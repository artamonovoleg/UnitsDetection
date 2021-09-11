#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Unit.hpp"
#include "Sector.hpp"

Vector2 RotateVector2(Vector2 v, float angle)
{
    return
        {
            v.x * cos(angle) - v.y * sin(angle),
            v.x * sin(angle) + v.y * cos(angle)
        };
}

bool AreClockwise(Vector2 v1, Vector2 v2)
{
    return -v1.x * v2.y + v1.y * v2.x > 0;
}

bool IsWithinRadius(Vector2 v, float radiusSquared)
{
    return v.x * v.x + v.y * v.y <= radiusSquared;
}

bool IsInsideSector(const Unit& source, const Unit& target, const Sector& sector, float distance) {
    Vector2 relPoint
        (
            target.position.x - source.position.x,
            target.position.y - source.position.y
        );

    return !AreClockwise(sector.start, relPoint) &&
           AreClockwise(sector.end, relPoint) &&
           IsWithinRadius(relPoint, distance);
}

Sector ConstructUnitSector(const Unit& unit, float degrees)
{
    float sectorInRadians = glm::radians(degrees);
    Sector res{};
    res.start = RotateVector2(unit.view, -(sectorInRadians / 2.0f));
    res.end = RotateVector2(unit.view, (sectorInRadians / 2.0f));
    return res;
}

bool CheckBetweenUnitPair(Unit& source, const Unit& target, float degrees, float distance)
{
    if (IsInsideSector(source, target, ConstructUnitSector(source, degrees), distance))
        source.detectCount++;
    else
        return glm::length(target.position - source.position) <= distance;
    return true;
}

int main()
{
    float degrees = 135.5;
    float distance = 2;

    std::vector<Unit> units;
    units.reserve(10000);
    // Somehow random units
    uint32_t id = 0;
    units.emplace_back(Vector2(1, 1), Vector2(0, 1), id++);
    units.emplace_back(Vector2(1, 2), Vector2(1, 0), id++);
    units.emplace_back(Vector2(-5, -1), Vector2(0.707, 0.707), id++);
    // Sort vector
    std::sort(units.begin(), units.end(), [](const auto& u1, const auto& u2)
    {
        return u1.position.x < u2.position.x
            && u1.position.y < u2.position.y;
    });

    for (int i = 0; i < units.size(); i++)
    {
        auto& unit = units[i];
        bool needCheckLefts = true;
        bool needCheckRights = true;

        for (int j = 0; needCheckLefts || needCheckRights; j++)
        {
            needCheckLefts = (i + j) < units.size();
            needCheckRights = (i - j) >= 0;

            if (needCheckLefts)
                needCheckLefts = CheckBetweenUnitPair(units[i], units[i + j], degrees, distance);

            if (needCheckRights)
                needCheckRights = CheckBetweenUnitPair(units[i], units[i - j], degrees, distance);
        }
    }

    // Sort again for good output
    std::sort(units.begin(), units.end(), [](const auto& u1, const auto& u2)
    {
        return u1.id < u2.id;
    });

    for (const auto& unit : units)
        std::cout << "Unit " << unit.id << " see " << unit.detectCount << std::endl;

    return 0;
}
