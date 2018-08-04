/*
    Breakout - Renderer Header
    Copyright (C) 2018  Patrick Jakobsen
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.
    
    You should have received a copy of the GNU Affero General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAME_RENDERER_H_
#define GAME_RENDERER_H_

#include <SDL.h>

typedef struct game_renderer {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *background; //May be NULL
} game_renderer;

//Destroys the game renderer. Doesn't free the renderer pointer.
void game_renderer_destroy(game_renderer *renderer);

//Draws the background, whatever that amounts to.
void game_renderer_draw_background(game_renderer *renderer);

//Draws a graphic on the screen.
void game_renderer_draw_graphic(game_renderer *renderer, SDL_Texture *graphic, SDL_Rect *graphic_box, int x, int y);

//Makes the rendering operations take effect.
void game_renderer_present(game_renderer *renderer);

#endif // GAME_RENDERER_H_
