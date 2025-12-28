
#pragma once
#include <queue>
#include <vector>
#include <functional>
#include "Task.hpp"

namespace stm {

// Urgency score = function of due date proximity, status, estimate, etc.
using UrgencyFn = std::function<double(const Task&)>;

class Scheduler {
public:
    explicit Scheduler(UrgencyFn fn);

    void load(const std::vector<Task>& tasks);
    void clear();

    bool empty() const noexcept;
    size_t size() const noexcept;

    // Returns the most urgent task without removing it
    const Task& peek() const; // throws if empty

    // Pops the most urgent task
    Task pop(); // throws if empty

private:
    struct Node {
        double score;
        Task task;
        bool operator<(const Node& other) const { return score < other.score; } // max-heap
    };

    std::priority_queue<Node> m_pq;
    UrgencyFn m_urgency;
};

} // namespace stm
