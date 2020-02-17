#ifndef Common_Function_H_
#define Common_Function_H_

//library
#include<SDL.h>
#include<string>
#include<Windows.h>
#include<SDL_image.h>
#include<ctime>

#define SCREEN_WIDTH 1200 // chieu rong cua chuong trinh
#define SCREEN_HEIGHT 600 // chieu cao cua chuong trinh
#define SCREEN_BPP 32
#define NUM_THREATS 3 // so luong cua dich

// Image game
#define BKG_GAME "bg.png"

// bien tinh (static variables)
static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Event g_event;

// prototype function
namespace SDL_CommonFunction {
  int Random(int min, int max);// value random
  SDL_Surface* LoadImage(std::string file_path);// tao hinh anh trong game
  void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
  void CleanUp();// clean memory
}
#endif // Common_Function_H_
