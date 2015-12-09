#ifndef CRAGMOOR_RENDERER_GENERIC_MESSAGEBOX_H
#define CRAGMOOR_RENDERER_GENERIC_MESSAGEBOX_H

//----LOCAL----
#include "dialog.h"

namespace Cragmoor
{
	namespace Renderer
	{
		namespace Generic
		{
			class MessageBox : public Dialog
			{
				private:
					std::string text = "Default";
					bool visible = true;
				public:
					MessageBox(std::string title, std::string text);
					MessageBox(std::string title, std::string text, short x, short y, short w, short h);
					
					void draw(Renderer* renderer) override;
					bool tick(InputState inputs) override;
						
					void setVisible(bool visible) override;
			};
		}
	}
}

#endif
