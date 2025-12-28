
#pragma once
#include <string>
#include <set>

namespace stm {

class User {
public:
    User() = default;
    User(std::string username, std::string display_name);

    const std::string& username() const noexcept;
    const std::string& display_name() const noexcept;

    void set_display_name(std::string dn);

    // user preferences (e.g., default project)
    void set_default_project(std::string project);
    const std::string& default_project() const noexcept;

    // skills or tags interest
    bool add_skill(const std::string& tag);
    bool remove_skill(const std::string& tag);
    const std::set<std::string>& skills() const noexcept;

private:
    std::string m_username;
    std::string m_display_name;
    std::string m_default_project;
    std::set<std::string> m_skills;
};

} // namespace stm
