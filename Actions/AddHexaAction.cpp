#include "AddHexaAction.h"
#include "../Figures/Chexagon.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
AddHexaAction::AddHexaAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddHexaAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center of it");

	//Read center of hexagon and store it
	pIn->GetPointClicked(c.x, c.y);

	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	Chexagon* H = new Chexagon(c,HexaGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}

void AddHexaAction::PlayRec()
{
	//Create a Hexagon with the parameters read from the user
	Chexagon* H = new Chexagon(c, HexaGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}