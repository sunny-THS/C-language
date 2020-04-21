#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
HANDLE wHnd;
HANDLE rHnd;
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x,y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void veKhung (int x, int y, int width, int height, int color, std::string text) {
	for (int i = 0; i < height; i++) {
		gotoxy(x, y + i);
		for (int j = 0; j < width ; j++) {
			if (i < 3 || i == height-1 || j == 0 || j == width-1) {
				textcolor(color);
			} else textcolor(7);
			std::cout << " ";
		}
	}
	gotoxy(x + (width - text.size())/2, y+1);
	std::cout << text;
}
void veNut (int x, int y, int size, int colorT, int colorF, int ctextT, int ctextF, std::string text, bool kt) {
	gotoxy(x, y);
	for (int i = 0; i < size; ++i) {
		if(i == 0 || i == size-1) {
			textcolor(7);std::cout << " ";

		}else {
			if (kt == true)
				textcolor(colorT);
			else
				textcolor(colorF);
			std::cout << "=";
		}
	}
	gotoxy(x, y+1);
	for (int i = 0; i < size; ++i) {
		if(i == 0 || i == size-1) {
			if (kt == true)
				textcolor(colorT);
			else
				textcolor(colorF);
			std::cout << "|";
		}else {
			textcolor(7);std::cout << " ";
		}
	}
	gotoxy(x, y+2);
	for (int i = 0; i < size; ++i) {
		if(i == 0 || i == size-1) {
			textcolor(7);std::cout << " ";
		}else {
			if (kt == true)
				textcolor(colorT);
			else
				textcolor(colorF);
			std::cout << "=";
		}
	}
	gotoxy(x + (size - text.size())/2, y + 1);
	if (kt == true)
		textcolor(ctextT);
	else
		textcolor(ctextF);
	std::cout << text;
}
void VeCot (int khoangCachCot[],int ViTri) {
	for (int i = 0; i < 7; ++i) {
		for (int j = 30; j < 44; ++j) {
			if (ViTri >= 0 && ViTri <= 96) {
				gotoxy(ViTri, j);
				textcolor(185);
				std::cout << "#XI";
				textcolor(7);
				std::cout << " ";
			} else if (ViTri == -1) {
				gotoxy (0, j);
				textcolor(185);
				std::cout << "XI";
				textcolor(7);
				std::cout << " ";
			} else if (ViTri == -2) {
				gotoxy(0, j);
				textcolor(185);
				std::cout << "I";
				textcolor(7);
				std::cout << " ";
			} else if (ViTri == -3) {
				gotoxy(0, j);
				textcolor(7);
				std::cout << " ";
			} else if (ViTri == 97) {
				gotoxy(ViTri, j);
				textcolor(185);
				std::cout << "#XI";
			} else if (ViTri == 98) {
				gotoxy(ViTri, j);
				textcolor(185);
				std::cout << "#X";
			} else if (ViTri == 99) {
				gotoxy(ViTri, j);
				textcolor(185);
				std::cout << "#";
			} else break;
		}
		ViTri += khoangCachCot[i];
	}
}
void VeVat (int viTri) {
	gotoxy(50, viTri);
	textcolor(12);
	std::cout << "@@@";
	gotoxy(50, viTri-1);
	std::cout << "@@@";
}
void XoaVat (bool kt, int viTri) {
	if (kt == 1)
	{
		gotoxy(50, viTri+1);
		textcolor(7);
		std::cout << "   ";
	} else {
		gotoxy(50, viTri-2);
		textcolor(7);
		std::cout << "   ";
	}
}
void gameOver (int diem, int& kt) {
	veKhung(35, 15, 30, 15, 202, "GAME OVER !");
	textcolor(14);
	gotoxy(44, 19);
	std::cout << "SCORE : " << diem;
	kt = 0;
	veNut(40, 23, 19, 13, 15, 94, 14, "PLAY AGAIN", 1);
	veNut(40, 26, 19, 13, 15, 94, 14, "BACK TO MENU", 0);
	while (1) {
		fflush(stdin);
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN)) {
			if (kt == 1) {
				kt = 0;
				veNut(40, 23, 19, 13, 15, 94, 14, "PLAY AGAIN", 1);
				veNut(40, 26, 19, 13, 15, 94, 14, "BACK TO MENU", 0);
				Sleep(100);
			} else {
				kt = 1;
				veNut(40, 23, 19, 13, 15, 94, 14, "PLAY AGAIN", 0);
				veNut(40, 26, 19, 13, 15, 94, 14, "BACK TO MENU", 1);
				Sleep(100);
			}
			fflush(stdin);
		}
		if (GetAsyncKeyState(VK_RETURN)) break;
	}
}
void VeGame () {
	while (1) {
		for (int i = 0; i < 44; ++i) {
			textcolor(7);
			gotoxy(0, i);
			for (int j = 0; j < 98; ++j) {
				std::cout << " ";
			}
		}
		gotoxy(0, 44);
		textcolor(10);
		std::cout << "+ Bui Tong Minh Chau +";
		int ktThoat = 0;
		int khoangCachCot[7];
		int ViTriChuan = 0;
		srand(time(0));
		for (int i = 0; i < 7; ++i) {
			khoangCachCot[i] = rand() % 6 + 15;
		}
		int ViTriVat = 0;
		for (int i = 0; i < 7; ++i) {
			ViTriVat += khoangCachCot[i];
			if (ViTriVat > 55)
				break;
		}
		ViTriVat -= 50;
		ViTriVat = 28 - ViTriVat/2;
		bool kt = 0;
		int thoiGian = 0;
		int diem=-1;
		gotoxy(0, 0);
		for (int i = 0; i < 300; ++i) {
			textcolor(46);
			std::cout << " ";
		}
		gotoxy(40, 1);
		std::cout << "SCORE : 0";
		bool ktDiem = 1;
		while (1) {
			int kc1 = khoangCachCot[0] + khoangCachCot[1] + ViTriChuan;
			int kc2 = kc1 + khoangCachCot[2];
			if (((kc1 >= 47 && kc1 <= 51)||(kc2 >=47 && kc2 <= 51))&&ViTriVat < 29)
				ktDiem = true;
			if (((kc1 >= 47 && kc1 <= 51)||(kc2 >=47 && kc2 <= 51))&&ViTriVat == 29&&ktDiem ==1) {
				++diem;
				gotoxy(48, 1);
				textcolor(46);
				std::cout << diem;
				ktDiem = 0;
			}
			if (((kc1 > 51 || kc1 < 47)&&(kc2 > 51 || kc2 < 47))&&ViTriVat == 29) {
				ViTriVat++;
				VeVat(ViTriVat);
				XoaVat(1, ViTriVat);
				break;
			}
			fflush(stdin);
			if (GetAsyncKeyState(VK_SPACE)) {
				if(((kc1 >= 47 && kc1 <= 51)||(kc2 >=47 && kc2 <= 51))&&ViTriVat == 29) {
					kt = 1;
				}
				fflush(stdin);
			}
			if (ViTriVat < 20) {
				kt = 0;
			}
			if (GetAsyncKeyState(VK_SPACE) && kt == 1) {
				kt = 1;
				fflush(stdin);
			}else if (!GetAsyncKeyState(VK_SPACE)) {
				kt = 0;
				fflush(stdin);
			}

			if (thoiGian % 5 == 0) {
				if (ViTriChuan < -4) {
					ViTriChuan = khoangCachCot[0]-5;
					for (int i = 0; i < 7; ++i) {
						khoangCachCot[i] = khoangCachCot[i+1];
					}
					khoangCachCot[6] = rand() % 6 + 15;
				}
				VeCot(khoangCachCot, ViTriChuan);
				ViTriChuan--;
			}if (thoiGian % 10 == 0) {

				if(kt == 1) {
					ViTriVat--;
					VeVat(ViTriVat);
					XoaVat(kt, ViTriVat);
				} else if (ViTriVat < 29){
					ViTriVat++;
					VeVat(ViTriVat);
					XoaVat(kt, ViTriVat);
				}
			}
			thoiGian++;
			thoiGian == 2000 ? thoiGian = 10:thoiGian = thoiGian;
			Sleep(10);
		}
		gameOver(diem, ktThoat);
		if (ktThoat == 1)
		{
			break;
		}
	}
}
void DiemCao (int newScore) {
	veKhung(30, 10, 40, 25, 157, "HIGH SCORE");
	std::fstream outf;
	outf.open("highScore.txt", std::ios::in | std::ios::out);
	std::tring diem[5];
	for (int i = 0,j = 15; i < 5; ++i, j+=2) {
		outf << diem[i];
		gotoxy(40, j);
		textcolor(15);
		std::cout << i+1 << ". ";
		textcolor(14);
		std::cout << diem[i];
	}
	outf.close();
}
void Thoat (bool& kt) {
	veKhung(29, 15, 35, 15, 74, "EXIT");
	gotoxy(36, 19);
	textcolor(12);
	kt = 1;
	std::cout << "Do you want to exit ?";
	veNut(31, 21, 30, 13, 15, 28, 12, "YES", 1);
	veNut(31, 25, 30, 13, 15, 26, 10, "NO", 0);
	Sleep(200);
	while (1) {
		fflush(stdin);
		if (GetAsyncKeyState(VK_UP)||GetAsyncKeyState(VK_DOWN)) {
			if (kt == 0) {
				kt = 1;
				veNut(31, 21, 30, 13, 15, 28, 12, "YES", 1);
				veNut(31, 25, 30, 13, 15, 26, 10, "NO", 0);
				Sleep(100);
			} else if (kt == 1) {
				kt = 0;
				veNut(31, 21, 30, 13, 15, 28, 12, "YES", 0);
				veNut(31, 25, 30, 13, 15, 26, 10, "NO", 1);
				Sleep(100);
			}
		}
		if (GetAsyncKeyState(VK_RETURN))
			break;
	}
}
void manHinhChinh (int& ktMenu, bool& ktThoat) {
	for (int i = 0; i < 44; ++i) {
		textcolor(7);
		gotoxy(0, i);
		for (int j = 0; j < 100; ++j) {
			std::cout << " ";
		}
	}
	textcolor(12);
	gotoxy(15, 5);
	std::cout << "       __ __  __ __  ___ ___       ______ ___    __  ___ _____";
	gotoxy(15, 6);
	std::cout << "      / // / / //  |/  // __ \\    / ____//   |  /  |/  // ____/";
	gotoxy(15, 7);
	std::cout << " __  / // / / // /|_/ // /_/ /   / /___ / /| | / /|_/ // __/   ";
	gotoxy(15, 8);
	std::cout << "/ /_/ // /_/ // /  / // ____/   / /_/ // ___ |/ /  / // /___   ";
	gotoxy(15, 9);
	std::cout << "\\____/ \\____//_/  /_//_/        \\____//_/  |_/_/  /_//_____/   ";
	veNut(32, 20, 30, 10, 15, 30, 14, "PLAY GAME",0);
	veNut(32, 24, 30, 10, 15, 30, 14, "HELP",0);
	veNut(32, 28, 30, 10, 15, 30, 14, "HIGH SCORE",0);
	veNut(32, 32, 30, 10, 15, 30, 14, "INTRODUCE",0);
	veNut(32, 36, 30, 10, 15, 30, 14, "EXIT",0);
	if (ktMenu == 1) {
		veNut(32, 20, 30, 10, 15, 30, 14, "PLAY GAME",1);
	} else if (ktMenu == 2) {
		veNut(32, 24, 30, 10, 15, 30, 14, "HELP",1);
	} else if (ktMenu == 3) {
		veNut(32, 28, 30, 10, 15, 30, 14, "HIGH SCORE",1);
	} else if (ktMenu == 4) {
		veNut(32, 32, 30, 10, 15, 30, 14, "INTRODUCE",1);
	} else if (ktMenu == 5) {
		veNut(32, 36, 30, 10, 15, 30, 14, "EXIT",1);
	}
	while (1) {
		fflush(stdin);
		if(GetAsyncKeyState(VK_UP)) {
			if (ktMenu == 2) {
				veNut(32, 20, 30, 10, 15, 30, 14, "PLAY GAME",1);
				veNut(32, 24, 30, 10, 15, 30, 14, "HELP",0);
				ktMenu--;
			} else if (ktMenu == 3) {
				veNut(32, 24, 30, 10, 15, 30, 14, "HELP",1);
				veNut(32, 28, 30, 10, 15, 30, 14, "HIGH SCORE",0);
				ktMenu--;
			} else if (ktMenu == 4) {
				veNut(32, 28, 30, 10, 15, 30, 14, "HIGH SCORE",1);
				veNut(32, 32, 30, 10, 15, 30, 14, "INTRODUCE",0);
				ktMenu--;
			} else if (ktMenu == 5) {
				veNut(32, 32, 30, 10, 15, 30, 14, "INTRODUCE",1);
				veNut(32, 36, 30, 10, 15, 30, 14, "EXIT",0);
				ktMenu--;
			} else if (ktMenu == 1) {
				veNut(32, 36, 30, 10, 15, 30, 14, "EXIT",1);
				veNut(32, 20, 30, 10, 15, 30, 14, "PLAY GAME",0);
				ktMenu = 5;
			}
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_DOWN)) {
			if (ktMenu == 1) {
				veNut(32, 20, 30, 10, 15, 30, 14, "PLAY GAME",0);
				veNut(32, 24, 30, 10, 15, 30, 14, "HELP",1);
				ktMenu++;
			} else if (ktMenu == 2) {
				veNut(32, 24, 30, 10, 15, 30, 14, "HELP",0);
				veNut(32, 28, 30, 10, 15, 30, 14, "HIGH SCORE",1);
				ktMenu++;
			} else if (ktMenu == 3) {
				veNut(32, 28, 30, 10, 15, 30, 14, "HIGH SCORE",0);
				veNut(32, 32, 30, 10, 15, 30, 14, "INTRODUCE",1);
				ktMenu++;
			} else if (ktMenu == 4) {
				veNut(32, 32, 30, 10, 15, 30, 14, "INTRODUCE",0);
				veNut(32, 36, 30, 10, 15, 30, 14, "EXIT",1);
				ktMenu++;
			} else if (ktMenu == 5) {
				veNut(32, 36, 30, 10, 15, 30, 14, "EXIT",0);
				veNut(32, 20, 30, 10, 15, 30, 14, "PLAY GAME",1);
				ktMenu = 1;
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_RETURN)) {
			if (ktMenu == 1)
				VeGame();
			else if (ktMenu == 5)
				Thoat(ktThoat);
			else if (ktMenu == 3)
				DiemCao(0);
			break;
		}
	}
}
int main () {
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT("JUMP GAME"));
	SMALL_RECT windowSize = {0, 0, 99, 44};
	COORD bufferSize = {100, 45};
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	int ktMenu = 1;
	bool ktThoat = 0;
	while (1) {
		if (ktThoat == 1) break;
		manHinhChinh(ktMenu, ktThoat);
	}
}
