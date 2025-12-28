/* Compelete implementation of the User.hpp class. */

#include "User.hpp"
#include <utility>

namespace stm
{

    User::User(std::string username, std::string display_name)
        : m_username(move(username)), m_display_name(move(display_name))

    {
    }

    const std::string &User::username() const noexcept
    {

        return m_username;
    }

    const std::string &User::display_name() const noexcept
    {
        return m_display_name;
    }

    void User::set_display_name(std::string dn)
    {

        m_display_name = move(dn);
    }

    void User::set_default_project(std::string project)
    {
        m_default_project = move(project);
    }

    const std::string &User::default_project() const noexcept
    {
        return m_default_project;
    }

    bool User::add_skill(const std::string &tag)
    {
        auto result = m_skills.insert(tag);
        return result.second;
    }

    bool User::remove_skill(const std::string &tag)
    {

        return m_skills.erase(tag) > 0;
    }

    const std::set<std::string> &User::skills() const noexcept
    {
        return m_skills;
    }
}