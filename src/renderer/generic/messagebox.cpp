//----LOCAL----
#include "messagebox.h"
#include "renderer.h"

namespace Cragmoor
{
	namespace Renderer
	{
		namespace Generic
		{
			MessageBox::MessageBox(std::string title, std::string text)
			{
				this->title = title;
				this->text = text;
			}
			
			MessageBox::MessageBox(std::string title, std::string text, short x, short y, short w, short h)
			{
				this->title = title;
				this->text = text;
				this->pos = Position(x, y);
				this->width = w;
				this->height = h;
			}
			
			void MessageBox::draw(Renderer* renderer)
			{
				if (this->visible)
				{
					/* Draw body */
					renderer->drawRectangle(this->pos.x, this->pos.y, this->width, this->height, OutputCell(' ', 11, 3));
					renderer->drawBorder(this->pos.x, this->pos.y, this->width, this->height, 11);
					renderer->drawText(this->pos.x + 1, this->pos.y + 1, this->width - 2, this->height - 2, this->text, 0);
					
					/* Draw title */
					renderer->drawString(this->pos.x + 4, this->pos.y, this->title, 11);
					renderer->getWindow()->setCellChar(this->pos.x + 3, this->pos.y, '|');
					renderer->getWindow()->setCellChar(this->pos.x + 4 + this->title.length(), this->pos.y, '|');
				}
			}
			
			bool MessageBox::tick(InputState inputs)
			{
				return false;
			}
			
			void MessageBox::setVisible(bool visible)
			{
				this->visible = visible;
			}
		}
	}
}
