#ifndef Common_Function_H_
#define Common_Function_H_

//library
#include<SDL.h>
#include<string>
#include<Windows.h>
#include<SDL_image.h>
#include<ctime>

#define WIDTH_BACKGROUND 4800
#define HEIGHT_BACKGROUND 600
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 600
#define SCREEN_BPP 32
#define NUM_THREATS 3


// bien tinh (static variables)
static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Event g_event;

// Image game
#define BKG_GAME "img/bg4800.png"
#define M_OBJ "img/plane.png"
#define M_OBJ_BULLET "img/plane_bullet.png"
#define M_LAZE_BULLET "img/laser.png"
#define M_SPHERE_BULLET "img/sphere.png"
#define PLANE_THREAT "img/af1.png"
#define T_BULLET "img/sphere2.png"

// prototype function
namespace SDL_CommonFunction {
  int Random(int min, int max);// value random
  SDL_Surface* LoadImage(std::string file_path);// tao hinh anh trong game
  void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
  void CleanUp();// clean memory
}

#endif // Common_Function_H_
