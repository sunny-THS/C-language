#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

//tuy vao cua so console
#define CONSOLE_HEIGHT 30 //chieu cao cua console
#define CONSOLE_WIDTH 120 // chieu dai cua console
#define SPEED_MIN 100 // toc do toi da

//gia tri mau
enum COLOR {
  Blue = 1,
  Green = 10,
  Purple = 13,
  Orange = 12,
  White = 15,
  Gray = 8,
  Red = 4,
  CadetBlue = 11,  // xanh lam
  Yellow = 14
};
//gia tri cua chieu dai, chieu rong cua khung game
enum KHUNGGAME {
  // xy va yx tuong duong voi toa do x
  // xx va yy tuong duong vơi toa do y
  xy = 2,
  xx = CONSOLE_WIDTH/2,
  yx = 1,
  yy = CONSOLE_HEIGHT-2
};

enum TrangThai {UP, DOWN, LEFT, RIGHT};

typedef struct ToaDo{
  int x, y;
}TD;
struct Color{
  int color_Snake, color_Fruit, color_KhungGame;
};
struct Snake{
  TD dot[1000];
  int n;// do dai cua con ran
  TrangThai tt;
};
struct Fruit{
  TD tD;
};
typedef struct ThongSoGame{
  int speed, score;
  Color clr;
}TS;


void draw(int, int, int, int, TS);
void gotoxy(int, int);
void cls();
void textColor(int);
int random(int, int);
void khoiTao(Snake &snake, Fruit &fr);
void hienThi_Snake(Snake snake, TS);
void hienThi_Fruit(Fruit fr, TS);
void dieuKhien_DiChuyen(Snake &snake, Fruit &fr, TS &thongSo);
int processed(Snake &snake, Fruit &fr, TS &thongSo);
void beginGame(Snake &snake, Fruit &fr, TS &thongSo);
void startGame(Snake &s, Fruit &f, TS &ts);
void menu(char *start, char *help, char *e, int, int, int);
void howToPlay(Snake &snake, Fruit &fr, TS &thongSo);
void loadingGame();

// main function
int main(){
  srand(time(NULL)); // bo dem phat sinh ngau nhien

  Snake snake;
  TS thongSo;
  Fruit fr;

  loadingGame();
  beginGame(snake, fr, thongSo);
  //startGame(snake, fr, thongSo);

  return 0;
}

void loadingGame(){
  char title_Game[] = "\n\n\t\t ######  ##    ##    ###    ##    ## ########     ######      ###    ##     ## ########\n\t\t##    ## ###   ##   ## ##   ##   ##  ##          ##    ##    ## ##   ###   ### ##      \n\t\t##       ####  ##  ##   ##  ##  ##   ##          ##         ##   ##  #### #### ##      \n\t\t ######  ## ## ## ##     ## #####    ######      ##   #### ##     ## ## ### ## ######  \n\t\t      ## ##  #### ######### ##  ##   ##          ##    ##  ######### ##     ## ##      \n\t\t##    ## ##   ### ##     ## ##   ##  ##          ##    ##  ##     ## ##     ## ##      \n\t\t ######  ##    ## ##     ## ##    ## ########     ######   ##     ## ##     ## ########";
  int loading = 0, time_delay = 5;
  char t[] = "Game Loading...";

  while (loading!=101) {
    cls();
    textColor(random(1,15));
    printf("%s", title_Game);
    gotoxy((CONSOLE_WIDTH-strlen(t))/2-3, CONSOLE_HEIGHT/2);
    textColor(Green);
    printf("%s %d", t, loading);
    loading++;
    if (loading >= 90) {
      time_delay = 50;
    }
    Sleep(time_delay);
  }
  cls();
}

void beginGame(Snake &snake, Fruit &fr, TS &thongSo){
  char title_Game[] = "\n\n\t\t ######  ##    ##    ###    ##    ## ########     ######      ###    ##     ## ########\n\t\t##    ## ###   ##   ## ##   ##   ##  ##          ##    ##    ## ##   ###   ### ##      \n\t\t##       ####  ##  ##   ##  ##  ##   ##          ##         ##   ##  #### #### ##      \n\t\t ######  ## ## ## ##     ## #####    ######      ##   #### ##     ## ## ### ## ######  \n\t\t      ## ##  #### ######### ##  ##   ##          ##    ##  ######### ##     ## ##      \n\t\t##    ## ##   ### ##     ## ##   ##  ##          ##    ##  ##     ## ##     ## ##      \n\t\t ######  ##    ## ##     ## ##    ## ########     ######   ##     ## ##     ## ########";
  char start[] = "Start Game";
  char help[] = "How to play";
  char e[] = "Exit";
  int y = 4, n = 15;//y la chon, n la khong chon
  int select = 1;//1 la start game, 2 la help, 3 la exit

  textColor(Green);
  printf("%s", title_Game);
  while (1) {
    switch (select) {
      case 1: menu(start, help, e, y, n, n); break;
      case 2: menu(start, help, e, n, y, n); break;
      case 3: menu(start, help, e, n, n, y); break;
    }

    // dieu khien chon
    if (kbhit()) { // phat hien nhan phim
      char key = _getch();
      if (key == 'w' || key == 'W' || key == 56 || key == 72) {
        select--;
        if (select<1) {
          select = 3;
        }
      }else if (key == 's' || key == 'S' || key == 50 || key == 80) {
        select++;
        if (select>3) {
          select = 1;
        }
      }else if (key == 13) {
        // khi nhan phim enter
        switch (select) {
          case 2: howToPlay(snake, fr, thongSo); break;
          case 1: {
            startGame(snake, fr, thongSo);
            select = 3;
          }
          case 3: cls(); break;
        }
        if (select == 3) {
          break;
        }
      }
    }
  }
}

void startGame(Snake &snake, Fruit &fr, TS &thongSo){
  thongSo.speed = 200; // toc do game
  thongSo.clr.color_Snake = 10;
  thongSo.clr.color_Fruit = 4;
  thongSo.clr.color_KhungGame = 14;
  thongSo.score = 0;

  int a = 0;

  khoiTao(snake, fr);
  while (1) {
    cls();//xoa man hinh moi vong lap
    // hien thi
    draw(xx, xy, yx, yy, thongSo); // ve khung hinh
    hienThi_Snake(snake, thongSo); // ve ran
    hienThi_Fruit(fr, thongSo); // ve trai cay
    //dieu khien
    dieuKhien_DiChuyen(snake, fr, thongSo);
    a = processed(snake, fr, thongSo);
    // hien thi diem da ghi
    char score_[] = "Score:";
    gotoxy((CONSOLE_WIDTH/2-strlen(score_))/2+CONSOLE_WIDTH/2, CONSOLE_HEIGHT/4+2);
    printf("%s %d", score_, thongSo.score);
    // xu ly thua
    // neu thua a tra ve 1
    if (a == -1) {
      // thong bao thua
      char alertLose[] = "Ban da thua ^.^";
      char info[] = "nhan phim esc de choi lai";
      char info_Score[] = "Diem cua ban:";
      gotoxy((CONSOLE_WIDTH/2-strlen(alertLose))/2+CONSOLE_WIDTH/2, CONSOLE_HEIGHT/2);
      printf("%s", alertLose);
      gotoxy((CONSOLE_WIDTH/2-strlen(info))/2+CONSOLE_WIDTH/2, CONSOLE_HEIGHT/2+2);
      printf("%s", info);
      gotoxy((CONSOLE_WIDTH/2-strlen(info_Score))/2+CONSOLE_WIDTH/2, CONSOLE_HEIGHT/2+4);
      printf("%s %d", info_Score, thongSo.score);
      while (_getch()!=27);
      cls();
      beginGame(snake, fr, thongSo);
      break;
    }
    Sleep(thongSo.speed); //toc do game
  }
}
void howToPlay(Snake &snake, Fruit &fr, TS &thongSo){
    cls();
    char info_1[] = "Dieu khien bang cac nut w a s d hoac 8 4 2 6";
    char info_2[] = "Nhan esc de quay lai";
    char info_3[] = "Nhan enter de dung lai";
    while (1) {
      gotoxy((CONSOLE_WIDTH-strlen(info_1))/2, CONSOLE_HEIGHT/2-3);
      textColor(Green);
      printf("%s", info_1);
      gotoxy((CONSOLE_WIDTH-strlen(info_2))/2, CONSOLE_HEIGHT/2+2-3);
      textColor(Green);
      printf("%s", info_2);
      gotoxy((CONSOLE_WIDTH-strlen(info_3))/2, CONSOLE_HEIGHT/2+4-3);
      textColor(Green);
      printf("%s", info_3);
      if (kbhit()) {
        char key = _getch();
        if (key == 27) {
          cls();
          beginGame(snake, fr, thongSo);
        }
      }
    }
}

void gotoxy(int x, int y){
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h, c);
}
void cls(){
  system("cls");
}
//tao mau chu
void textColor(int x){
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, x);
}
// ham random
int random(int min, int max){
  return min + rand()%(max-min+1);
}

//ve khung hinh
void draw(int xx, int xy, int yx, int yy, TS thongSo){
  textColor(thongSo.clr.color_KhungGame);
  for (int i = xy; i <= xx; i++) {
    for (int j = yx; j <= yy; j++) {
      if (i==xx || i==xy) {
        gotoxy(i, j);
        putchar(179);
      }else if (j==yy) {
        gotoxy(i, j);
        putchar(95);
      }else if (j==yx) {
        gotoxy(i, j-yx);
        putchar(95);
      }
    }
  }
  char title[] = "Snake Game";
  char hr[] = "==++==++==++==++==";
  int chieuDaiKhung = 10;
  int chieuRongKhung= CONSOLE_WIDTH/4-xy;
  // ve khung
  textColor(CadetBlue);
  for (int i = 0; i < chieuDaiKhung; i++) {
    gotoxy(CONSOLE_WIDTH/2+2, xy+i);
    for (int j = 0; j < chieuRongKhung; j++) {
      if (i==0||i==chieuDaiKhung-1) {
        printf("* ");
      }else if (j==0||j==chieuRongKhung-1) {
        printf("* ");
      }else {
        printf("  ");
      }
    }
    printf("\n");
  }
  textColor(Red);
  gotoxy((CONSOLE_WIDTH/2-strlen(title))/2+CONSOLE_WIDTH/2, CONSOLE_HEIGHT/7);
  printf("%s", title);
  gotoxy((CONSOLE_WIDTH/2-strlen(hr))/2+CONSOLE_WIDTH/2, CONSOLE_HEIGHT/4);
  printf("%s", hr);
}
//tao menu Game
void menu(char *start, char *help, char *e, int a, int b, int c){
  //hien thi menu
  gotoxy((CONSOLE_WIDTH-strlen(start))/2, CONSOLE_HEIGHT/2-3);
  textColor(a);
  printf("%s", start);
  gotoxy((CONSOLE_WIDTH-strlen(help))/2, CONSOLE_HEIGHT/2+2-3);
  textColor(b);
  printf("%s", help);
  gotoxy((CONSOLE_WIDTH-strlen(e))/2, CONSOLE_HEIGHT/2+4-3);
  textColor(c);
  printf("%s", e);
}

void khoiTao(Snake &snake, Fruit &fr){
  // khoi tao ran
  snake.n = random(3, 4); // do dai cua ran chua tinh dau
  snake.dot[0].x = random(xy+1, xx-1);
  snake.dot[0].y = random(yx+1, yy-1);
  for (int i = 1; i < snake.n; i++) {
    snake.dot[i].x = snake.dot[0].x -i;
    snake.dot[i].y = snake.dot[0].y;
  }
  snake.tt = RIGHT;

  // khoi tao trai cay
  fr.tD.x = random(xy+1, xx-1);
  fr.tD.y = random(yx+1, yy-1);

}
void hienThi_Snake(Snake snake, TS thongSo){
  for (int i = 0; i < snake.n; i++) {
    if (i==0) {
      gotoxy(snake.dot[i].x, snake.dot[i].y);
      textColor(Blue);
      putchar(42);
    }else {
      gotoxy(snake.dot[i].x, snake.dot[i].y);
      textColor(thongSo.clr.color_Snake);
      putchar(248);
    }
  }
}

void hienThi_Fruit(Fruit fr, TS thongSo){
  //tao thuc an
  textColor(thongSo.clr.color_Fruit);
  gotoxy(fr.tD.x, fr.tD.y);
  putchar(248);
}

void dieuKhien_DiChuyen(Snake &snake, Fruit &fr, TS &thongSo){
  //trang thai di chuyen cua tung dot
  for (int i = snake.n - 1; i > 0; i--) {
    snake.dot[i] = snake.dot[i-1];
  }

  // thiet lap nut di chuyen
  if (kbhit()) { // phat hien nhan phim
    char key = _getch();
    if ((key == 'a' || key == 'A' || key == 52) && snake.tt != RIGHT) {
      snake.tt = LEFT;
    }else if ((key == 'd' || key == 'D' || key == 54) && snake.tt != LEFT) {
      snake.tt = RIGHT;
    }else if ((key == 'w' || key == 'W' || key == 56) && snake.tt != DOWN) {
      snake.tt = UP;
    }else if ((key == 's' || key == 'S' || key == 50) && snake.tt != UP) {
      snake.tt = DOWN;
    }else if (key == 32) {
      system("pause");
    }else if (key == 27) {
      cls();
      beginGame(snake, fr, thongSo);
    }
  }

  // thiet lap huong di chuyen
  if (snake.tt == UP) {
    snake.dot[0].y--;
  }else if (snake.tt == DOWN) {
    snake.dot[0].y++;
  }else if (snake.tt == LEFT) {
    snake.dot[0].x--;
  }else if (snake.tt == RIGHT) {
    snake.dot[0].x++;
  }
}

int processed(Snake &snake, Fruit &fr, TS &thongSo){
  // xu li cham nhau
  if (snake.dot[0].x == fr.tD.x && snake.dot[0].y == fr.tD.y) {
    snake.n++;
    fr.tD.x = random(xy+1, xx-1);
    fr.tD.y = random(yx+1, yy-1);
    thongSo.score++;
    if (thongSo.speed > SPEED_MIN) {
      thongSo.speed -= 10;
    }
  }
  // dieu kien thua
  if (snake.dot[0].x < xy || snake.dot[0].x >= xx || snake.dot[0].y < yx || snake.dot[0].y > yy) {
    // khi di chuyen qua duong gioi han se thua
    return -1;
  }
  for (int i = 1; i < snake.n; i++) {
    // khi tu Can
    if (snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y) {
      return -1;
    }
  }
}
