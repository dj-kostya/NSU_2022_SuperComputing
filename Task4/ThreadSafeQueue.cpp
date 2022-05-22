//
// Created by konstantin on 22.05.22.
//

#include "ThreadSafeQueue.hpp"

template<typename T>
void ThreadSafeQueue<T>::Push(std::unique_ptr<T> job) {
    std::unique_lock<std::mutex> guard(lock);
    queue.emplace(std::move(job));
    addedJobs++;
    stop = false;
    cond.notify_one();
}

template<typename T>
std::unique_ptr<T> ThreadSafeQueue<T>::Pop() {
    std::unique_lock<std::mutex> guard(lock);
    cond.wait(guard, [&]() { return stop || !queue.empty(); });
    if (stop) {
        return nullptr;
    }

    auto job = std::move(queue.front());
    queue.pop();
    return std::move(job);
}

template<typename T>
void ThreadSafeQueue<T>::Stop() {
    std::unique_lock<std::mutex> guard(lock);
    stop = true;
    cond.notify_all();
}

template<typename T>
void ThreadSafeQueue<T>::CompleteJob() {
    std::unique_lock<std::mutex> guard(lock);
    completedJobs++;
    if (addedJobs == completedJobs) {
        stop = true;
        cond.notify_all();
    }
}

