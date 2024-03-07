#include "DeleteFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigure::DeleteFigure(ApplicationManager* pApp) :Action(pApp)
{

}

void DeleteFigure::ReadActionParameters()
{
	
}

void DeleteFigure::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedFig() == NULL)
	{
		pOut->PrintMessage("No selected Figure");
	}
	else
	{
		pManager->DeleteFig();
		pOut->ClearDrawArea();
		pOut->PrintMessage("Deleted Successfully");
	}
}

void DeleteFigure::PlayRec()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() == NULL)
	{
		pOut->PrintMessage("No selected Figure");
	}
	else
	{
		pManager->DeleteFig();
		pOut->ClearDrawArea();
		pOut->PrintMessage("Deleted Successfully");
	}
}