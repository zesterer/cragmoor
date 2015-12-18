#include "stdio.h"

//----STANDARD----
#include "string"

//----LOCAL----
#include "renderer/renderer.h"
#include "window/timer.h"

int main(int argc, char* argv[])
{
	Cragmoor::Game::Game game;
	
	Cragmoor::Renderer::Renderer renderer(&game);
	
	/*Cragmoor::Window::Timer timer;
	int ticks = 0;*/
	
	while (!renderer.shouldClose())
	{
		game.tick();
		
		renderer.tick();
		
		/*if (timer.getTime() >= 1.0)
		{
			timer.reset();
			printf(("FPS:" + std::to_string(ticks) + "\n").c_str());
			ticks = 0;
		}
		ticks ++;*/
	}
	
	return 0;
}
