//Player
#ifndef GRIDSCALE
#define GRIDSCALE 40
#endif
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
	Ship *Pole[12][12];
protected:
    void fill(int tempx, int tempy, int TillCol){
        floodfill(tempx * GRIDSCALE + 1, tempy * GRIDSCALE + 1, TillCol);
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
        if (Pole[tempx][tempy] != NULL) return false;


        if (vertical == false && tempx > CELLSFORGRID - TypeOfCheck)
        {
            return false;
        }
        if (vertical == true && tempy > CELLSFORGRID - TypeOfCheck)
        {
            return false;
        }

        if (TypeOfCheck == 2)
        {
            if ((Pole[tempx + 1][tempy] != NULL) && !vertical)
                return false;
            if ((Pole[tempx][tempy + 1] != NULL) && vertical)
                return false;
        }
        if (TypeOfCheck == 3)
        {
            if ((Pole[tempx + 1][tempy] != NULL || Pole[tempx+2][tempy] != NULL)
                && !vertical)
            {
                return false;
            }
            if ((Pole[tempx][tempy + 1] != NULL || Pole[tempx][tempy+2] != NULL) && vertical)
            {
                return false;
            }
        }
        if (TypeOfCheck == 4)
        {
            if ((Pole[tempx + 1][tempy] != NULL || Pole[tempx+2][tempy] != NULL || Pole[tempx + 3][tempy] != NULL)
                && !vertical)
            {
                return false;
            }
            if ((Pole[tempx][tempy + 1] != NULL || Pole[tempx][tempy+2] != NULL || Pole[tempx][tempy + 3] != NULL)
                && vertical)
            {
                return false;
            }
        }
        return true;
    }

    bool CheckChange(int newX = mousex() / GRIDSCALE, int newY = mousey() / GRIDSCALE){
        static int prevX = -1;
        static int prevY = -1;
        if (!CheckAvailable(newX,newY, 1)){prevX = -1; prevY = -1; return false;}

        if (newX != prevX || newY != prevY)
        {
            prevX = newX;
            prevY = newY;
            return true;
        }
        else return false;

    }

    void PutBoat(int x, int y, int BoatType){
        Pole[x-1][y-1]  = FLAG;
        Pole[x-1][y]    = FLAG;
        Pole[x-1][y+1]  = FLAG;
        Pole[x][y-1]    = FLAG;
        Pole[x+1][y-1]  = FLAG;
        Pole[x+1][y + 1]= FLAG;
        if (BoatType == 1) {
            Pole[x][y] = new Ship(x, y, BoatType, vertical);

            Pole[x + 0][y + 1] = FLAG;
            Pole[x + 1][y + 0] = FLAG;
        }
        if (BoatType == 2) {
            Pole[x][y] = new Ship(x, y, BoatType, vertical);
            if (vertical)
                Pole[x][y+1]= Pole[x][y];
            else
                Pole[x+1][y]= Pole[x][y];

            if (vertical) {
                Pole[x + 1][y + 0] = FLAG;
                Pole[x + 1][y + 0] = FLAG;
                Pole[x + 1][y + 2] = FLAG;
                Pole[x + 0][y + 2] = FLAG;
                Pole[x - 1][y + 2] = FLAG;
            }
            else {
                Pole[x + 2][y - 1] = FLAG;
                Pole[x + 2][y    ] = FLAG;
                Pole[x + 2][y + 1] = FLAG;
                Pole[x][y + 1]     = FLAG;
            }
        }
        if (BoatType == 3) {
            Pole[x][y] = new Ship(x, y, BoatType, vertical);
            if (vertical) {
                Pole[x][y + 1] = Pole[x][y];
                Pole[x][y + 2] = Pole[x][y];
            }
            else {
                Pole[x + 1][y] = Pole[x][y];
                Pole[x + 2][y] = Pole[x][y];
            }
            if (vertical) {
                Pole[x - 1][y + 2] = FLAG;
                Pole[x - 1][y + 3] = FLAG;
                Pole[x + 0][y + 3] = FLAG;
                Pole[x + 1][y + 2] = FLAG;
                Pole[x + 1][y + 3] = FLAG;
                Pole[x + 1][y + 0] = FLAG;
            }
            else {
                Pole[x + 2][y - 1] = FLAG;
                Pole[x + 2][y + 1] = FLAG;
                Pole[x + 3][y + 1] = FLAG;
                Pole[x + 3][y + 0] = FLAG;
                Pole[x + 3][y - 1] = FLAG;
                Pole[x + 0][y - 1] = FLAG;
            }

        }
        if (BoatType == 4) {
            Pole[x][y] = new Ship(x, y, BoatType, vertical);
            if (vertical) {
                Pole[x - 1][y + 2] = FLAG;
                Pole[x - 1][y + 3] = FLAG;
                Pole[x - 1][y + 4] = FLAG;
                Pole[x + 1][y + 2] = FLAG;
                Pole[x + 1][y + 3] = FLAG;
                Pole[x + 1][y + 4] = FLAG;
                Pole[x + 0][y + 4] = FLAG;
                Pole[x + 1][y + 0] = FLAG;
            }
            else{
                Pole[x + 2][y - 1] = FLAG;
                Pole[x + 3][y - 1] = FLAG;
                Pole[x + 4][y - 1] = FLAG;
                Pole[x + 4][y + 0] = FLAG;
                Pole[x + 4][y + 1] = FLAG;
                Pole[x + 3][y + 1] = FLAG;
                Pole[x + 2][y + 1] = FLAG;
            }
        }

    }

    void clearGrid(){
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++)
                if(Pole[i][j] == FLAG) Pole[i][j] = NULL;
    }

    int mouseX(){
        return mousex()/GRIDSCALE;
    }
    int mouseY(){
        return mousey()/GRIDSCALE;
    }
public:
	Player(){
		DrawGrid(0,0);
		vertical = true;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++)
                Pole[i][j] = NULL;
		Nboat1 = 0;
		Nboat2 = 0;
		Nboat3 = 0;
		Nboat4 = 0;
	}

    Ship* getBoat(int x, int y){
        return Pole[x][y];
    }

    void reset(){
        Nboat1 = 0;
        Nboat2 = 0;
        Nboat3 = 0;
        Nboat4 = 0;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++) {
                if (Pole [i][j] != FLAG && Pole[i][j] != NULL)
                    delete Pole[i][j];
                Pole[i][j] = NULL;

            }
        vertical = true;
        cleardevice();
        DrawGrid(0,0);
    }

	int GetBoats(int index){
		if (index == 1)
            return Nboat1;
        if (index == 2)
            return Nboat2;
        if (index == 3)
            return Nboat3;
        if (index == 4)
            return Nboat4;
        return -1;

	}

	void Flip(int BoatType){
		HighlightBoat(BoatType,true);
		vertical = 1 - vertical;
	}

	void HighlightBoat(int BoatType, bool flag = false){
		static int tempx = -1;
		static int tempy = -1;
		if (flag) {
			setfillstyle(1, BLACK);
			fill(tempx, tempy, WHITE);
			if (BoatType == 2 && vertical)
				fill(tempx, tempy + 1, WHITE);
			if (BoatType == 2 && !vertical)
				fill(tempx + 1, tempy, WHITE);

			if (BoatType == 3 && vertical) {
				fill(tempx, tempy + 2, WHITE);
				fill(tempx, tempy + 1, WHITE);
			}
			if (BoatType == 3 && !vertical) {
				fill(tempx + 2, tempy, WHITE);
				fill(tempx + 1, tempy, WHITE);
			}
			if (BoatType == 4 && vertical) {
				fill(tempx, tempy + 3, WHITE);
				fill(tempx, tempy + 2, WHITE);
				fill(tempx, tempy + 1, WHITE);
			}
			if (BoatType == 4 && !vertical) {
				fill(tempx + 3, tempy, WHITE);
				fill(tempx + 2, tempy, WHITE);
				fill(tempx + 1, tempy, WHITE);
			}
			tempx = -1;
			tempy = -1;
			return;
		}
		if (BoatType == 1 && CheckChange()) {
			setfillstyle(1, BLACK);
			fill(tempx,tempy,WHITE);
			tempx = mouseX();
			tempy = mouseY();

			if (!CheckAvailable(tempx, tempy, BoatType)) return;
			setfillstyle(1, COLOR(0, 255, 0));
			fill(tempx,tempy,WHITE);
		}

		if (BoatType == 2 && CheckChange()){
			setfillstyle(1, BLACK);
			fill(tempx,tempy,WHITE);
			if (vertical == false) {
				fill(tempx + 1, tempy, WHITE);
			}
			else {
				fill(tempx, tempy + 1, WHITE);
			}
			tempx = mouseX();
			tempy = mouseY();
			if (!CheckAvailable(tempx, tempy, BoatType)) return;
			setfillstyle(1,COLOR(0,255,0));
			fill(tempx,tempy,WHITE);
			if (vertical == false) {
				fill(tempx + 1, tempy, WHITE);
			}
			else {
				fill(tempx, tempy + 1, WHITE);
			}
		}

		if (BoatType == 3 && CheckChange()){
			setfillstyle(1, BLACK);
			fill(tempx,tempy,WHITE);
			if (vertical == false) {
				fill(tempx + 1, tempy, WHITE);
				if (Pole[tempx+2][tempy] == NULL)
					fill(tempx + 2, tempy, WHITE);
			}
			else {
				fill(tempx, tempy + 1, WHITE);
				if (Pole[tempx][tempy + 2] == NULL)
					fill(tempx, tempy + 2, WHITE);
			}
			tempx = mouseX();   tempy = mouseY();
			if (!CheckAvailable(tempx, tempy, BoatType)) return;
			setfillstyle(1,COLOR(0,255,0));
			fill(tempx,tempy,WHITE);
			if (vertical == false)
			{
				fill(tempx + 1, tempy, WHITE);
				fill(tempx + 2, tempy, WHITE);
			}
			else
			{
				fill(tempx, tempy + 1, WHITE);
				fill(tempx, tempy + 2, WHITE);
			}
		}
		if (BoatType == 4 && CheckChange()){
			setfillstyle(1, BLACK);
			fill(tempx,tempy,WHITE);
			if (vertical == false) {
				fill(tempx + 1, tempy, WHITE);
				if (Pole[tempx + 2][tempy] == NULL)
					fill(tempx + 2, tempy, WHITE);
				if (Pole[tempx + 3][tempy] == NULL)
					fill(tempx + 3,tempy,WHITE);
			}
			else {
				fill(tempx, tempy + 1, WHITE);
				if (Pole[tempx][tempy + 2] == NULL)
					fill(tempx, tempy + 2, WHITE);
				if (Pole[tempx][tempy + 3] == NULL)
					fill(tempx, tempy + 3, WHITE);
			}
			tempx = mouseX();   tempy = mouseY();
			if (!CheckAvailable(tempx, tempy, BoatType)) return;
			setfillstyle(1,COLOR(0,255,0));
			fill(tempx,tempy,WHITE);
			if (vertical == false)
			{
				fill(tempx + 1, tempy, WHITE);
				fill(tempx + 2, tempy, WHITE);
				fill(tempx + 3, tempy, WHITE);
			}
			else
			{
				fill(tempx, tempy + 1, WHITE);
				fill(tempx, tempy + 2, WHITE);
				fill(tempx, tempy + 3, WHITE);
			}
		}

	}

	int PlaceBoats(int BoatType){
        if (Nboat1 == 5 && Nboat2 == 5 && Nboat3 == 5 && Nboat4 == 5) {
            clearGrid();
            return 0;
        }
        if ((Nboat1 == 4 || Nboat2 == 3 || Nboat3 == 2 || Nboat4 == 1)){
			BoatType = 0;
			if (Nboat1 == 4) Nboat1 = 5;
			if (Nboat2 == 3) Nboat2 = 5;
			if (Nboat3 == 2) Nboat3 = 5;
			if (Nboat4 == 1) Nboat4 = 5;
		    outtextxy(350,650,"Out of boats!");
			return 1;
		}
		if (BoatType == 1 && Nboat1 >= 4) {
            outtextxy(350,650,"Out of boats!");
            return 1;
        }
		if (BoatType == 2 && Nboat2 >= 3){
            outtextxy(350,650,"Out of boats!");
            return 1;
        }
		if (BoatType == 3 && Nboat3 >= 2) {
            outtextxy(350,650,"Out of boats!");
            return 1;
        }
		if (BoatType == 4 && Nboat4 >= 1) {
            outtextxy(350,650,"Out of boats!");
            return 1;
        }

		if (BoatType != 0) {
			setfillstyle(1, BLACK);
			bar(350,650,700,700);
		}
		HighlightBoat(BoatType);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			HighlightBoat(1,true);
			clearmouseclick(WM_LBUTTONDOWN);
			if(!CheckAvailable(mouseX(), mouseY(), BoatType)) return 1;
			setfillstyle(1, COLOR(0,255,0));
			floodfill(mousex(), mousey(), WHITE);
			PutBoat(mouseX(),mouseY(), BoatType);
			if (BoatType == 1) Nboat1++;
			if (BoatType == 2) Nboat2++;
			if (BoatType == 3) Nboat3++;
			if (BoatType == 4) Nboat4++;
		}
        return 1;
	}

	void DrawGrid(int Sx, int Sy){
        setfillstyle(1,WHITE);
        setcolor(WHITE);
		settextstyle(2,0,CELLSFORGRID - 3);
		outtextxy(600,100,"1");
		outtextxy(600,200,"2");
		outtextxy(600,300,"3");
		outtextxy(600,400,"4");
        outtextxy(600,500,"Reset");
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
