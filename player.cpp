#include "player.h"

Player::Player(int width) {
    x = width / 2;
    y = 0;
}

void Player::MoveLeft() {
    x--;
}

void Player::MoveRight() {
    x++;
}

void Player::MoveUp() {
    y--;
}

void Player::MoveDown() {
    y++;
}
