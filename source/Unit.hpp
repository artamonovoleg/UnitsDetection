#pragma once

#include "Math.hpp"

struct Unit
{
    Vector2 position;
    Vector2 view;
    uint32_t id = 0;
    uint32_t detectCount = 0;
    Unit() = default;
    Unit(Vector2 p, Vector2 v, uint32_t id) : position(p), view(v), id(id) {}
};