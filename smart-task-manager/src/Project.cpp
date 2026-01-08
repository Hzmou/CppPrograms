/* Implementation of the Project.hpp class */

/* This class represents a project, which can contain multiple tasks. */

#include "Project.hpp"
#include <utility>
#include <string>
#include <vector>

namespace stm
{

    /* constructor for the Project class */

    Project::Project(std::string name)
        : m_name(std::move(name)) {}

    /* returns the name of the project */
    const std::string &Project::name() const noexcept
    {

        return m_name;
    }

    // returns the description of the project.
    const std::string &Project::description() const noexcept
    {

        return m_description;
    }

    // sets the description of the project.
    void Project::set_description(std::string d)
    {
        m_description = std::move(d);
    }

    // sets the color of the project.
    void Project::set_color(std::string hex)
    {

        m_color = std::move(hex);
    }

    // returns the color of the project.

    const std::string &Project::color() const noexcept
    {

        return m_color;
    }

} // namespace stm. 
