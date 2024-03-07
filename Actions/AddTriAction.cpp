#include "AddTriAction.h"
#include "../Figures/Ctriangle.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
AddTriAction::AddTriAction(ApplicationManager* pApp):Action(pApp)
{

}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New triangle: Click at first point");

	//Read first triangle point 
	pIn->GetPointClicked(p1.x, p1.y);

	pOut->PrintMessage("New triangle: Click at second point");

	//Read second triangle point 
	pIn->GetPointClicked(p2.x, p2.y);

	pOut->PrintMessage("New triangle: Click at third point");

	//Read third triangle point 
	pIn->GetPointClicked(p3.x, p3.y);

	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	Ctriangle* T = new Ctriangle(p1,p2,p3,TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}

void AddTriAction::PlayRec()
{
	//Create a triangle with the parameters read from the user
	Ctriangle* T = new Ctriangle(p1, p2, p3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}