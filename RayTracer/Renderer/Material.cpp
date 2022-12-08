#include "Material.h"

bool Lambertian::Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const
{
    glm::vec3 target = hit.point + hit.normal + randomInUnitSphere();
    glm::vec3 direction = glm::normalize(target - hit.point);

    scattered = { hit.point, direction };
    attenuation = m_albedo;

    return true;
}

bool Metal::Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const
{
    glm::vec3 reflected = reflect(glm::normalize(ray.m_direction),hit.normal);
    scattered = { hit.point, reflected + randomInUnitSphere() * m_fuzz};
    attenuation = m_albedo;

    return dot(hit.normal,scattered.m_direction) > 0;
}

