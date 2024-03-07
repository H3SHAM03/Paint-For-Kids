#ifndef CHEXA_H
#define CHEXA_H
#include "CFigure.h"

class Chexagon:public CFigure
{
private:
	Point center;
public:
	Chexagon();
	Chexagon(Point c,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	void Save(ofstream& outf);
	void Load(ifstream& inf);
	virtual bool MoveFig(Point);
	virtual Point GetCenter();
};
#endif
