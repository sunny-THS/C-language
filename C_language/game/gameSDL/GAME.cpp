#include "CommonFunction.h"
#include "MainObject.h"
#include "ThreatsObject.h"

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
	srand(time(NULL));

	bool is_quit = false;
	if (Init() == false) {
		return 0;
	}

	// ApplySurface(bkground, screen, x, y);
	g_bkground = SDL_CommonFunction::LoadImage(BKG_GAME);
	if (g_bkground == NULL) {
		return 0;
	}

	// Make MainObject
	MainObject human_object;
	human_object.SetRect(100, 200);
	bool ret = human_object.LoadIMG(M_OBJ);
	if (!ret) { // ret == false
		return 0;
	}

	// Make ThreatsObject
	ThreatsObject* p_threats = new ThreatsObject[NUM_THREATS];
	for (int i = 0; i < NUM_THREATS; i++) {
		ThreatsObject* p_threat = (p_threats + i);
		if (p_threat != NULL) {
			ret = p_threat->LoadIMG(PLANE_THREAT);
			if (!ret) {
				return 0;
			}
			p_threat->SetRect(SCREEN_WIDTH + i* SDL_CommonFunction::Random(100, 300), SDL_CommonFunction::Random(0, SCREEN_HEIGHT*0.75));
			p_threat->set_x_val(2); // speed threats

			// Make bullet
			BulletObject* p_bullet = new BulletObject();
			p_threat->InitBullet(p_bullet);
		}
	}

	while (!is_quit) {
		while (SDL_PollEvent(&g_event)) {
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			human_object.HandleInputAction(g_event);
		}
		// Apply background
		SDL_CommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);

		// Implement main object
		human_object.Show(g_screen);
		human_object.HandleMove();
		human_object.MakeBullet(g_screen);

		// Implement Threats object
		for (int i = 0; i < NUM_THREATS; i++) {
			ThreatsObject* p_threat = (p_threats + i);
			if (p_threat != NULL) {
				p_threat->Show(g_screen);
				p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_threat->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
			}
		}

		// Update screen
		if (SDL_Flip(g_screen) == -1) {
			return 0;
		}
	}

	delete[] p_threats;
	// xoa bo nho chuong trinh
	SDL_CommonFunction::CleanUp();
	SDL_Quit();

	return 0;
}
