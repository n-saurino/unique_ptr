#pragma once
#include <iostream>
#include "ControlBlock.hpp"

template<typename T>
class UniqPtr
{
private:
    ControlBlock* pcb_{};

public:
    UniqPtr(T* raw_ptr): pcb{raw_ptr ? new ControlBlock<T>{raw_ptr} : 
                             nullptr}{
        
    }

    ~UniqPtr(){
        // needs to delete the free store control block
        delete pcb;
    }

    UniqPtr& operator*(){
        return *this;
    }
    
    UniqPtr* operator->(){
        return this;
    }
};
