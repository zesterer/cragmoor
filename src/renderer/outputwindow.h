#ifndef CRAGMOOR_RENDERER_OUTPUTWINDOW_H
#define CRAGMOOR_RENDERER_OUTPUTWINDOW_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "common/types.h"
#include "window/window.h"
#include "window/texture.h"

namespace Cragmoor
{
	namespace Renderer
	{
		struct OutputCell
		{
			byte character = ' ';
			byte foreground = 0;
			byte background = 0;
			
			OutputCell(byte character, byte foreground, byte background)
			{
				this->character = character;
				this->foreground = foreground;
				this->background = background;
			}
			
			bool equalTo(const OutputCell& other)
			{
				bool eq = true;
				eq &= this->character == other.character;
				eq &= this->foreground == other.foreground;
				eq &= this->background == other.background;
				return !eq;
			}
			
			bool operator==(const OutputCell& other) { return this->equalTo(other); }
			bool operator!=(const OutputCell& other) { return !this->equalTo(other); }
		};
		
		class OutputWindow
		{
			private:
			public:
				virtual void initiate() = 0;
				virtual bool tick() = 0;
				
				virtual OutputCell* getCell(short x, short y) = 0;
				virtual short getWidth() = 0;
				virtual short getHeight() = 0;
				
				virtual void setCellChar(short x, short y, byte character = ' ') = 0;
				virtual void setCellForeground(short x, short y, byte foreground = 0) = 0;
				virtual void setCellBackground(short x, short y, byte background = 0) = 0;
				virtual void setCell(short x, short y, OutputCell cell = OutputCell(' ', 0, 0)) = 0;
		};
	}
}

#endif
