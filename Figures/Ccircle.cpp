#include "Ccircle.h"
#include<fstream>
Ccircle::Ccircle()
{

}
Ccircle::Ccircle(Point c, Point on, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = c;
	onCircle = on;
}

void Ccircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(center, onCircle, FigGfxInfo, Selected);
}

bool Ccircle::IsInside(Point P)
{
	double r = sqrt(pow((center.x - onCircle.x), 2) + pow((center.y - onCircle.y), 2));
	if (sqrt(pow((center.x - P.x), 2) + pow((center.y - P.y), 2)) <= r)
	{
		return true;
	}
	return false;
}

void Ccircle::Save(ofstream& outf)
{
	outf << "CIRC" << " " << ID << " " << center.x << " " << center.y << " " << onCircle.x << " " << onCircle.y << " " << setcolor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
		outf << setcolor(FigGfxInfo.FillClr);
	else
		outf << "non-filled" << endl;
}

void Ccircle::Load(ifstream& inf)
{
	inf >> ID >> center.x >> center.y >> onCircle.x >> onCircle.y;
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

bool Ccircle::MoveFig(Point vec)
{
	center.x += vec.x;
	center.y += vec.y;
	onCircle.x += vec.x;
	onCircle.y += vec.y;
	return true;
}

Point Ccircle::GetCenter()
{
	return center;
}