#ifndef CRAGMOOR_RENDERER_GRAPHICALWINDOW_H
#define CRAGMOOR_RENDERER_GRAPHICALWINDOW_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "common/types.h"
#include "window/window.h"
#include "window/texture.h"
#include "outputwindow.h"

namespace Cragmoor
{
	namespace Renderer
	{
		class GraphicalWindow : public OutputWindow
		{
			private:
				std::vector<OutputCell> cells[2];
				
				byte swapper = 0;
				
				Colour palette[16];
				
				int width = 1;
				int height = 1;
				
				Window::Texture tileset;
				
				byte pixel_w = 1;
				short cell_w = 16;
				short cell_h = 16;
				short tile_w = 16;
				short tile_h = 16;
				
				Window::Window window;
				
				void setup();
				
				void blitSymbol(byte symbol, short x, short y, Colour foreground = Colour(255, 255, 255), Colour background = Colour(0, 0, 0));
			public:
				GraphicalWindow();
				~GraphicalWindow();
				
				void initiate() override;
				bool tick() override;
				
				OutputCell* getCell(short x, short y) override;
				
				short getWidth() override;
				short getHeight() override;
				
				InputState getInputState() override;
				
				void setCellChar(short x, short y, byte character = ' ') override;
				void setCellForeground(short x, short y, byte foreground = 0) override;
				void setCellBackground(short x, short y, byte background = 0) override;
				void setCell(short x, short y, OutputCell cell = OutputCell(' ', 0, 0)) override;
		};
	}
}

#endif
