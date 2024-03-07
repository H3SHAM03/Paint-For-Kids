#include "CRectangle.h"
#include<fstream>
CRectangle::CRectangle()
{
}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInside(Point P)
{
	Point Center;
	double L, l, A, A1, A2, A3, A4;
	l = abs(Corner2.y - Corner1.y);
	L = abs(Corner2.x - Corner1.x);
	A = L * l;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	if (abs(Center.y-P.y) < l / 2 && abs(Center.x-P.x) < L / 2)
	{
		return true;
	}
	return false;
}

void CRectangle::Save(ofstream& outf)
{
	outf << "RECT" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << setcolor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
		outf << setcolor(FigGfxInfo.FillClr);
	else
		outf << "non-filled" << endl;
}

void CRectangle::Load(ifstream& inf)
{
	inf >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
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

bool CRectangle::MoveFig(Point vec)
{
	Corner1.x += vec.x;
	Corner1.y += vec.y;
	Corner2.x += vec.x;
	Corner2.y += vec.y;


	return true;
}

Point CRectangle::GetCenter()
{
	return center;
}