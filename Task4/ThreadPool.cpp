//
// Created by konstantin on 22.05.22.
//

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(size_t poolSize) : PoolSize(poolSize) {
    this->workers.reserve(poolSize);
}

void ThreadPool::ThreadFunc() {
    std::unique_ptr<RetraceJob> a = std::move(queue.Pop());
    while (a != nullptr) {
        a->Execute();
        queue.CompleteJob();
        a = std::move(queue.Pop());
    }
}

void ThreadPool::AddJob(std::unique_ptr<RetraceJob> job) {
    queue.Push(std::move(job));
}

void ThreadPool::Join() {
    for (size_t i = 0; i < this->PoolSize; i++) {
        workers.emplace_back(new std::thread([this]() {
            ThreadFunc();
        }));
    }
    for (auto w: workers) {
        w->join();
    }
    workers.clear();
}
