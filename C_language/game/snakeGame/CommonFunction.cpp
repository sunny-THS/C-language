#include "CommonFunction.h"
int CommonFunction::random(int max, int min) {
  return min+rand()%(max+1-min);
}
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
int CommonFunction::whereX() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int CommonFunction::whereY() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void CommonFunction::GotoXY(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void CommonFunction::SetColor(int x) {
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, x);
}
//============== làm ẩn trỏ chuột ===========
void CommonFunction::ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int CommonFunction::inputKey() {
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}
void CommonFunction::SetVideoMode(int w, int h, char *text){
  HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
  HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT(text));
	SMALL_RECT windowSize = {0, 0, w, h};
	COORD bufferSize = {w, h};
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
}
