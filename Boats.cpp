#include <graphics.h>

class Ship{
private:
	void fill(int tempx, int tempy, int TillCol){
		floodfill(tempx * GRIDSCALE + 1, tempy * GRIDSCALE + 1, TillCol);
	}
	int x;
    int y;
    int Npalub;
    bool vertical;
	bool Check(int x, int y){
		if (x < CELLSFORGRID || x > 0)
			return true;
		if (y < CELLSFORGRID || y > 0)
			return true;
		return false;
	}
public:
    Ship(int sx, int sy, int type, bool vert):x(sx),y(sy),Npalub(type),vertical(vert){}
	int GetX(){ return x;}
	int GetY(){ return y;}
	int GetPalub(){ return Npalub;}
	int OpisCircle() {
		setfillstyle(1, GREY);
        for (int i = -1; i < Npalub + 1; i++) {
            printf("vertical: %i\n", vertical);
            if (vertical) {
                if (x - 1 > 0 && y + i < CELLSFORGRID && y + i > 0) {
                    fill(x - 1, y + i, WHITE);
                }
                if (x + 1 < CELLSFORGRID && y + i < CELLSFORGRID && y + i > 0) {
                    fill(x + 1, y + i, WHITE);
                }
                if (y - 1 > 0)
                    fill(x, y - 1, WHITE);
                if (y + Npalub < CELLSFORGRID)
                    fill(x, y + Npalub, WHITE);
            }
            if (!vertical) {
                if (x + i < CELLSFORGRID && y - 1 > 0 && x + i > 0) {
                    fill(x + i, y - 1, WHITE);
                }
                if (x + i < CELLSFORGRID && y + 1 < CELLSFORGRID && x + i > 0) {
                    fill(x + i, y + 1, WHITE);
                }
                if (x - 1 > 0)
                    fill(x - 1, y, WHITE);
                if (x + Npalub < CELLSFORGRID)
                    fill(x + Npalub, y, WHITE);
            }
        }
		/*
		for (int i = -1; i < Npalub + 1; i++)
			for (int j = -1; j <= 1; j++) {
				if (Pole[])
					if (vertical)
						fill(x + j, y + i, WHITE);
					else
						fill(x + i, y + j, WHITE);
			}*/
	}

};
/*
class OdnoPalub{
private:
protected:
	bool hitted1;
	bool Defeated;
    int* x;
    int* y;
public:
	OdnoPalub(){
		Defeated = false;
	}
    void hit(){
        outtextxy(SCREENMIDDLEX,SCREENMIDDLEY,"Odnopalubnik unichtozhen");
    }
    void ClearOut(){
        setfillstyle(1,BLACK);
        bar(SCREENMIDDLEX,SCREENMIDDLEY,getwindowheight(),getwindowwidth());
    }
};

class DvuPalub: public OdnoPalub{
private:
protected:
	bool hitted2;
	bool vertical;
public:
	DvuPalub(int sx, int sy, bool vert){}
    int GetX(){
//        return x2;
    }
    int GetY(){
        return y2;
    }
};

class TrePalub: public DvuPalub{
private:
protected:
	bool hitted3;
	int  x3;
	int  y3;
public:
	TrePalub(int sx, int sy, bool vert): DvuPalub(sx,sy,vert){}
};

class ChetirPalub: public TrePalub{
private:
public:
	bool hitted4;
	int  x4;
	int  y4;
public:
	ChetirPalub(int sx, int sy, bool vert): TrePalub(sx,sy,vert){}
};


*/
