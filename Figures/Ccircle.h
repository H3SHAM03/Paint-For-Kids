#ifndef CCIRC_H
#define CCIRC_H
#include "CFigure.h"
class Ccircle:public CFigure
{
private:
	Point center;
	Point onCircle;
public:
	Ccircle();
	Ccircle(Point c, Point on, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& outf);
	void Load(ifstream& inf);
	virtual bool IsInside(Point P);
	virtual bool MoveFig(Point);
	virtual Point GetCenter();
};
#endif
