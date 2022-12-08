#pragma once
#include "Canvas.h"
#include "../Math/Ray.h"
#include <SDL.h>

class Object;
class Scene;
class Camera;

class Renderer
{ 
public:
	Renderer() = default;
	bool Initialize();
	void Shutdown();
	bool CreateWindow(int width,int height);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	void Render(Canvas& canvas, Scene& scene, Camera& camera);

	friend class Canvas;
private:
	color3 GetBackgroundFromRay(const Ray& ray);

	SDL_Window * m_window{nullptr};
	SDL_Renderer * m_renderer{nullptr}; 
};