#include <graphics.h>

class Ship{
private:
	void hz(){}
};

class OdnoPalub{
private:
protected:
	bool hitted1;
	bool Defeated;
	int  x;
	int  y;
public:
	OdnoPalub(int sx, int sy){
		x = sx; y = sy;
		Defeated = false;
		hitted1 = false;
	}
};

class DvuPalub: public OdnoPalub{
private:
protected:
	bool hitted2;
	bool vertical;
	int  x2;
	int  y2;
public:
	DvuPalub(int x, int y,int x2, int y2): OdnoPalub(x,y){}
};

class TrePalub: public DvuPalub{
private:
protected:
	bool hitted3;
	int  x3;
	int  y3;
public:
	TrePalub(int x, int y, int x2, int y2, int x3, int y3): DvuPalub(x,y,x2,y2){}
};

class ChetirPalub: public TrePalub{
private:
public:
	bool hitted4;
	int  x4;
	int  y4;
public:
	ChetirPalub(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4): TrePalub(x,y,x2,y2,x3,y3){}
};


