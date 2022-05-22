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


/*
 *
 *  void Push(std::unique_ptr<T> job) {
        std::unique_lock<std::mutex> guard(lock);
        if (set.find(job->getUniq()) == set.end()) {
            set.insert(job->getUniq());
            queue.emplace(std::move(job));
            addedJobs++;
            cond.notify_one();
        }
    }

    std::unique_ptr<T> Pop() {
        std::unique_lock<std::mutex> guard(lock);
        cond.wait(guard, [&]() { return stop || !queue.empty(); });
        if (stop) {
            return nullptr;
        }

        auto job = std::move(queue.front());
        queue.pop();
        return std::move(job);
    }

    void Stop() {
        std::unique_lock<std::mutex> guard(lock);
        stop = true;
        cond.notify_all();
    }

    void CompleteJob() {
        std::unique_lock<std::mutex> guard(lock);
        completedJobs++;
        if (addedJobs == completedJobs) {
            stop = true;
            cond.notify_all();
        }
    }

    size_t getUniqSize() {
        return set.size();
    }

private:
    std::queue<std::unique_ptr<T>> queue;
    std::unordered_set<Uniq> set;
    std::mutex lock;
    std::condition_variable cond;
    bool stop = false;

    size_t addedJobs = 0;
    size_t completedJobs = 0;
};

 */

#endif //TASK1_THREADSAFEQUEUE_HPP
