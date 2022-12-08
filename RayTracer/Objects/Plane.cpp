#include "Plane.h"

bool Plane::Hit(const Ray& ray, float min, float max, RaycastHit& hit)
{
    // if dot product (direction and plane normal) is 0 direction is parallel  
    float denominator = dot(ray.m_direction, m_normal);
    if (abs(denominator) < std::numeric_limits<float>::epsilon())
    {
        return false; // direction and plane parallel, no intersection 
    }

    float t = glm::dot(m_center - ray.m_origin, m_normal) / denominator;
    if (t < 0)
    {
        return false; // plane behind ray's origin 
    }

    // check if t (distance is within range 
    if (t > min && t < max)
    {
        //set the hit distance, point, normal and material
        hit.distance = t;
        hit.point = ray.GetPoint(t);
        hit.normal = glm::normalize(hit.point - m_center);
        hit.material = m_material.get();
        return true;
    }

    return false;
}
