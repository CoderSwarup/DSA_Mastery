#include <queue>
#include <iostream>

int main() {
    // Creating a priority queue of integers
    std::priority_queue<int> pq;

    // Pushing elements into the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    // Accessing the top element (highest priority)
    std::cout << "Top element: " << pq.top() << std::endl;

    // Pop the top element
    pq.pop();

    // Accessing the new top element
    std::cout << "Top element after pop: " << pq.top() << std::endl;

    // Checking if the priority queue is empty
    if (pq.empty()) {
        std::cout << "Priority queue is empty." << std::endl;
    } else {
        std::cout << "Priority queue is not empty." << std::endl;
    }

    // Size of the priority queue
    std::cout << "Size of priority queue: " << pq.size() << std::endl;



        // Min Priority Queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;

    // Pushing elements into the min priority queue
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);

    // Accessing the top element (minimum priority)
    std::cout << "Min Priority Queue - Top element: " << minPQ.top() << std::endl;

    // Max Priority Queue
    std::priority_queue<int, std::vector<int>, std::less<int>> maxPQ;

    // Pushing elements into the max priority queue
    maxPQ.push(30);
    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(20);

    // Accessing the top element (maximum priority)
    std::cout << "Max Priority Queue - Top element: " << maxPQ.top() << std::endl;



    return 0;
}
