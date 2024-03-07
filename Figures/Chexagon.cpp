#include "Chexagon.h"
#include<fstream>
Chexagon::Chexagon()
{
}

Chexagon::Chexagon(Point c, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = c;
}

void Chexagon::Draw(Output* pOut) const
{
	pOut->DrawHexa(center ,FigGfxInfo,Selected);
}

bool Chexagon::IsInside(Point P)
{
	double A, A1, A2, A3, A4, A5, A6;
	Point P1h, P2h, P3h, P4h, P5h, P6h;
	P1h.x = center.x - (0.5 * 100);
	P1h.y = center.y + (sqrt(3) / 2) * 100;
	P2h.x = center.x + (0.5 * 100);
	P2h.y = center.y + (sqrt(3) / 2) * 100;
	P3h.x = center.x + 100;
	P3h.y = center.y;
	P4h.x = center.x - 100;
	P4h.y = center.y;
	P5h.x = center.x - (0.5 * 100);
	P5h.y = center.y - (sqrt(3) / 2) * 100;
	P6h.x = center.x + (0.5 * 100);
	P6h.y = center.y - (sqrt(3) / 2) * 100;
	A = ((3 * sqrt(3)) / 2) * pow(100, 2);
	A1 = (P1h.x * (P2h.y - P.y) + P2h.x * (P.y - P1h.y) + P.x * (P1h.y - P2h.y)) / 2.0;
	A2 = (P2h.x * (P3h.y - P.y) + P3h.x * (P.y - P2h.y) + P.x * (P2h.y - P3h.y)) / 2.0;
	A3 = (P3h.x * (P6h.y - P.y) + P6h.x * (P.y - P3h.y) + P.x * (P3h.y - P6h.y)) / 2.0;
	A4 = (P6h.x * (P5h.y - P.y) + P5h.x * (P.y - P6h.y) + P.x * (P6h.y - P5h.y)) / 2.0;
	A5 = (P5h.x * (P4h.y - P.y) + P4h.x * (P.y - P5h.y) + P.x * (P5h.y - P4h.y)) / 2.0;
	A6 = (P4h.x * (P1h.y - P.y) + P1h.x * (P.y - P4h.y) + P.x * (P4h.y - P1h.y)) / 2.0;
	if (abs(A) >= abs(A1) + abs(A2) + abs(A3) + abs(A4) + abs(A5) + abs(A6))
	{
		return true;
	}
	return false;
}
void Chexagon::Save(ofstream& outf)
{
	outf << "HEXA" << " " << ID << " " << center.x << " " << center.y << " " << setcolor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
		outf << setcolor(FigGfxInfo.FillClr) << endl;
	else
		outf << "non-filled" << endl;
}

void Chexagon::Load(ifstream& inf)
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

bool Chexagon::MoveFig(Point vec)
{
	center.x += vec.x;
	center.y += vec.y;



	return true;
}

Point Chexagon::GetCenter()
{
	return center;
}