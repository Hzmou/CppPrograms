/* complete implementation of the TagManager.hpp class.*/

/* This class Handles saving and loading the application state aka tags.
 (projects, users, tasks)
 * supports adding/removing tags, and renaming tags to keep the taxonomy clean.
 */

#include "TagManger.hpp";
#include <stdexcept>
#include <algorithm>

namespace stm
{

    // track tag usage counts and renames.

    // Add a new tag with initial count 0
    /* returns false if tag already exists */
    bool TagManager::add(const std::string &tag)
    {

        if (tag.empty())
        {
            throw std::invalid_argument("Tag cannot be empty");
        }

        if (m_counts.find(tag) != m_counts.end())
        {
            return false; // Tag already exists
        }
        m_counts[tag] = 0; // Initialize count to 0
        return true;
    }

    // Remove a tag from the manager
    /* returns false if tag does not exist */
    bool remove(const std::string &tag)
    {

        if (tag.empty())
        {
            throw std::invalid_argument("Tag cannot be empty");
        }

        auto it = m_counts.find(tag);
        if (it == m_counts.end())
        {
            return false; // Tag does not exist
        }

        m_counts.erase(it);
        return true;
    }

    // rename an existing tag to a new tag.

    bool TagManager::rename(const std::string &old_tag, const std::string &new_tag)
    {

        if (old_tag.empty() || new_tag.empty())
        {
            throw std::invalid_argument("Tags cannot be empty");
        }

        auto it_old = m_counts.find(old_tag);
        if (it_old == m_counts.end())
        {
            return false; // old tag does not exist.
        }

        auto it_new = m_counts.find(new_tag);
        if (it_new != m_counts.end())
        {
            return false; // new tag already exists.
        }

        // Perform rename
        m_counts.emplace(new_tag, it_old->second); // Copy count to new tag
        m_counts.erase(it_old);                    // Remove old tag
        return true;
    }

    // get the count of a specific tag.

    size_t TagManager::count(const std::string &tag) const
    {

        auto it = m_couts.find(tag);

        if (it == m_counts.end())
        {
            throw std::invalid_argument("Tag does not exist.");
        }

        return it->second;
    }

    /* get all tags. sorted outpu and return all tags.   */
    std::set<std::string> TagManager::all_tags() const
    {

        std::set<std::string> tags;

        for (const auto &pair : m_counts)
        {
            tags.insert(pair.first);
        }

        return tags;
    }

    void TagManager::increment(const std::string &tag)
    {
        auto it = m_counts.find(tag);
        if (it == m_counts.end())
        {
            throw std::invalid_argiment("Tag does not exist.");
        }

        ++(it->second); // Increment count.
    }

    void decrement(const std::string &tag)
    {
        auto it = m_counts.find(tag);
        if (it == m_counts.end())
        {

            throw std::invalid_argument("Tag does not exist. ");
        }

        --(it->second); // descrement count.
    }

} // namespace stm.
