#include "game.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

Game::Game(int w, int h) {
    numberOfLanes = h;
    width = w;
    quit = false;
    score = 0;
    level = 1;

    for (int i = 0; i < numberOfLanes; i++)
        map.push_back(new Lane(width));
    player = new Player(width);
}

Game::~Game() {
    delete player;
    for (int i = 0; i < map.size(); i++) {
        Lane* current = map.back();
        map.pop_back();
        delete current;
    }
}

void Game::Draw() {
    system("cls");
    for (int i = 0; i < numberOfLanes; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 && (j == 0 || j == width - 1)) std::cout << "_";
            else if (i == numberOfLanes - 1 && (j == 0 || j == width - 1)) std::cout << "___";
            else if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1) std::cout << "#";
            else if (player->x == j && player->y == i) std::cout << "V";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Level: " << level << " Score: " << score << std::endl;
}

void Game::Input() {
    if (_kbhit()) {
        char current = _getch();
        switch (current) {
        case 'a':
            player->MoveLeft();
            break;
        case 'd':
            player->MoveRight();
            break;
        case 'w':
            player->MoveUp();
            break;
        case 's':
            player->MoveDown();
            break;
        case 'q':
            quit = true;
            break;
        }
    }
}

void Game::Logic() {
    for (int i = 1; i < numberOfLanes - 1; i++) {
        if (rand() % 10 == 1)
            map[i]->Move();
        if (map[i]->CheckPos(player->x) && player->y == i)
            quit = true; 
    }
    if (player->y == numberOfLanes - 1) {
        score += level * 10; 
        player->y = 0;
        std::cout << "\x07";
        map[rand() % numberOfLanes]->ChangeDirection();
        if (score % 50 == 0) { 
            level++;

        }
    }
}

void Game::Run() {
    while (!quit) {
        Input();
        Draw();
        Logic();
    }
}
