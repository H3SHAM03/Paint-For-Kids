#ifndef CSQUA_H
#define CSQUA_H
#include "CFigure.h"
class Csquare:public CFigure
{
private:
	Point center;
public:
	Csquare();
	Csquare(Point c,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	void Save(ofstream& outf);
	void Load(ifstream& inf);
	virtual bool MoveFig(Point);
	virtual Point GetCenter();
};
#endif
