
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gVentana = NULL;
SDL_Surface* gSuperficieDeVentana = NULL;
SDL_Surface* gSuperficieActual = NULL;


enum gTeclasPresionadas {
  TECLA_DEFECTO,
  TECLA_UP,
  TECLA_DOWN,
  TECLA_LEFT,
  TECLA_RIGHT,
  TECLA_TOTAL
};
// Arreglo de punteros a Superficies, de tamaño 5
SDL_Surface* gSuperficieDeLaTeclaPresionada[TECLA_TOTAL];

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

SDL_Surface* leerSuperficie( std::string rutaImagen) {
  // Leer imagen en la ruta especificada
  SDL_Surface* superficieLeida = SDL_LoadBMP(rutaImagen.c_str());
  if (superficieLeida == NULL) {
    printf("No se pudo leer la imagen %s! SDL Error: %s\n", rutaImagen.c_str(), SDL_GetError());
  }
  return superficieLeida;
}

bool leerMedios() {
  bool success = true;
  // Leer superficie por defecto
  gSuperficieDeLaTeclaPresionada[TECLA_DEFECTO] = leerSuperficie("press.bmp");
  if (gSuperficieDeLaTeclaPresionada[TECLA_DEFECTO] == NULL) {
    printf("Falló la lectura de la imagen press\n");
    success = false;
  }
  // Leer superficie UP
  gSuperficieDeLaTeclaPresionada[TECLA_UP] = leerSuperficie("up.bmp");
  if (gSuperficieDeLaTeclaPresionada[TECLA_UP] == NULL) {
    printf("Fallo la lectura de la imagen up");
    success = false;
  }

  gSuperficieDeLaTeclaPresionada[TECLA_DOWN] = leerSuperficie("down.bmp");
  if (gSuperficieDeLaTeclaPresionada[TECLA_DOWN] == NULL) {
    printf("Falló la lectura de la imagen down");
    success = false;
  }

  gSuperficieDeLaTeclaPresionada[TECLA_LEFT] = leerSuperficie("left.bmp");
  if (gSuperficieDeLaTeclaPresionada[TECLA_LEFT] == NULL) {
    printf("Falló la lectura de la imagen left");
    success = false;
  }

  gSuperficieDeLaTeclaPresionada[TECLA_RIGHT] = leerSuperficie("right.bmp");
  if (gSuperficieDeLaTeclaPresionada[TECLA_RIGHT] == NULL) {
    printf("Fallo la lectura de la imagen right");
    success = false;
  }
  return success;
}

int main() {
  printf("Starting\n");
  // Iniciar SDL y crear ventana
  if ( !inicializar() ) {
    printf("Fallo la inicialización");
  } else {
    // Leer medios
    if ( !leerMedios()) {
      printf("Fallo la lectura de medios\n");
    } else {
      bool quit = false;

      // Event handler
      SDL_Event e;

      // Setear superficie inicial
      gSuperficieActual = gSuperficieDeLaTeclaPresionada[TECLA_DEFECTO];

      while(!quit) {
        while(SDL_PollEvent(&e) != 0) {
          std::cout << "Evento detectado: " << e.type << std::endl;
          if (e.type == SDL_QUIT) {
            quit = true;
          } else if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
              gSuperficieActual = gSuperficieDeLaTeclaPresionada[TECLA_UP];
              break;
            case SDLK_DOWN:
              gSuperficieActual = gSuperficieDeLaTeclaPresionada[TECLA_DOWN];
              break;
            case SDLK_LEFT:
              gSuperficieActual = gSuperficieDeLaTeclaPresionada[TECLA_LEFT];
              break;
            case SDLK_RIGHT:
              gSuperficieActual = gSuperficieDeLaTeclaPresionada[TECLA_RIGHT];
              break;
            
            default:
              gSuperficieActual = gSuperficieDeLaTeclaPresionada[TECLA_DEFECTO];
              break;
            }
          }
        }

        // Aplicar la imagen actual
        SDL_BlitSurface(gSuperficieActual, NULL, gSuperficieDeVentana, NULL);

        // Actualizar la superficie
        SDL_UpdateWindowSurface(gVentana);
      }
    }
  }
  printf("Finished\n");
  SDL_Delay(500);
  return 0;
}