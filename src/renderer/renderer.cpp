//----LOCAL----
#include "renderer.h"
#include "graphicalwindow.h"
#include "curseswindow.h"
#include "generic/messagebox.h"

namespace Cragmoor
{
	namespace Renderer
	{
		Renderer::Renderer(Game::Game* game)
		{
			this->game = game;
			this->window = window;
			
			if (0)
				this->window = new CursesWindow();
			else
				this->window = new GraphicalWindow();
			
			this->window->initiate();
			
			std::string str = "Welcome, young traveller, to the kingdom of Cragmoor.\n\nAlthough the wind may blow and the rain may pour, you must venture onwards. A little to the north there exists a small hamlet by which you may obtain provisions and a bed for the night. Alas, I must leave you now, but I wish you luck and bid thee farewell.";
			this->dialogs.push_back(new Generic::MessageBox("Welcome!", str, 2, 2, this->window->getWidth() - 4, 8));
			
			this->dialogs.push_back(new Generic::MessageBox("Controls & Keys", "Use the arrowkeys to move the view around!", 2, this->window->getHeight() - 7, 32, 4));
		}
		
		Renderer::~Renderer()
		{
			delete this->window;
		}
		
		void Renderer::tick()
		{
			/* Process Input */
			int xx = 0;
			int yy = 0;
			InputState inputs = this->window->getInputState();
			
			if (inputs.keyUP)
				yy --;
			if (inputs.keyLEFT)
				xx --;
			if (inputs.keyDOWN)
				yy ++;
			if (inputs.keyRIGHT)
				xx ++;
			
			this->game->setViewFocus(this->game->getViewFocus() + Position(xx, yy));
			
			/* Process dialogs */
			for (unsigned int i = 0; i < this->dialogs.size(); i ++)
			{
				Generic::Dialog* dialog = this->dialogs[i];
				dialog->tick(inputs);
			}
			
			/* Render things */
			this->renderGame();
			
			//this->drawRectangle(2, 2, this->window->getWidth() - 4, 10, OutputCell(' ', 11, 3));
			//this->drawBorder(2, 2, this->window->getWidth() - 4, 10, 11);
			
			//this->drawText(3, 3, this->window->getWidth() - 6, 6, str, 11);
			
			/* Draw dialogs */
			for (unsigned int i = 0; i < this->dialogs.size(); i ++)
			{
				Generic::Dialog* dialog = this->dialogs[i];
				dialog->draw(this);
			}
			
			/* Update things */
			
			this->should_close |= this->window->tick();
			
			this->time ++;
		}
		
		void Renderer::renderGame()
		{
			Game::World::World* world = this->game->getWorld();
			
			Position focus = this->game->getViewFocus();
			focus.x = std::max(0, std::min(world->getWidth(), focus.x));
			focus.y = std::max(0, std::min(world->getHeight(), focus.y));
			
			int width = this->window->getWidth();
			int height = this->window->getHeight();
			
			//Render floor types
			for (int x = 0; x < width; x ++)
			{
				for (int y = 0; y < height; y ++)
				{
					Game::World::Cell* cell = world->getCell(focus.x + x, focus.y + y);
					Game::World::FloorType floortype = world->getFloorType(cell->floor_type);
					
					this->window->setCell(x, y, OutputCell(floortype.character, floortype.foreground, floortype.background));
				}
			}
			
			//Render entities
			for (int i = 0; i < this->game->getEntityCount(); i ++)
			{
				Game::Entity::Entity* entity = this->game->getEntity(i);
				
				if (entity->getPosition().isInRectangle(focus.x, focus.y, width, height))
				{
					this->window->setCellChar(entity->getPosition().x - focus.x, entity->getPosition().y - focus.y, entity->getCharacter());
					this->window->setCellForeground(entity->getPosition().x - focus.x, entity->getPosition().y - focus.y, entity->getColour());
				}
			}
		}
		
		bool Renderer::shouldClose()
		{
			return this->should_close;
		}
		
		void Renderer::drawRectangle(short x, short y, short w, short h, OutputCell cell)
		{
			for (short i = 0; i < w; i ++)
			{
				for (short j = 0; j < h; j ++)
				{
					this->window->setCell(x + i, y + j, cell);
				}
			}
		}
		
		/* TODO - Could probably do with cleaning up */
		void Renderer::drawText(short x, short y, short w, short h, std::string text, byte colour)
		{
			std::vector<std::string>lines;
			lines.emplace_back();
			
			if (w < 1)
				w = 1;
			
			for (unsigned int i = 0; i < text.size(); i ++)
			{
				bool skip_char = false;
				unsigned int str_id = lines.size() - 1;
				
				if (lines[str_id].size() >= (unsigned int)w)
				{
					lines.emplace_back();
					
					unsigned int last = lines[str_id].size() - 1;
					while (lines[str_id][last] != ' ' && last > 0)
						last --;
					
					if (last > 0)
					{
						lines[str_id + 1] += lines[str_id].substr(last + 1, lines[str_id].size() - last - 1);
						lines[str_id] = lines[str_id].substr(0, last);
					}
					
					str_id = lines.size() - 1;
				}
				
				{
					if (text[i] == '\n')
					{
						lines.emplace_back();
						str_id = lines.size() - 1;
						skip_char = true;
					}
					
					if (text[i] == '\0')
						skip_char = true;
					
					if (!skip_char)
						lines[str_id] += text[i];
				}
				
				if (str_id >= (unsigned int)h)
					break;
			}
			
			if ((unsigned int)h > lines.size())
				h = lines.size();
			
			for (short j = 0; j < h; j ++)
			{
				this->drawString(x, y + j, lines[j], colour);
			}
		}
		
		void Renderer::drawString(short x, short y, std::string text, byte colour)
		{
			for (unsigned int i = 0; i < text.size(); i ++)
			{
				this->window->setCellChar(x + i, y, text[i]);
					this->window->setCellForeground(x + i, y, colour);
			}
		}
		
		void Renderer::drawBorder(short x, short y, short w, short h, byte colour)
		{
			this->window->setCellChar(x, y, 12 * 16 + 9);
			this->window->setCellChar(x + w - 1, y, 11 * 16 + 11);
			this->window->setCellChar(x, y + h - 1, 12 * 16 + 8);
			this->window->setCellChar(x + w - 1, y + h - 1, 11 * 16 + 12);
			
			for (short i = 0; i < w - 2; i ++)
			{
				this->window->setCellChar(x + i + 1, y, 12 * 16 + 13);
				this->window->setCellForeground(x + i + 1, y, colour);
				
				this->window->setCellChar(x + i + 1, y + h - 1, 12 * 16 + 13);
				this->window->setCellForeground(x + i + 1, y + h - 1, colour);
			}
			
			for (short j = 0; j < h - 2; j ++)
			{
				this->window->setCellChar(x, y + j + 1, 11 * 16 + 10);
				this->window->setCellForeground(x, y + j + 1, colour);
				
				this->window->setCellChar(x + w - 1, y + j + 1, 11 * 16 + 10);
				this->window->setCellForeground(x + w - 1, y + j + 1, colour);
			}
		}
	}
}
