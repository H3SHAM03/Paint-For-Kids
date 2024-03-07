#include "Select.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{

}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select A Figure By clicking inside it");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();
	if(pManager->GetFigure(P.x, P.y)!=NULL)
	{
		pManager->SetSelectedFig(pManager->GetFigure(P.x, P.y));
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Figure Selected Successfully");
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pManager->UnSelect();
		pOut->PrintMessage("No selected Figure");
	}
}

void Select::PlayRec()
{
	if (pManager->GetFigure(P.x, P.y) != NULL)
	{
		pManager->SetSelectedFig(pManager->GetFigure(P.x, P.y));
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Figure Selected Successfully");
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pManager->UnSelect();
		pOut->PrintMessage("No selected Figure");
	}
}