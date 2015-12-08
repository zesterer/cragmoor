//----LOCAL----
#include "window.h"

namespace Cragmoor
{
	namespace Window
	{
		Window::Window()
		{
			this->window = SDL_CreateWindow("Cragmoor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 840, SDL_WINDOW_SHOWN);
			this->surface = SDL_GetWindowSurface(this->window);
			
			this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
		}
		
		Window::~Window()
		{
			//SDL_DestroyWindow(this->window);
			SDL_DestroyRenderer(this->renderer);
			
			SDL_Quit();
		}
		
		void Window::blank()
		{
			SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(this->renderer, NULL);
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
			
			SDL_RenderPresent(this->renderer);
		}
		
		void Window::lockSurface(bool lock)
		{
			if (lock)
				SDL_UnlockSurface(this->surface);
			else
				SDL_LockSurface(this->surface);
		}
		
		void Window::renderTexture(Texture* texture, SDL_Rect source, SDL_Rect target)
		{
			SDL_RenderCopy(this->renderer, texture->getInternal(), &source, &target);
		}
		
		SDL_Renderer* Window::getInternalRenderer()
		{
			return this->renderer;
		}
		
		void Window::renderRectangle(SDL_Rect rectangle, Colour colour)
		{
			SDL_SetRenderDrawColor(this->renderer, colour.r, colour.g, colour.b, 255);
			SDL_RenderFillRect(this->renderer, &rectangle);
			SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
		}
		
		int Window::getWidth()
		{
			int w;
			SDL_GetWindowSize(this->window, &w, nullptr);
			return w;
		}
		
		int Window::getHeight()
		{
			int h;
			SDL_GetWindowSize(this->window, nullptr, &h);
			return h;
		}
	}
}
