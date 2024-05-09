#include "lane.h"
#include <cstdlib>

Lane::Lane(int width) {
    for (int i = 0; i < width; i++)
        cars.push_front(true);
    right = rand() % 2;
}

void Lane::Move() {
    if (right) {
        if (rand() % 10 == 1)
            cars.push_front(true);
        else
            cars.push_front(false);
        cars.pop_back();
    }
    else {
        if (rand() % 10 == 1)
            cars.push_back(true);
        else
            cars.push_back(false);
        cars.pop_front();
    }
}

bool Lane::CheckPos(int pos) {
    return cars[pos];
}

void Lane::ChangeDirection() {
    right = !right;
}
