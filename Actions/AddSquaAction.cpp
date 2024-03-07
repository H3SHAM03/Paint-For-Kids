#include "AddSquaAction.h"
#include "../Figures/Csquare.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
AddSquaAction::AddSquaAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddSquaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");

	//Read center of square 
	pIn->GetPointClicked(c.x,c.y);

	SquaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddSquaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	Csquare* S = new Csquare(c, SquaGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(S);
}

void AddSquaAction::PlayRec()
{
	//Create a square with the parameters read from the user
	Csquare* S = new Csquare(c, SquaGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(S);
}