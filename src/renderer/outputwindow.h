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
		enum OutputColour
		{
			BLACK = 0,
			RED = 1,
			GREEN = 2,
			YELLOW = 3,
			BLUE = 4,
			MAGENTA = 5,
			CYAN = 6,
			GREY = 7,
			DARK_GREY = 0,
			LIGHT_RED = 1,
			LIGHT_GREEN = 2,
			LIGHT_YELLOW = 3,
			LIGHT_BLUE = 4,
			LIGHT_MAGENTA = 5,
			LIGHT_CYAN = 6,
			WHITE = 7
		};
		
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
				return eq;
			}
			
			bool operator==(const OutputCell& other) { return this->equalTo(other); }
			bool operator!=(const OutputCell& other) { return !this->equalTo(other); }
		};
		
		struct InputState
		{
			bool keyUP = false;
			bool keyLEFT = false;
			bool keyDOWN = false;
			bool keyRIGHT = false;
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
				
				virtual InputState getInputState() = 0;
				
				virtual void setCellChar(short x, short y, byte character = ' ') = 0;
				virtual void setCellForeground(short x, short y, byte foreground = 0) = 0;
				virtual void setCellBackground(short x, short y, byte background = 0) = 0;
				virtual void setCell(short x, short y, OutputCell cell = OutputCell(' ', 0, 0)) = 0;
		};
	}
}

#endif
