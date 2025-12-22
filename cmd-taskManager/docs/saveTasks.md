# saveTasks — explanation and implementation

## Purpose

- **Description:** Writes the current tasks to a text file (`filename`) in a simple CSV-like format so they can be reloaded later.

## Behavior

- **Early checks:**
  - If the task list is empty, the function prints a message and returns.
  - Opens an `std::ofstream` with `std::ios::trunc` to overwrite the file; if opening fails it prints an error and returns.

- **Line format written for each Task:**
  - `id,completed,"description"`
    - `id`: integer task ID
    - `completed`: `1` if completed, `0` otherwise
    - `description`: quoted string (surrounded by double quotes)

- **Escaping description:**
  - Double quotes inside the description are escaped by doubling them (CSV-style).
  - Newline characters are replaced with the two-character sequence `\n` so each task stays on a single line.

- **Writing and final checks:**
  - Each task is written as a single line:
    `id,completed,"escapedDescription"` followed by `\n`.
  - After closing the stream the code checks the stream state: on failure it prints an error, otherwise prints a success message.

## Implementation (C++)

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Assumes Task.h defines: int getId() const; std::string getDescription() const; bool isCompleted() const;

void saveTasks(const std::vector<Task>& tasks, const std::string& filename) {
    using std::cout;
    using std::endl;

    if (tasks.empty()) {
        cout << "No tasks to save." << endl;
        return;
    }

    std::ofstream ofs(filename, std::ios::trunc);
    if (!ofs) {
        cout << "Failed to open '" << filename << "' for writing." << endl;
        return;
    }

    for (const auto &t : tasks) {
        std::string desc = t.getDescription();
        std::string esc;
        esc.reserve(desc.size());

        for (char c : desc) {
            if (c == '"') {
                esc += "\"\""; // double the quote for CSV-style escaping
            } else if (c == '\n') {
                esc += "\\n"; // represent newline as two chars: backslash + n
            } else {
                esc.push_back(c);
            }
        }

        ofs << t.getId() << ',' << (t.isCompleted() ? 1 : 0) << ",\"" << esc << "\"\n";
    }

    ofs.close();
    if (!ofs) {
        cout << "Error occurred while writing to '" << filename << "'." << endl;
    } else {
        cout << "Tasks saved to '" << filename << "'." << endl;
    }
}
```

## Notes / improvements

- Consider writing to a temporary file and renaming it into place for atomic saves.
- If descriptions can include more complex characters, consider using a proper CSV library or a more robust serialization format (JSON, protobuf).
- Optionally enable exception-based I/O error handling (`ofs.exceptions(...)`) if you prefer exceptions over manual stream-state checks.
