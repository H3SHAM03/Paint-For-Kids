#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUA,		//Draw Square
	DRAW_TRIA,		//Draw Triangle
	DRAW_HEXA,		//Draw Hexagon
	DRAW_CIRC,		//Draw Circle

	SELECT_ONE,		//Select one Figure
	CHANGE_DRAW_CLR,//Change Drawing Color
	CHANGE_FILL_CLR,//Change Filling Color

	BLACK_CLR,		//
	YELLOW_CLR,		//
	ORANGE_CLR,		//
	RED_CLR,		//
	GREEN_CLR,		//
	BLUE_CLR,		//

	DELETE_ITM,		//Delete selected figure
	MOVE_ITM,		//Move selected figure
	UNDO,			//Undo last operation
	REDO,			//Redo the undone operation

	CLEAR,			//Clear All
	START_REC,		//Start Recording
	STOP_REC,		//Stop Recording
	PLAY,			//Play last Recording
	SAVE,			//
	LOAD,			//

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	FIGURES,
	COLORS,
	COLOREDFIGURES,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EXIT			//Exit

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif