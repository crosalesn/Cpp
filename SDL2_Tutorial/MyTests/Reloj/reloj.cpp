
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 240;
SDL_Window* gVentana = NULL;
SDL_Renderer* gRenderer = NULL;

bool inicializar() {
  bool success = true;

  // Inicializar SDL
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL no se pudo inicializar, SDL Error: %s\n", SDL_GetError());
    success = false;
  } else {
    // Crear ventana
    gVentana = SDL_CreateWindow("Cristopher's SDL Explorations", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gVentana == NULL) {
      printf("La ventana no se pudo crear, SDL Error: %s\n", SDL_GetError());
      success = false;
    } else {
      // Crear renderer
      gRenderer = SDL_CreateRenderer(gVentana, -1, SDL_RENDERER_ACCELERATED);
      if (gRenderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        success = false;
      }
    }
  }

  return success;
}

int main() {
  TTF_Init();
  printf("Starting\n");
  // Cargar Fuente
  TTF_Font* Sarai = TTF_OpenFont("Sarai.ttf", 800);
  // Definir color
  SDL_Color White = {255, 255, 0};
  // Iniciar SDL y crear ventana
  if ( !inicializar() ) {
    printf("Fallo la inicialización\n");
    return 0;
  }
  bool quit = false;
  SDL_Surface* surfaceMessage = NULL;
  SDL_Texture* texture = NULL;
  SDL_Event e;
  int frame = 1;
  while (!quit) {
    while( SDL_PollEvent( &e ) != 0 ) {
      //User requests quit
      if( e.type == SDL_QUIT )
      {
        quit = true;
      } 
    }
    std::string texto = "Texto prueba";
    time_t now = time(0);   // get time now
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);
    texto = buf;
    surfaceMessage = TTF_RenderText_Solid(Sarai, texto.c_str(), White); 
    //SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sarai, "texto prueba", White);
    texture = SDL_CreateTextureFromSurface(gRenderer, surfaceMessage );
    //Clear screen
    SDL_RenderClear( gRenderer );

    // Render Texture to screen
    SDL_RenderCopy(gRenderer, texture, NULL, NULL);

    // Update Scren
    SDL_RenderPresent(gRenderer);


    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surfaceMessage);
  }
  printf("Finished\n");
  TTF_Quit();
  return 0;
}