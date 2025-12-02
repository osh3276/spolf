#include "game.h"
#include <vector>
#include "raylib.h"

Game::Game(int currentLevel)
    : currentLevel(currentLevel)
    , isAiming(false)
    , isSimulating(false)
{
    // Initialize particle starting position
    particle.position = {100, 100};
    particle.velocity = {0, 0};
    
    // Initialize goal
    goal.position = {700, 500};
    goal.radius = 30.0f;
    
    // Add some test bodies
    bodies.push_back({BodyType::PLANET, {400, 300}, 5000.0f, 50.0f});
    bodies.push_back({BodyType::STAR, {600, 200}, 3000.0f, 30.0f});
}

Game::~Game()
{
    // Cleanup if necessary
}

void Game::Update(float deltaTime)
{
    // Handle input, physics, collisions
}

void Game::Draw()
{
    // Draw bodies
    for (const auto& body : bodies) {
        DrawCircleV(body.position, body.radius, BLUE);
    }
    
    // Draw goal
    DrawCircleV(goal.position, goal.radius, GREEN);
    
    // Draw particle
    DrawCircleV(particle.position, 5.0f, RED);
}