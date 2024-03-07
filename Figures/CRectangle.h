#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point center;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	void Save(ofstream& outf);
	void Load(ifstream& inf);
	virtual bool MoveFig(Point);
	virtual Point GetCenter();
};
#endif