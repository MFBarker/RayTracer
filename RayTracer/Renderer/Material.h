#pragma once
#include "../Math/Ray.h"
#include "../Math/Color.h"

class Material
{
public:
	virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const = 0;
};

class Lambertian : public Material
{
public:
    Lambertian(const color3& albedo) : m_albedo{ albedo } {}
    virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

protected:
    color3 m_albedo;
};

class Metal : public Material
{
public:
    Metal(const color3& albedo, float fuzz = 0) : m_albedo{ albedo }, m_fuzz{ fuzz } {}
    virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

protected:
    color3 m_albedo;
    float m_fuzz;
};