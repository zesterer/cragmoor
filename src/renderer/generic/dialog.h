#ifndef CRAGMOOR_RENDERER_GENERIC_DIALOG_H
#define CRAGMOOR_RENDERER_GENERIC_DIALOG_H

//----LOCAL----
#include "outputwindow.h"
#include "common/types.h"

namespace Cragmoor
{
	namespace Renderer
	{
		class Renderer;
		
		namespace Generic
		{
			class Dialog
			{
				protected:
					std::string title;
					Position pos = Position(0, 0);
					short width = 16;
					short height = 8;
				public:
					virtual void draw(Renderer* renderer) = 0;
					virtual bool tick(InputState inputs) = 0;
					
					virtual void setVisible(bool visible) = 0;
			};
		}
	}
}

#endif
