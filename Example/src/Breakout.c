/*
    Breakout
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

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <Breakout.h>
#include <defs.h>
#include <game_renderer.h>

int main(int argc, char **argv) {
  
  printf("Hello, World!\n");
  
  init();
  
  bool quit = false;
  SDL_Event e;
  
  printf("Starting event loop.\n");
  
  SDL_Rect box;
  box.x = 0; box.y = 0; //Don't matter when not using actual texture data.
  box.w = 40; box.h = 20; //Dimensions of the box.
  
  int next_game_tick = SDL_GetTicks();
  int curtick;
  int num_frames_processed;
  
  while (!quit) {
    
    curtick = SDL_GetTicks();
    num_frames_processed = 0;
    
    while(curtick > next_game_tick && num_frames_processed < MAXFRAMESKIP) {
      
      //Input
      while(SDL_PollEvent(&e) != 0) {
        switch(e.type) {
          case SDL_QUIT: //When the window receives a close request. (Clicks X button)
            quit = true;
            break;
          case SDL_KEYDOWN: //When a button gets pressed down.
            break;
          case SDL_KEYUP: //When a button is released.
            break;
        }
      }
      
      //Game Logic
      
      
      //Frame postprocessing
      next_game_tick += TICKSPERFRAME;
      num_frames_processed += 1;
      
    }
    
    //Now that the game logic has been updated sufficiently, update the rendering.
      
    //Rendering
    game_renderer_draw_background(renderer);
    
    game_renderer_draw_graphic(renderer, NULL, &box, 90, 70);
    
    game_renderer_present(renderer);
    
    //And make the game not spend 100% CPU.
    // This also slows the game down when at maximum load such that the user can still get input in.
    SDL_Delay(10); //Might want to tweak this if it becomes relevant.
    
  }
  
  shutdown_game();
  
  return 0; //Not needed. Just for good measure.
}

void init() {
  //This function initializes SDL and creates the game window.
  //If this fails, then it terminates the program.
  
  printf("Hello, Init!\n");
  
  //Initialize SDL.
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL: Could not initialize SDL: %s\n", SDL_GetError());
    exit(ERRORCODE_SDL); //Not using shutdown here because SDL wasn't initialized, which should be the fist action.
  }
  
  printf("No error with initializing SDL.\n");
  
  renderer = malloc(sizeof(game_renderer));
  if(renderer == NULL) {
    printf("Failed to allocate memory for game renderer.\n");
    shutdown_game(ERRORCODE_MEMORY);
  }
  
  //Create the SDL window.
  renderer->window = SDL_CreateWindow("WIP Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(renderer->window == NULL) {
    printf("SDL: Could not create window: %s\n", SDL_GetError());
    shutdown_game(ERRORCODE_SDL);
  } 
  
  printf("Creating the Window caused no problems.\n");
  
  renderer->renderer = SDL_CreateRenderer(renderer->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  //renderer = SDL_CreateSoftwareRenderer(windowSurface);
  if(renderer->renderer == NULL) {
    printf("SDL: Could not create renderer: %s\n", SDL_GetError());
    shutdown_game(ERRORCODE_SDL);
  } 
  
  printf("Creating the Renderer caused no problems.\n");
  
  printf("End of init function.\n");
  
}

void shutdown_game(int e) {
  //Free memory, quit SDL and close the program. The main means of exiting.
  
  printf("Shutting down.\n");
  
  game_renderer_destroy(renderer);
  
  //Destroy the renderer. This must be done before the window is destroyed.
  /*if(renderer != NULL) {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
  }
  
  //Destroy the window.
  if(window != NULL) {
    SDL_DestroyWindow(window);
    window = NULL;
  }*/
  
  //Quit SDL.
  SDL_Quit();
  
  exit(e);
  
}

