#include "CFigure.h"

CFigure::CFigure()
{
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

color CFigure::GetDrawCol() const
{
	return FigGfxInfo.DrawClr;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::setID(int d)
{
	ID = d;
}

int CFigure::getID() const
{
	return ID;
}
string CFigure::setcolor(color c)const
{
	if (c == RED)
		return "red";
	else if (c == BLACK)
		return "black";
	else if (c == GREEN)
		return "green";
	else if (c == BLUE)
		return "blue";
	else if (c == YELLOW)
		return "yellow";
	else if (c == ORANGE)
		return "orange";
}

color CFigure::getcolor(string c)const
{
	if (c == "black")
		return BLACK;
	else if (c == "green")
		return GREEN;
	else if (c == "blue")
		return BLUE;
	else if (c == "yellow")
		return YELLOW;
	else if (c == "red")
		return RED;
	else if (c == "orange")
		return ORANGE;
}
