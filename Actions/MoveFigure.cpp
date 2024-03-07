#include "MoveFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

void MoveFigure::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* pFig = pManager->GetSelectedFig();
	if (pFig == NULL)
	{
		pOut->PrintMessage("no selected figure to move");
	}
	else
	{
		Point p1;
		pOut->PrintMessage("Click on the new location of the selected figure");
		p1 = pFig->GetCenter();
		if (pFig->IsInside(p1))
		{
			Point p2;
			pIn->GetPointClicked(p2.x, p2.y);
			vec.x = p2.x - p1.x;
			vec.y = p2.y - p1.y;
		}
	}
}

void MoveFigure::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* pFig = pManager->GetSelectedFig();
	if (pFig != NULL)
	{
		pFig->MoveFig(vec);
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pManager->UnSelect();
		pOut->PrintMessage("Figure Moved Successfully");
	}
}

MoveFigure::MoveFigure(ApplicationManager* pApp) :Action(pApp)
{
}

void MoveFigure::PlayRec()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* pFig = pManager->GetSelectedFig();
	if (pFig != NULL)
	{
		pFig->MoveFig(vec);
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pManager->UnSelect();
		pOut->PrintMessage("Figure Moved Successfully");
	}
}