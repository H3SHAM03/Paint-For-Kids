#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1500;
	UI.height = 768;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0,UI.width,UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAW;
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg"; 
	MenuItemImages[ITM_SQUA] = "images\\MenuItems\\Menu_Squa.jpg";
	MenuItemImages[ITM_TRIA] = "images\\MenuItems\\Menu_Tria.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Menu_Hexa.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_BCOLOR] = "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_RECORD] = "images\\MenuItems\\Menu_Start.jpg";
	MenuItemImages[ITM_STOP] = "images\\MenuItems\\Menu_Stop.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_GAMEMODE] = "images\\MenuItems\\Menu_GameMode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	ClearDrawArea();

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	ClearDrawArea();
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_FIGURES] = "images\\MenuItems\\Figures.jpg";
	MenuItemImages[ITM_COLORS] = "images\\MenuItems\\Colors.jpg";
	MenuItemImages[ITM_COLOREDFIGURES] = "images\\MenuItems\\ColoredFigures.jpg";
	MenuItemImages[ITM_DRAWMODE] = "images\\MenuItems\\Menu_DrawMode.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\Menu_Exit.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const  //Draw a rectangle
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

bool Output::isSquaOutofBounds(Point C) const
{
	int s = 100;
	Point P1h, P2h, P3h, P4h;
	P1h.y = C.y - 0.5 * s;
	P2h.y = C.y - 0.5 * s;
	P3h.y = C.y + 0.5 * s;
	P4h.y = C.y + 0.5 * s;
	if (P1h.y <= UI.ToolBarHeight || P2h.y <= UI.ToolBarHeight || P3h.y <= UI.ToolBarHeight || P4h.y <= UI.ToolBarHeight)
		return true;
	else
		return false;
}

bool Output::isHexaOutofBounds(Point C) const
{
	int s = 100;
	Point P1h, P2h, P3h, P4h, P5h, P6h;
	int x, y;
	P1h.y = C.y + (sqrt(3) / 2) * s;
	P2h.y = C.y + (sqrt(3) / 2) * s;
	P3h.y = C.y;
	P4h.y = C.y;
	P5h.y = C.y - (sqrt(3) / 2) * s;
	P6h.y = C.y - (sqrt(3) / 2) * s;
	if (P1h.y <= UI.ToolBarHeight || P2h.y <= UI.ToolBarHeight || P3h.y <= UI.ToolBarHeight || P4h.y <= UI.ToolBarHeight || P5h.y <= UI.ToolBarHeight || P6h.y <= UI.ToolBarHeight)
		return true;
	else
		return false;
}

bool Output::isCircOutofBounds(Point C, Point P) const
{
	int r = sqrt(pow((C.x - P.x), 2) + pow((C.y - P.y), 2));
	Point P1;
	P1.y = C.y - r;
	if (P1.y <= UI.ToolBarHeight)
		return true;
	else
		return false;
}

void Output::DrawSqua(Point C, GfxInfo SquaGfxInfo, bool selected) const  //Draw a square
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquaGfxInfo.FillClr);
	}
	else
		style = FRAME;


	int s = 100;
	Point P1h, P2h, P3h, P4h;
	P1h.x = C.x + (0.5 * s);
	P1h.y = C.y - 0.5 * s;
	P2h.x = C.x - (0.5 * s);
	P2h.y = C.y - 0.5 * s;
	P3h.x = C.x - 0.5 * s;
	P3h.y = C.y + 0.5 * s;
	P4h.x = C.x + 0.5 * s;
	P4h.y = C.y + 0.5 * s;
	int Px[] = { P1h.x,P2h.x,P3h.x,P4h.x };
	int Py[] = { P1h.y,P2h.y,P3h.y,P4h.y };
	pWind->DrawPolygon(Px, Py, 4, style);

}

void Output::DrawTria(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo, bool selected) const  //Draw a triangle
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriaGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawHexa(Point C, GfxInfo HexaGfxInfo, bool selected) const  //Draw a hexagon
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;


	int s = 100;
	Point P1h, P2h, P3h, P4h, P5h, P6h;
	P1h.x = C.x - (0.5 * s);
	P1h.y = C.y + (sqrt(3) / 2) * s;
	P2h.x = C.x + (0.5 * s);
	P2h.y = C.y + (sqrt(3) / 2) * s;
	P3h.x = C.x + s;
	P3h.y = C.y;
	P4h.x = C.x - s;
	P4h.y = C.y;
	P5h.x = C.x - (0.5 * s);
	P5h.y = C.y - (sqrt(3) / 2) * s;
	P6h.x = C.x + (0.5 * s);
	P6h.y = C.y - (sqrt(3) / 2) * s;
	int Px[] = { P1h.x,P2h.x,P3h.x,P6h.x,P5h.x,P4h.x };
	int Py[] = { P1h.y,P2h.y,P3h.y,P6h.y,P5h.y,P4h.y };
	pWind->DrawPolygon(Px, Py, 6, style);

}

void Output::DrawCirc(Point C, Point P, GfxInfo CircGfxInfo, bool selected) const  //Draw a circle
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;


	int r = sqrt(pow((C.x - P.x), 2) + pow((C.y - P.y), 2));
	pWind->DrawCircle(C.x, C.y, r, style);

}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

