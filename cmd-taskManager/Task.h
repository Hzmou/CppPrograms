#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    // Constructors
    Task(int _id, const std::string& desc);

    // Getters
    int getId() const;
    std::string getDescription() const;
    bool isCompleted() const;

    // Setters / Mutators
    void setDescription(const std::string& desc);
    void markComplete();
    void markIncomplete();

    // (Optional: Add methods for due date, priority, etc.)

private:
    int id;
    std::string description;
    bool completed;
    // (Optional: std::string dueDate; int priority;)
};

#endif // TASK_H