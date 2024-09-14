#include <../header_files/common.h>
#include <../header_files/thread_pool.h>

ThreadPool::ThreadPool(size_t thread_number) {
    for (size_t i = 0; i < thread_number; ++i) {
        threads.emplace_back([this] {
            while (true) {
                std::function<void()> task;
                //put this in a scope so the mutex doesn't lock up for the time of task execution
                {
                    std::unique_lock<std::mutex> lock(queue_mutex);

                    cv.wait(lock, [this] {
                        return !tasks.empty() || stop;
                    });

                    if (stop && tasks.empty()) {
                        return;
                    }
                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    std::unique_lock<std::mutex> lock(queue_mutex);
    tasks.emplace(std::move(task));
    cv.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    cv.notify_all();
    for (std::thread& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}