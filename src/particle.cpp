#include "raylib.h"

struct Particle {
    Vector2 position;
    Vector2 velocity;
    Color color;
};

struct Body {
    Vector2 position;
    float mass;
};

struct Goal {
    Vector2 position;
    float radius;
};
