//----LOCAL----
#include "window.h"

namespace Cragmoor
{
	namespace Window
	{
		Window::Window()
		{
			this->window = SDL_CreateWindow("Cragmoor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
			this->surface = SDL_GetWindowSurface(this->window);
		}
		
		void Window::blank()
		{
			SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format, 0xFF, 0xFF, 0xFF));
		}
		
		void Window::fetchEvents()
		{
			SDL_Event e;
			while(SDL_PollEvent(&e) != 0)
			{
				if(e.type == SDL_QUIT)
				{
					this->should_close = true;
				}
			}
		}
		
		void Window::setPixel(short x, short y, Pixel pixel)
		{
			Uint32* p_screen = (Uint32*)this->surface->pixels;
			p_screen += y * this->surface->w + x;
			*p_screen = SDL_MapRGBA(this->surface->format,pixel.r,pixel.g,pixel.b,pixel.a);  
		}
		
		bool Window::shouldClose()
		{
			return this->should_close;
		}

		void Window::update()
		{
			this->fetchEvents();
			
			SDL_UpdateWindowSurface(this->window);
			
			//SDL_Delay(20);
		}
		
		void Window::lockSurface(bool lock)
		{
			if (lock)
				SDL_UnlockSurface(this->surface);
			else
				SDL_LockSurface(this->surface);
		}
	}
}
