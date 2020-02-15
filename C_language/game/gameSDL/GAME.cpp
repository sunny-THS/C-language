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
	//hien background game
	g_bkground = SDL_CommonFunction::LoadImage("bg.png");
	if (g_bkground == NULL) {
		return 0;
	}

	// Make MainObject
	MainObject human_object;
	human_object.SetRect(100, 200); // vi tri cua nhan vat
	bool ret = human_object.LoadIMG("plane.png");
	if (!ret) { // ret == false
		return 0;
	}

	// Make ThreatsObject
	ThreatsObject* threats = new ThreatsObject[NUM_THREATS];
	for (int i = 0; i < NUM_THREATS; i++) {
		ThreatsObject* p_threat = new ThreatsObject();
		ret = p_threat->LoadIMG("af1.png");
		p_threat->SetRect(SCREEN_WIDTH, SDL_CommonFunction::Random(0, SCREEN_HEIGHT*0.75));
		if (!ret) {
			return 0;
		}
		p_threat->set_x_val(2);
		// khoi tao dan cua dinh
		p_threat->InitBullet();
	}

	while (!is_quit) {
		while (SDL_PollEvent(&g_event)) { // kiem tra nhan phim
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			human_object.HandleInputAction(g_event);
		}
		SDL_CommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);
		human_object.Show(g_screen);
		human_object.HandleMove();

		// hien thi duong di cua vien dan
		for (int i = 0; i < human_object.GetBulletList().size(); i++) {
			std::vector<BulletObject*> bullet_list = human_object.GetBulletList();
			BulletObject* p_bullet = bullet_list.at(i);
			if (p_bullet != NULL) {
				if (p_bullet->get_is_move()) {
					p_bullet->Show(g_screen);
					p_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				}else {
					if (p_bullet != NULL) {
						bullet_list.erase(bullet_list.begin() + i); // xoa phan tu ra khoi bullet_list
						human_object.SetBulletList(bullet_list);

						delete p_bullet;
						p_bullet = NULL;
					}
				}
			}
		}

		// Threats
		p_threat->Show(g_screen);
		p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
		p_threat->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (SDL_Flip(g_screen) == -1) {
			return 0;
		}
	}

	// xoa bo nho chuong trinh
	SDL_CommonFunction::CleanUp();
	SDL_Quit();

	return 0;
}
