
#pragma once
#include <string>
#include <vector>
#include "Task.hpp"
#include "Project.hpp"
#include "User.hpp"

namespace stm {

class Persistence {
public:
    // Serialize all entities to a simple text/JSON-like format
    bool save(const std::string& path,
              const std::vector<Project>& projects,
              const std::vector<User>& users,
              const std::vector<Task>& tasks) const;

    // Load entities; return false on parse error
    bool load(const std::string& path,
              std::vector<Project>& projects,
              std::vector<User>& users,
              std::vector<Task>& tasks) const;
};

} // namespace stm
