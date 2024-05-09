#include "game.h"

int main() {
    Game game(30, 5);
    game.Run();
    std::cout << "Game over!" << std::endl;
    std::getchar();
    return 0;
}
