#include "stdio.h"

//----STANDARD----
#include "string"

//----LOCAL----
#include "renderer/renderer.h"
#include "window/timer.h"

int main(int argc, char* argv[])
{
	Cragmoor::Window::Window window;
	Cragmoor::Game::Game game;
	
	Cragmoor::Renderer::Renderer renderer(&game, &window);
	
	Cragmoor::Window::Timer timer;
	
	int ticks = 0;
	
	while (!window.shouldClose())
	{
		window.blank();
		
		renderer.tick();
		
		window.update();
		
		if (timer.getTime() >= 1.0)
			break;
		
		ticks ++;
	}
	
	printf(("Framerate: " + std::to_string(ticks) + "\n").c_str());
	
	return 0;
}
