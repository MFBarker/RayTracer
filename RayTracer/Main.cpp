#include"Renderer/Renderer.h"
#include "Objects/Sphere.h"
#include "Objects/Scene.h"
#include<iostream>

int main(int,char**)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(600, 300);
	bool quit=false;

	Canvas canvas(600, 300, renderer);
	Scene scene;
	//add objects
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ 0, 1, 0 })));
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
		renderer.Render(canvas, scene);

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