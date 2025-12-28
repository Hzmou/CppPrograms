
#pragma once
#include <string>
#include <vector>

namespace stm {

class Project {
public:
    Project() = default;
    explicit Project(std::string name);

    const std::string& name() const noexcept;
    const std::string& description() const noexcept;

    void set_description(std::string d);

    // Optional: metadata or color
    void set_color(std::string hex);
    const std::string& color() const noexcept;

private:
    std::string m_name;
    std::string m_description;
    std::string m_color; // #RRGGBB
};

} // namespace stm

