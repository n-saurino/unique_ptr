#pragma once

template<typename T>
class ControlBlock
{
private:
    T* ptr_{};
    bool ref_count_{};

public:
    ControlBlock(T* ptr): ptr_{ptr}, ref_count{1}{

    }

    ~ControlBlock(){

    }
};
