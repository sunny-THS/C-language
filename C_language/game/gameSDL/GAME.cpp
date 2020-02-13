#include "CommonFunction.h"
#include "MainObject.h"

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

	MainObject human_object;
	human_object.SetRect(100, 200); // vi tri cua nhan vat
	bool ret = human_object.LoadIMG("plane.png");
	if (!ret) { // ret == false
		return 0;
	}
	human_object.Show(g_screen);

	while (!is_quit) {
		while (SDL_PollEvent(&g_event)) { // kiem tra nhan phim
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			human_object.HandleInputAction(g_event);
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
