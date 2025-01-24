#pragma once
#include <iostream>

template<typename T>
class UniqPtr
{
private:
    T* ptr_{}; 

public:
    explicit UniqPtr(T* raw_ptr): ptr_{raw_ptr}{
        
    }

    ~UniqPtr(){
        // needs to delete the free store control block
        delete ptr_;
    }

    // deleting the copy constructor and copy assignment operator
    UniqPtr(const UniqPtr& other) = delete;
    UniqPtr& operator=(const UniqPtr& other) = delete;

    // move constructor
    UniqPtr(UniqPtr&& other) noexcept: ptr_{other.ptr_}{
        other.ptr_ = nullptr;
    }

    // move assignment operator
    UniqPtr& operator=(UniqPtr&& other) noexcept{
        if(this == &other){
            return *this;
        }
        delete ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;

        return *this;
    }

    T& operator*() const{
        return *ptr_;
    }
    
    T* operator->() const{
        return ptr_;
    }

    T* get() const{
        return ptr_;
    }
};
