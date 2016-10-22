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
	DvuPalub(int sx, int sy, bool vert): OdnoPalub(sx,sy), vertical(vert){}
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


