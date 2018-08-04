/*
    Breakout - Renderer
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

#include <game_renderer.h>

void game_renderer_destroy(game_renderer *renderer) {
  if(renderer->renderer != NULL) {
    SDL_DestroyRenderer(renderer->renderer);
    renderer->renderer = NULL;
  }
  
  if(renderer->window != NULL) {
    SDL_DestroyWindow(renderer->window);
    renderer->window = NULL;
  }
  
  if(renderer->background != NULL) {
    SDL_DestroyTexture(renderer->background);
    renderer->background = NULL;
  }
  
}

void game_renderer_draw_background(game_renderer *renderer) {
  
  //If there has been set a background graphic.
  if(renderer->background != NULL) {
    SDL_RenderCopy(renderer->renderer, renderer->background, NULL, NULL);
  } else { //No background graphic has been set.
    SDL_SetRenderDrawColor(renderer->renderer, 0, 0, 0, 0xFF); //Black.
    SDL_RenderClear(renderer->renderer); //Draw everything with the render draw color.
  }
  
}

void game_renderer_draw_graphic(game_renderer *renderer, SDL_Texture *graphic, SDL_Rect *graphic_box, int x, int y) {
  SDL_Rect pos;
  pos.x = x; pos.y = y;
  pos.w = graphic_box->w; pos.h = graphic_box->h;
  
  if(graphic != NULL) { //There is actual texture data
    SDL_RenderCopy(renderer->renderer, graphic, graphic_box, &pos);
  } else { //No texture data. Draw a rectangle.
    SDL_SetRenderDrawColor(renderer->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer->renderer, &pos);
  }
}

void game_renderer_present(game_renderer *renderer) {
  SDL_RenderPresent(renderer->renderer);
}




