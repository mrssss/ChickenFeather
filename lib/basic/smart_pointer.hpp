namespace Basic {

template<typename T>
class unique_pointer {
public:
    explicit unique_pointer(T * ptr = nullptr) : ptr_(ptr) {}

    ~unique_pointer() {
        delete ptr_;
    }

    unique_pointer(const unique_pointer &) = delete;
    //unique_pointer & operator=(const unique_pointer &) = delete;

    unique_pointer(unique_pointer && other) {
        ptr_ = other.release();
    }

    template<typename U>
    unique_pointer(unique_pointer<U> && other) {
        ptr_ = other.release();
    }

    unique_pointer & operator=(unique_pointer rhs) {
        rhs.swap(*this);
        return *this;
    }

    T * get() const { return ptr_; }

    T & operator*() const { return *ptr_; }

    /// p->member expression
    /// 1. p is a pointer, then (*p).member
    /// 2. p is an object which implements operator->(), then (p.operator->())->member
    /// 3. p is an object which does not implement operator->(), then error at compile time. 
    T * operator->() const { return ptr_; }
    operator bool() const { return ptr_; }

    T * release() {
        T * ptr = ptr_;
        ptr_ = nullptr;
        return ptr; 
    }

    void swap(unique_pointer & rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T * ptr_;
};

// template<typename T>
// class shared_pointer {
// private:

// class shared_count {
// public:
//     shared_count(): count(1) {}

//     void add_count() { ++count; }
//     long reduce_count() { return --count; }
//     long get_count() const { return count; }    

// private:
//     long count;
// };

// public:
//     explicit shared_pointer(T * ptr_ = nullptr) : ptr(ptr_) {
//         if(ptr) { 
//             count = new shared_count()
//         }
//     }

// };

}