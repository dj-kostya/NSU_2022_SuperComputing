//
// Created by konstantin on 22.05.22.
//

#ifndef TASK1_THREADPOOL_HPP
#define TASK1_THREADPOOL_HPP

#include <thread>
#include "ThreadSafeQueue.cpp"
#include "RetraceJob.cpp"
#pragma once
class ThreadPool {
private:
    size_t PoolSize = 1;
    ThreadSafeQueue<RetraceJob> queue;
    std::vector<std::thread *> workers;
public:
    ThreadPool() = default;

    explicit ThreadPool(size_t poolSize);

    void ThreadFunc();

    void AddJob(std::unique_ptr<RetraceJob> job);

    void Join();

};


#endif //TASK1_THREADPOOL_HPP
