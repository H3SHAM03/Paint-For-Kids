#include "AddCircAction.h"
#include "../Figures/Ccircle.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
AddCircAction::AddCircAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at point for center");

	//Read "center" of circle and store in point c
	pIn->GetPointClicked(c.x, c.y);

	pOut->PrintMessage("New Circle: Click at second point for raduis");

	//Read point "onCircle" and store in point on
	pIn->GetPointClicked(on.x,on.y);

	CIRCGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CIRCGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CIRCGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	 
	//Create a circle with the parameters read from the user
	Ccircle* C = new Ccircle(c, on, CIRCGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);

}

void AddCircAction::PlayRec()
{
	//Create a circle with the parameters read from the user
	Ccircle* C = new Ccircle(c, on, CIRCGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}
