
#include <SDL.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gVentana = NULL;
SDL_Surface* gSuperficieDeVentana = NULL;
bool inicializar() {
  bool success = true;

  // Inicializar SDL
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL no se pudo inicializar, SDL Error: %s\n", SDL_GetError());
    success = false;
  } else {
    // Crear ventana
    gVentana = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gVentana == NULL) {
      printf("La ventana no se pudo crear, SDL Error: %s\n", SDL_GetError());
      success = false;
    } else {
      // Obtener superficie de la ventana
      gSuperficieDeVentana = SDL_GetWindowSurface(gVentana);
    }
  }

  return success;
}

int main() {

  // Iniciar SDL y crear ventana
  if ( !inicializar() ) {
    printf("Fallo la inicialización");
  }

  return 0;
}