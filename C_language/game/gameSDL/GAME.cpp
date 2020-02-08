#include "CommonFunction.h"

// bien toan cuc (glocal)
SDL_Surface *g_object = NULL;

bool Init(){ // Ham khoi tao (initialization)
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	// dinh dang man hinh
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	if (g_screen == NULL) {
		return false;
	}
	return true;
}

int main (int arc, char*  argv[]) {
	bool is_quit = false;
	if (Init() == false) {
		return 0;
	}

	// ApplySurface(bkground, screen, x, y);
	//hien background game
	g_bkground = SDL_CommonFunction::LoadImage("bg2.png");
	if (g_bkground == NULL) {
		return 0;
	}
	SDL_CommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);

	//hien nhan vat game
 	g_object = SDL_CommonFunction::LoadImage("human.png");
	if (g_object == NULL) {
		return 0;
	}
	SDL_CommonFunction::ApplySurface(g_object, g_screen, 300, 420);

	while (!is_quit) {
		while (SDL_PollEvent(&g_event)) { // kiem tra nhan phim
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
			}
		}
		if (SDL_Flip(g_screen) == -1) {
			return 0;
		}
	}

	// xoa bo nho chuong trinh
	SDL_CommonFunction::CleanUp();
	SDL_Quit();

	return 0;
}
