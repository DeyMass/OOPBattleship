//Player
#include "graphics.h"
#include "Boats.cpp"
#include <stdlib.h>

class Player{
private:
	int Nboat1;
	int Nboat2;
	int Nboat3;
	int Nboat4;
	bool vertical;
	OdnoPalub *Pole[12][12];
public:
	Player(){
		DrawGrid(0,0);
		vertical = true;
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 12; j++)
				Pole[i][j] = NULL;
//		odin = new OdnoPalub	[4];
//		dva  = new DvuPalub		[3];
//		tre  = new TrePalub		[2];
//		chet = new ChetirPalub	[1];
		Nboat1 = 0;
		Nboat2 = 0;
		Nboat3 = 0;
		Nboat4 = 0;
	}
	int GetBoats(){
		return 0;
	}
	void PutBoat(int x, int y, int BoatType){
		if (BoatType == 1)
			Pole[x][y] = new OdnoPalub(x, y);
		if (BoatType == 2)
			//Pole[x][y] = new DvuPalub;
		if (BoatType == 3)
			//Pole[x][y] = new TrePalub;
		if (BoatType == 4);
			//Pole[x][y] = new ChetirPalub;
	}

    void Flip(){
        vertical = 1 - vertical;
        cleardevice();
        DrawGrid(0,0);
    }

	bool CheckAvailable(int tempx, int tempy, int TypeOfCheck){
		if (mousex () % GRIDSCALE == 0 || mousey() % GRIDSCALE == 0)
		{
			return false;
		}
		if (tempx > 10 || tempy > 10 || tempx < 1 || tempy < 1)
		{
			return false;
		}
		if (TypeOfCheck == 1)
			for (int i = 1; i >= -1; i--) {
				for (int j = -1; j <= 1; j++) {
		//			printf("Pole[%i][%i] = %p\n",tempx+i,tempy+j, Pole[tempx + i][tempy + j]);
					if (Pole[tempx + i][tempy + j] != NULL) return false;
				}
			}
		//printf("-----------------------------------------------------");
        if (TypeOfCheck == 2)
        {
            if (vertical == false && tempx > 9)
            {
                return false;
            }
            if (vertical == true && tempy > 9)
            {
                return false;
            }
        }
        return true;
	}

	bool CheckChange(int newX, int newY){
		static int prevX = -1;
		static int prevY = -1;
        if (!CheckAvailable(newX,newY, 1)){prevX = -1; prevY = -1; return false;}

		//printf("%i : %i after - %i : %i \n",prevX,prevY, newX, newY);
		if (newX != prevX || newY != prevY)
		{
			prevX = newX;
			prevY = newY;
			return true;
		}
		else return false;

	}

	void HighlightBoat(int BoatType, bool flag = false){
		static int tempx = -1;
		static int tempy = -1;
		if (flag){
			setfillstyle(1,BLACK);
			floodfill(tempx*GRIDSCALE + 1,tempy*GRIDSCALE + 1,WHITE);
			tempx = -1;
			tempy = -1;
			return;
		}
		if (BoatType == 1 && CheckChange(mousex() / GRIDSCALE, mousey() / GRIDSCALE)) {
			//if (!CheckAvailable(tempx, tempy, BoatType)) return;
			setfillstyle(1, BLACK);
		//	printf("%i : %i zakrasheno",tempx, tempy);
			floodfill(tempx * GRIDSCALE + 1, tempy * GRIDSCALE + 1, WHITE);
			tempx = mousex() / GRIDSCALE;
			tempy = mousey() / GRIDSCALE;
			if (!CheckAvailable(tempx, tempy, BoatType)) return;
			setfillstyle(1, COLOR(0, 255, 0));
		//	printf("%i : %i perekrasheno",tempx, tempy);
			floodfill(tempx * GRIDSCALE + 1, tempy * GRIDSCALE + 1, WHITE);
		}

		if (BoatType == 2 && CheckChange(mousex() / GRIDSCALE, mousey() / GRIDSCALE)){
			setfillstyle(1, BLACK);
			floodfill(tempx * GRIDSCALE + 1, tempy * GRIDSCALE + 1, WHITE);
			if (vertical == false) floodfill((tempx + 1) * GRIDSCALE + 1, tempy * GRIDSCALE + 1, WHITE);
			else floodfill(tempx * GRIDSCALE + 1, (tempy + 1) * GRIDSCALE + 1, WHITE);
			tempx = mousex() / GRIDSCALE;
			tempy = mousey() / GRIDSCALE;
			if (!CheckAvailable(tempx, tempy, BoatType)) return;
			setfillstyle(1,COLOR(0,255,0));
			floodfill(tempx * GRIDSCALE + 1,tempy * GRIDSCALE + 1, WHITE);
			if (vertical == false) floodfill((tempx + 1) * GRIDSCALE + 1, tempy * GRIDSCALE + 1, WHITE);
			else floodfill(tempx * GRIDSCALE + 1, (tempy + 1) * GRIDSCALE + 1, WHITE);
		}

		if (BoatType == 3 && CheckChange(mousex() / GRIDSCALE, mousey() / GRIDSCALE)){
			setfillstyle(1,COLOR(0,0,0));
			floodfill(tempx * GRIDSCALE + 1, tempy * GRIDSCALE + 1, WHITE);

		}

	}

	void PlaceBoats(int BoatType){
		printf("::::::: %i ::::::::::", BoatType);
		if ((Nboat1 == 4 || Nboat2 == 3 || Nboat3 == 2 || Nboat4 == 1) && BoatType != 0){
			BoatType = 0;
			outtextxy(350,650,"Out of boats!");
			return;
		}
		printf(" ----- ---- - %i - ---- -----\n",BoatType);
		if (BoatType != 0) {
			setfillstyle(1, BLACK);
			bar(350,650,700,700);
		}
		printf("%p\n",Pole[mousex() / GRIDSCALE][mousey() / GRIDSCALE]);
		HighlightBoat(BoatType);
		//printf("Frame %i \n",CheckAvailable(mousex() / GRIDSCALE, mousey() / GRIDSCALE,1));
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			HighlightBoat(1,true);
			clearmouseclick(WM_LBUTTONDOWN);
			if(!CheckAvailable(mousex() / GRIDSCALE, mousey() / GRIDSCALE,BoatType)) return;
			setfillstyle(1, COLOR(0,255,0));
			floodfill(mousex(), mousey(), WHITE);
			PutBoat(mousex() / GRIDSCALE, mousey() / GRIDSCALE, BoatType);
			if (BoatType == 1) Nboat1++;
			if (BoatType == 2) Nboat2++;
			if (BoatType == 3) Nboat3++;
			if (BoatType == 4) Nboat4++;
		}

	}
	void DrawGrid(int Sx, int Sy){
		settextstyle(2,0,CELLSFORGRID - 3);
        outtextxy(600,100,"1");
        outtextxy(600,200,"2");
        outtextxy(600,300,"3");
        outtextxy(600,400,"4");
		for (int i = Sy; i <= CELLSFORGRID; i++){
			for (int j = Sx; j <= CELLSFORGRID; j++){
				if (j != CELLSFORGRID){
					bgiout << j;
					outstreamxy(j * GRIDSCALE + 5, 0 + 5);
				}
				line(j*GRIDSCALE,0,j*GRIDSCALE,CELLSFORGRID*GRIDSCALE);
			}
			if (i != CELLSFORGRID){
					bgiout << i;
					outstreamxy(0 + 5, i * GRIDSCALE + 5);
				}
			line(0,i * GRIDSCALE, CELLSFORGRID * GRIDSCALE, i * GRIDSCALE);
		}
		
	}
};
