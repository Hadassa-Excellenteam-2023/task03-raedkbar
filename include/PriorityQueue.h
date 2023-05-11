#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <list>
#include <exception>

template<typename T>
struct MyComparator {
    T operator()(const T& a, const T& b) const {
        return a - b;
    }
};

template<typename T>
class PriorityQueue {
public:
    PriorityQueue() {}

    void push(const T& t) {
        if (lst.empty()) {
            lst.push_back(t);
            return;
        }

        const MyComparator<T> comparator;
        auto it = lst.begin();
        for (; it != lst.end(); ++it) {
            if (comparator(*it, t) < 0) {
                lst.insert(it, t);
                return;
            }
        }

        lst.insert(it, t);
    }

    T poll() {
        if (lst.empty()) {
            throw std::runtime_error("PriorityQueue is empty.");
        }

        T element = lst.back();
        lst.pop_back();
        return element;
    }

private:
    std::list<T> lst;
};

#endif // PRIORITYQUEUE_H
