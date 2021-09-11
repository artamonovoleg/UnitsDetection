#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include <chrono>
#include "Math.hpp"
#include "Unit.hpp"
#include "Sector.hpp"
#include "Timer.hpp"

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

void AddPresetToMap(std::vector<Unit>& units, const Vector2& offset, uint32_t& currentID)
{
    units.emplace_back(Vector2(1 + offset.x, 1 + offset.y), Vector2(0.5, 0.5), currentID++);
    units.emplace_back(Vector2(1 + offset.x, 2 + offset.y), Vector2(1, 0), currentID++);
    units.emplace_back(Vector2(2 + offset.x, 2 + offset.y), Vector2(0.707, 0.707), currentID++);
    units.emplace_back(Vector2(2 + offset.x, 1 + offset.y), Vector2(-1, 0), currentID++);
}

int main()
{
    float degrees = 135.5;
    float distance = 2;
    Timer executionTimer;

    std::vector<Unit> units;
    units.reserve(10000);

    // Somehow random units
    uint32_t unitsCount = 10000;
    uint32_t id = 0;
    Vector2 offset(0, 0);
    for (int i = 0; i < unitsCount / 4; i++)
    {
        AddPresetToMap(units, offset, id);
        offset.x += 5.0f;
        offset.y += 5.0f;
    }

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

    std::cout << "Elapsed time: " << executionTimer.Elapsed() << std::endl;

    return 0;
}
