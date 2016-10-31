#define GRIDSCALE 40
#define FLAG (Ship*)1
#define GREY COLOR(125,125,125)
//#define BLACK COLOR(0,0,0)
//#define WHITE COLOR(255,255,255)
//#define GREEN COLOR(0,255,0);
#define CELLSFORGRID 11
#define SCREENMIDDLEX 350
#define SCREENMIDDLEY 500
#include <ctime>
#include <stdio.h>
#include <graphics.h>
//#include "Enemy.cpp"
#include <iostream.h>
#include "Player.cpp"

using namespace std;
//****************************************BattleShip
class Game{
private:
	int NScore;
public:
    int menu(){
	settextstyle(7,0,6);
	outtextxy(0,0,"BATTLESHIP V1");
	settextstyle(1,0,6);
	outtextxy(50,50,"Start the Game");
	outtextxy(50,250,"Quit the Game");

	while(1){
		if (ismouseclick(WM_LBUTTONDOWN) && mousex() > 50 && mousex() < 350 && mousey() > 50 && mousey() < 150) {
            break;
        }
		if (ismouseclick(WM_LBUTTONDOWN) && mousex() > 50 && mousex() < 350 && mousey() > 250 && mousey() < 350) {
            return -1;
        }
        clearmouseclick(WM_LBUTTONDOWN);
		delay(50);
	}
	cleardevice();
    settextstyle(7,0,6);
	outtextxy(350,0,"BATTLESHIP V1");
	settextstyle(1,0,6);
	outtextxy(50,50,"Player VS Player");
	outtextxy(50,250,"Player VS AI");
    clearmouseclick(WM_LBUTTONDOWN);
	while(1){
		if (ismouseclick(WM_LBUTTONDOWN) && mousex() > 50 && mousex() < 350 && mousey() > 50 && mousey() < 150) {
            cleardevice();
			return 1;
		}
		if (ismouseclick(WM_LBUTTONDOWN) && mousex() > 50 && mousex() < 350 && mousey() > 250 && mousey() < 350) {
            cleardevice();
            return 2;
        }
        clearmouseclick(WM_LBUTTONDOWN);
		delay(50);
	}
}

    void FakeLoading(){
        settextstyle(1,0,6);
        setcolor(MAGENTA);
        setfillstyle(1, LIGHTMAGENTA);
        outtextxy(150,350,"LOADING");
        for (int i = 0; i < 40; i++){
            ellipse(150 + (i * CELLSFORGRID), 450,0,0,2,2);
            delay(60);
        }
        cleardevice();
    }

	void update(){
//		Enemy .update();
//		Player.update();
	}
};

void CheckPress(Player &player1, int &type){
    if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 100 && mousey() < 150)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        type = 1;
        system("cls");
        printf("1 choosed");
    }
    if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 200 && mousey() < 250)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        player1.HighlightBoat(type,true);
        system("cls");
        type = 2;
        printf("2 choosed");
    }
    if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 300 && mousey() < 350)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        player1.HighlightBoat(type,true);
        system("cls");
        type = 3;
        printf("3 choosed");
    }
    if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 400 && mousey() < 450)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        player1.HighlightBoat(type,true);
        system("cls");
        type = 4;
        printf("4 choosed");
    }
    if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 500 && mousey() < 550)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        type = 1;
        player1.reset();
    }
    if (ismouseclick(WM_RBUTTONDOWN)){
        clearmouseclick(WM_RBUTTONDOWN);
        setfillstyle(1,BLACK);
        bar(50,600,200,700);
        if(player1.Flip(type) == 1)
            outtextxy(50,600,"Vertical");
        else
            outtextxy(50,600,"Horizontal");
    }
}

int main(){
	Game MAIN;
	initwindow(700,700);
	int menu = 1;
	//****************PlaceBoats
	int temp = MAIN.menu();
	switch(temp){
		case -1:
			return 0;
		default:
			menu = temp;
	}
	cleardevice();
	clearmouseclick(WM_LBUTTONDOWN);
	MAIN.FakeLoading();
	Player player1;
    int type = 1;
	while(menu == 1){
        CheckPress(player1,type);
		menu = player1.PlaceBoats(type);
		delay(100);
	}
    closegraph();
    initwindow(700,700);
    if (temp == 1) {
        outtextxy(150,350,"Player 2, place your Boats");
        delay(2000);
        cleardevice();
        Player player2;
        int menu = 1;
        int type = 1;
        while (menu == 1){
            CheckPress(player2,type);
            menu = player2.PlaceBoats(type);
            delay(100);
        }
    }

}
