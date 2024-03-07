#ifndef CTRIA_H
#define CTRIA_H
#include "CFigure.h"
class Ctriangle:public CFigure
{
private:
	Point t1;
	Point t2;
	Point t3;
	Point center;
public:
	Ctriangle();
	Ctriangle(Point p1,Point p2,Point p3,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	void Save(ofstream& outf);
	void Load(ifstream& inf);
	virtual bool MoveFig(Point);
	virtual Point GetCenter();
};
#endif
