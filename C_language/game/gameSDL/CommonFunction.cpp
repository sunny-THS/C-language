#include "CommonFunction.h"

// load hinh anh game
SDL_Surface* SDL_CommonFunction::LoadImage(std::string file_path) {
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

void SDL_CommonFunction::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

void SDL_CommonFunction::CleanUp() {
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}
