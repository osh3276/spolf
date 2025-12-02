#pragma once

#include "entities.h"
#include <vector>

class Game
{
private:
    Particle particle;
    std::vector<Body> bodies;
    Goal goal;
    int currentLevel;
    bool isAiming;
    bool isSimulating;

public:
    Game(int currentLevel = 0);
    ~Game();
    void Update(float deltaTime);
    void Draw();
};

