#pragma once
#include <deque>

class Lane {
private:
    std::deque<bool> cars;
    bool right;
public:
    Lane(int width);
    void Move();
    bool CheckPos(int pos);
    void ChangeDirection();
};
