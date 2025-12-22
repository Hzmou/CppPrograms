# loadTasks — implementation notes

## Purpose

- Reads tasks from a text file previously written by `saveTasks` and reconstructs the in-memory `std::vector<Task>` and the next available task id (`nextId`).

## Expected file format

Each line corresponds to one task and uses a CSV-like format:

```
id,completed,"description"
```

- `id`: integer task id
- `completed`: `1` (completed) or `0` (pending)
- `description`: double-quoted string; internal double quotes are represented as doubled quotes (`""`) and newlines are encoded as the two characters `\n` so each task occupies exactly one file line.

## High-level parsing strategy

1. Open the file using `std::ifstream`. If opening fails, print an error and return.
2. Clear the `tasks` vector and reset `nextId` to a safe default (e.g., `1`) before loading.
3. Read the file line-by-line with `std::getline`.
4. For each non-empty line:
   - Find the first comma to extract the `id` field.
   - Find the next comma to extract the `completed` field.
   - The remaining portion is the `description` field. If it begins with a double quote (`"`), parse until the matching closing quote while handling: doubled quotes (`""`) → one `"`, and sequences `\\n` → actual newline `\n`.
   - Convert the numeric fields with `std::stoi`, create a `Task` with the parsed `id` and `description`, set completion state if needed, and push it into `tasks`.
   - Track the largest `id` seen so you can set `nextId` = maxId + 1 at the end.
5. After processing all lines, report how many tasks were loaded.

## Robustness and error handling

- Skip malformed lines and print a brief warning rather than aborting the whole load.
- Wrap numeric conversions in try/catch to handle bad integer fields.
- Preserve the original `id` values from the file; compute `nextId` from the maximum id encountered.

## Implementation (C++)

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Assumes Task.h declares: Task(int id, const std::string& desc);
//                 and: int getId() const; std::string getDescription() const; bool isCompleted() const;
//                 and methods: void markComplete();

void loadTasks(std::vector<Task> &tasks, int &nextId, const std::string &filename)
{
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cout << "Failed to open '" << filename << "' for reading." << std::endl;
        return;
    }

    tasks.clear();
    nextId = 1;
    int maxId = 0;

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;

        size_t pos = 0;
        // parse id
        size_t comma = line.find(',', pos);
        if (comma == std::string::npos) { std::cout << "Skipping malformed line: " << line << '\n'; continue; }
        std::string idStr = line.substr(pos, comma - pos);
        pos = comma + 1;

        // parse completed
        comma = line.find(',', pos);
        if (comma == std::string::npos) { std::cout << "Skipping malformed line: " << line << '\n'; continue; }
        std::string compStr = line.substr(pos, comma - pos);
        pos = comma + 1;

        // parse quoted description (CSV-like), handle doubled quotes and \n sequences
        std::string desc;
        if (pos < line.size() && line[pos] == '"') {
            size_t i = pos + 1;
            while (i < line.size()) {
                char c = line[i];
                if (c == '"') {
                    // doubled quote -> literal quote
                    if (i + 1 < line.size() && line[i + 1] == '"') {
                        desc.push_back('"');
                        i += 2;
                        continue;
                    } else {
                        // closing quote
                        ++i;
                        break;
                    }
                }
                if (c == '\\' && i + 1 < line.size() && line[i + 1] == 'n') {
                    desc.push_back('\n');
                    i += 2;
                    continue;
                }
                desc.push_back(c);
                ++i;
            }
        } else {
            // no quotes -- take rest
            desc = line.substr(pos);
        }

        try {
            int id = std::stoi(idStr);
            int completed = std::stoi(compStr);

            Task t(id, desc);
            if (completed != 0) t.markComplete();
            tasks.push_back(t);

            if (id > maxId) maxId = id;
        } catch (const std::exception &) {
            std::cout << "Skipping line with bad numeric fields: " << line << '\n';
            continue;
        }
    }

    if (maxId >= nextId) nextId = maxId + 1;

    std::cout << "Loaded " << tasks.size() << " tasks from '" << filename << "'." << std::endl;
}
```

## Notes / possible improvements

- Use a temporary file + rename for `saveTasks` to avoid truncating the existing file on failures.
- Consider switching to JSON, which many libraries handle robustly for quoting/escaping.
- Add unit tests that exercise descriptions containing commas, quotes, and newlines.
- If file format changes, include a version header in the file to support backward compatibility.
