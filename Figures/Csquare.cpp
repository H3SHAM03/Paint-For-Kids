#include "Csquare.h"
#include<fstream>
Csquare::Csquare()
{
}
Csquare::Csquare(Point c, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = c;
}

void Csquare::Draw(Output* pOut) const
{
	pOut->DrawSqua(center,FigGfxInfo,Selected);
}

bool Csquare::IsInside(Point P)
{
	if (abs(P.x - center.x) < 50 && abs(P.y - center.y) < 50)
	{
		return true;
	}
	return false;
}
void Csquare::Save(ofstream& outf)
{

	outf << "SQUA" << " " << ID << " " << center.x << " " << center.y << " " << setcolor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
		outf << setcolor(FigGfxInfo.FillClr);
	else
		outf << "non-filled" << endl;
}

void Csquare::Load(ifstream& inf)
{
	inf >> ID >> center.x >> center.y;
	string s;
	inf >> s;
	FigGfxInfo.DrawClr = getcolor(s);
	string f;
	inf >> f;
	if (f == "non-filled")
		FigGfxInfo.isFilled = false;
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getcolor(f);
	}
	Selected = false;
}

bool Csquare::MoveFig(Point vec)
{
	center.x += vec.x;
	center.y += vec.y;

	return true;
}

Point Csquare::GetCenter()
{
	return center;
}