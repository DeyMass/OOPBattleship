#define GRIDSCALE 40
#define FLAG (OdnoPalub*)1
//#define BLACK COLOR(0,0,0)
//#define WHITE COLOR(255,255,255)
//#define GREEN COLOR(0,255,0);
#define CELLSFORGRID 11

#include <stdio.h>
#include <graphics.h>
//#include "Enemy.cpp"
#include "Player.cpp"

//****************************************BattleShip
class Game{
private:
	int NScore;
public:
	Game():NScore(0){
//		Enemy .start();
//		Player.start();
	}
	void update(){
//		Enemy .update();
//		Player.update();
	}
};

int main(){
	Game MAIN;
	initwindow(700,700);
	Player player1;
//****************PlaceBoats
int type = 1;
	while(1){
		
		if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 100 && mousey() < 150)
		{
			clearmouseclick(WM_LBUTTONDOWN);
			type = 1;
			printf("1 choosed");
		}
		if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 200 && mousey() < 250)
		{
			clearmouseclick(WM_LBUTTONDOWN);
			type = 2;
			printf("2 choosed");
            player1.HighlightBoat(2,true);
		}
		if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 300 && mousey() < 350)
		{
			clearmouseclick(WM_LBUTTONDOWN);
			type = 3;
			printf("3 choosed");
		}
		if (ismouseclick(WM_LBUTTONDOWN) && mousex()> 600 && mousex()<700 && mousey() > 400 && mousey() < 450)
		{
			clearmouseclick(WM_LBUTTONDOWN);
			type = 4;
			printf("4 choosed");
		}
		if (ismouseclick(WM_RBUTTONDOWN)){clearmouseclick(WM_RBUTTONDOWN); player1.Flip();}
		player1.PlaceBoats(type);
		delay(100);
	}
}
