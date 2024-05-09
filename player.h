#pragma once

class Player {
public:
    int x, y;
    Player(int width);
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
};
