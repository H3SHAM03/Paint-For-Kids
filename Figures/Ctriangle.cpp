#include "Ctriangle.h"
#include<fstream>
Ctriangle::Ctriangle()
{
}
Ctriangle::Ctriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	t1 = p1;
	t2 = p2;
	t3 = p3;
	center.x = (t1.x + t2.x + t3.x) / 3;
	center.y = (t1.y + t2.y + t3.y) / 3;
}

void Ctriangle::Draw(Output* pOut) const
{
	pOut->DrawTria(t1,t2,t3,FigGfxInfo,Selected);
}

bool Ctriangle::IsInside(Point P)
{
	double A, A1, A2, A3;
	A = (t1.x * (t2.y - t3.y) + t2.x * (t3.y - t1.y) + t3.x * (t1.y - t2.y)) / 2.0;
	A1 = (t1.x * (t2.y - P.y) + t2.x * (P.y - t1.y) + P.x * (t1.y - t2.y)) / 2.0;
	A2 = (t2.x * (t3.y - P.y) + t3.x * (P.y - t2.y) + P.x * (t2.y - t3.y)) / 2.0;
	A3 = (t3.x * (t1.y - P.y) + t1.x * (P.y - t3.y) + P.x * (t3.y - t1.y)) / 2.0;
	if (abs(A) == abs(A1) + abs(A2) + abs(A3))
	{
		return true;
	}
	return false;
}
void Ctriangle::Save(ofstream& outf)
{
	outf << "TRIA" << " " << ID << " " << t1.x << " " << t1.y << " " << t2.x << " " << t2.y << " " << t3.x << " " << t3.y << " " << setcolor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
		outf << setcolor(FigGfxInfo.FillClr);
	else
		outf << "non-filled" << endl;
}

void Ctriangle::Load(ifstream& inf)
{
	inf >> ID >> t1.x >> t1.y >> t2.x >> t2.y >> t3.x >> t3.y;
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

bool Ctriangle::MoveFig(Point vec)
{
	t1.x += vec.x;
	t1.y += vec.y;
	t2.x += vec.x;
	t2.y += vec.y;
	t3.x += vec.x;
	t3.y += vec.y;
	return true;
}

Point Ctriangle::GetCenter()
{
	return center;
}