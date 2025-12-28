
#pragma once
#include <string>
#include <unordered_map>
#include <set>

namespace stm {

class TagManager {
public:
    // track tag usage counts and renames
    bool add(const std::string& tag);
    bool remove(const std::string& tag);
    bool rename(const std::string& old_tag, const std::string& new_tag);

    size_t count(const std::string& tag) const;
    std::set<std::string> all() const; // sorted output

    void increment(const std::string& tag);
    void decrement(const std::string& tag);

private:
    std::unordered_map<std::string, size_t> m_counts;
};

} // namespace stm
