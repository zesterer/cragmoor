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
	
	while (!window.shouldClose())
	{
		window.blank();
		
		renderer.tick();
		
		window.update();
	}
	
	return 0;
}
