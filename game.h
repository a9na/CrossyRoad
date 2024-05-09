#pragma once
#include <vector>
#include "player.h"
#include "lane.h"

class Game {
private:
    bool quit;
    int numberOfLanes;
    int width;
    int score;
    int level;
    Player* player;
    std::vector<Lane*> map;
public:
    Game(int w = 20, int h = 10);
    ~Game();
    void Draw();
    void Input();
    void Logic();
    void Run();
};
