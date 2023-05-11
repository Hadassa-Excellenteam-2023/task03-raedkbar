#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <list>
#include <exception>

/**
 * Functor struct for comparing elements of the PriorityQueue.
 *
 * This struct provides a comparison function operator() to compare elements of the
 * PriorityQueue. It subtracts the second element from the first element and returns
 * the result.
 *
 * @tparam T The type of elements being compared.
 */
template<typename T>
struct MyComparator {
    T operator()(const T& a, const T& b) const {
        return a - b;
    }
};

/**
 * A priority queue implementation based on a linked list.
 *
 * This class represents a priority queue, where elements are stored in a linked list.
 * The elements are ordered based on their priority, which is determined by a user-defined
 * comparison function.
 *
 * @tparam T The type of elements stored in the priority queue.
 */
template<typename T>
class PriorityQueue {
public:
    /**
     * Default constructor for PriorityQueue.
     *
     * This constructor initializes an empty priority queue.
     */
    PriorityQueue() {}

    /**
     * Pushes an element into the priority queue.
     *
     * This function adds a new element to the priority queue while maintaining the order
     * of elements based on their priority. The element is inserted at the appropriate
     * position in the linked list.
     *
     * @param t The element to be inserted into the priority queue.
     */
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

    /**
     * Removes and returns the highest priority element from the queue.
     *
     * This function removes and returns the element with the highest priority from the
     * priority queue. The element is removed from the end of the linked list.
     *
     * @return The highest priority element in the priority queue.
     *
     * @throw std::runtime_error if the priority queue is empty.
     */
    T poll() {
        if (lst.empty()) {
            throw std::runtime_error("PriorityQueue is empty.");
        }

        T element = lst.back();
        lst.pop_back();
        return element;
    }

private:
    std::list<T> lst; // The linked list storing the elements of the priority queue
};

#endif // PRIORITYQUEUE_H
