#pragma once
#include <vector>
#include <memory>
#include "../Math/Color.h"

class Object;
struct Ray;
struct RaycastHit;

class Scene
{
public:
    Scene() = default;
    Scene(const color3& topColor, const color3& bottomColor):
        m_topColor{topColor},
        m_bottomColor{bottomColor}
    {}

    color3 Trace(const Ray& ray, float min, float max, RaycastHit& hit, int depth);

    void AddObject(std::unique_ptr<Object> object);

private:
    color3 m_topColor = { 0.5f, 0.7f, 1.0f };
    color3 m_bottomColor = { 1, 1, 1 };
    std::vector <std::unique_ptr<Object>> m_objects;
};