#ifndef TIMEDSHARED_PTR_H
#define TIMEDSHARED_PTR_H

#include <memory>
#include <chrono>

template<typename T>
class TimedSharedPtr {
public:
    using Clock = std::chrono::steady_clock;

    // Constructor: takes raw pointer and expiration in milliseconds
    explicit TimedSharedPtr(T* ptr, long long duration_ms = 0)
        : ptr_(std::shared_ptr<T>(ptr)), expiry_(Clock::now() + std::chrono::milliseconds(duration_ms)), duration_ms_(duration_ms) {}

    // Copy constructor
    TimedSharedPtr(const TimedSharedPtr& other)
        : ptr_(other.ptr_), expiry_(other.expiry_), duration_ms_(other.duration_ms_) {}

    // Assignment operator
    TimedSharedPtr& operator=(const TimedSharedPtr& other) {
        if (this != &other) {
            ptr_ = other.ptr_;
            expiry_ = other.expiry_;
            duration_ms_ = other.duration_ms_;
        }
        return *this;
    }

    // get(): returns raw pointer if not expired, else nullptr
    T* get() const {
        if (Clock::now() >= expiry_) {
            return nullptr;
        }
        return ptr_.get();
    }

    // use_count(): number of shared_ptr owners
    long use_count() const {
        return ptr_.use_count();
    }

private:
    std::shared_ptr<T> ptr_;
    Clock::time_point expiry_;
    long long duration_ms_;
};

#endif // TIMEDSHARED_PTR_H
