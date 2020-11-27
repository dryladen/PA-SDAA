#ifndef _Ladun
#define _Ladun

void frameAwal();
void frameMain();
void frameDisplay();
void frameOneInput();
void frameTwoInput();
void frameFourInput();
void framePemiluMain();
void frameThreeInput();
void gotoXY(int x, int y);
void blink(std::string text, int x = 57);
void lineX(int start, int finish, int y, int unicode);
void lineY(int start, int finish, int x, int unicode);
void frame(int width1, int width2, int height1, int height2, int utfwidht1 = 223, int utfwidth2 = 220, int utfheight1 = 219, int utfheight2 = 219);

#endif
