#ifndef CRAGMOOR_RENDERER_CURSESWINDOW_H
#define CRAGMOOR_RENDERER_CURSESWINDOW_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "common/types.h"
#include "outputwindow.h"

namespace Cragmoor
{
	namespace Renderer
	{
		class CursesWindow : public OutputWindow
		{
			private:
				std::vector<OutputCell> cells[2];
				
				byte swapper = 0;
				
				int width = 96;
				int height = 32;
				
				void setup();
				
				void blitSymbol(byte symbol, short x, short y, byte foreground = 0, byte background = 0);
			public:
				CursesWindow();
				virtual ~CursesWindow();
				
				void initiate() override;
				bool tick() override;
				
				OutputCell* getCell(short x, short y) override;
				
				short getWidth() override;
				short getHeight() override;
				
				void setCellChar(short x, short y, byte character = ' ') override;
				void setCellForeground(short x, short y, byte foreground = 0) override;
				void setCellBackground(short x, short y, byte background = 0) override;
				void setCell(short x, short y, OutputCell cell = OutputCell(' ', 0, 0)) override;
		};
	}
}

#endif
