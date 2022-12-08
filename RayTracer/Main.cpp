#include"Renderer/Renderer.h"
#include"Renderer/Camera.h"
#include "Objects/Sphere.h"
#include "Objects/Scene.h"
#include<iostream>

int main(int,char**)
{
	const int width = 800;
	const int height = 600;
	const int samples = 100;

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(width, height);
	bool quit=false;

	Canvas canvas(width, height, renderer);
	Camera camera({ 0, 1, 2 }, { 0, 0, 0 }, { 0, 1, 0 }, 70.0f, width / (float)height);
	Scene scene;
	//add objects
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ 0, 1, 0 })));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 1.25f, 0, -1 }, 0.5f, std::make_unique<Metal>(color3{ 1, 1, 1 }, 0.1f)));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3{ 0.2f, 0.2f, 0.2f })));

	while(!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch(event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		// render scene
		canvas.Clear({0,0,0,1});
		renderer.Render(canvas, scene, camera);
		//renderer.Render(canvas, scene, camera, samples);

		//static
		/*for (int i = 0; i < 100000; i++) 
		{
			canvas.DrawPoint({ random(0,600),random(0,400) }, { 1,1,1,1 });
		}*/
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}
	renderer.Shutdown();
	return 0;
}