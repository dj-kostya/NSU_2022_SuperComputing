//
// Created by konstantin on 22.05.22.
//

#ifndef TASK1_THREADSAFEQUEUE_HPP
#define TASK1_THREADSAFEQUEUE_HPP
#include <queue>
#include <mutex>
#include <condition_variable>
#pragma once
template<typename T>
class ThreadSafeQueue {
private:
    std::queue<std::unique_ptr<T>> queue;
    std::mutex lock;
    std::condition_variable cond;
    bool stop = false;
    size_t addedJobs = 0;
    size_t completedJobs = 0;

public:
    void Push(std::unique_ptr<T> job);

    std::unique_ptr<T> Pop();

    void Stop();

    void CompleteJob();

};


#endif //TASK1_THREADSAFEQUEUE_HPP
