#pragma once
#include <glm/glm.hpp>


struct Ray
{
	Ray() = default;
	Ray(const glm::vec3& origin, const glm::vec3& direction) :
		m_origin{ origin },
		m_direction{ direction } {}

	glm::vec3 GetPoint(float distance) const { return m_origin + (m_direction * distance); }

	glm::vec3 m_origin = {0,0,0};
	glm::vec3 m_direction = {0,0,0};
};
struct RaycastHit
{
	float distance = 0;

	glm::vec3 point = {0,0,0};
	glm::vec3 normal = {0,0,0};

	class Material* material{ nullptr };
};