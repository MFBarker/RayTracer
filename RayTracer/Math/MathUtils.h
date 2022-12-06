#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include <stdlib.h>
#include <algorithm>

inline float random01()
{
	return rand() / (float)RAND_MAX;
}

inline float random(float min, float max)
{
	if (min > max) std::swap(min, max);
	return min + (max - min) * random01();
}

template <typename T>
inline T lerp(T a, T b, float t)
{
	return (a * (1.0f - t)) + (b * t);
}

inline glm::vec3 randomInUnitSphere()
{
    glm::vec3 point;

    do
    {
        point = glm::vec3{ random(-1, 1), random(-1, 1), random(-1, 1) };
    } while (glm::length2(point) >= 1);

    return point;
}