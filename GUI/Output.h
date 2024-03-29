#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const; //Clears tool bar
	
	// -- Figures Drawing functions
	bool isSquaOutofBounds(Point C) const;
	bool isHexaOutofBounds(Point C) const;
	bool isCircOutofBounds(Point C, Point P) const;
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSqua(Point C, GfxInfo SquaGfxInfo, bool selected = false) const;  //Draw a square
	void DrawTria(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo, bool selected = false) const;  //Draw a triangle
	void DrawHexa(Point C, GfxInfo HexaGfxInfo, bool selected = false) const;  //Draw a hexagon
	void DrawCirc(Point C, Point P, GfxInfo CircGfxInfo, bool selected = false) const;  //Draw a circle

	
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif