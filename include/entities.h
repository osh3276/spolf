#pragma once
#include "raylib.h"

enum class BodyType
{
    PLANET,
    STAR,
    NEUTRON_STAR,
    BLACK_HOLE
};

struct Particle
{ 
    Vector2 position;
    Vector2 velocity;
    Color color;
};

struct Body
{
    BodyType type;
    Vector2 position;
    float mass;
    float radius;
};

struct Goal
{
    Vector2 position;
    float radius;
};