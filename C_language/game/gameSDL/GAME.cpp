#include<SDL.h>
#include<string>
#include<Windows.h>
#include<SDL_image.h>

#define SCREEN_WIDTH 1200 // chieu rong cua chuong trinh
#define SCREEN_HEIGHT 600 // chieu cao cua chuong trinh
#define SCREEN_BPP 32

// bien toan cuc (glocal)
SDL_Surface *g_screen = NULL;
SDL_Surface *g_bkground = NULL;
SDL_Surface *g_object = NULL;
SDL_Event g_event;

bool Init(){
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

// load hinh anh game
SDL_Surface* LoadImage(std::string file_path) {
	SDL_Surface *load_image = NULL;
	SDL_Surface *optimize_image = NULL; // dinh dang hinh anh

	load_image = IMG_Load(file_path.c_str());
	if (load_image != NULL) {
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);
		// ky thuat color key
		if (optimize_image != NULL) {
		 UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF); // rgb(0,255,255)
		 SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
		}
	}
	return optimize_image;
}

void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

void CleanUp() {
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}

int main (int arc, char*  argv[]) {
	bool is_quit = false;
	if (Init() == false) {
		return 0;
	}

	// ApplySurface(bkground, screen, x, y);
	//hien background gmae
	g_bkground = LoadImage("bg2.png");
	if (g_bkground == NULL) {
		return 0;
	}
	ApplySurface(g_bkground, g_screen, 0, 0);

	//hien nhan vat game
 	g_object = LoadImage("human.png");
	if (g_object == NULL) {
		return 0;
	}
	ApplySurface(g_object, g_screen, 300, 420);

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

	CleanUp();
	SDL_Quit();

	return 0;
}
