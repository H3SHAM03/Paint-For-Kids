#include "LoadAction.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../Figures/CFigure.h"
#include "../Figures/Chexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/Ccircle.h"
#include "../Figures/Ctriangle.h"
#include "../Figures/Csquare.h"
#include <fstream>
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("enter filename need to be loaded :");
	filename = pIn->GetSrting(pOut);
}

void LoadAction::Re_ReadActionParameters()    //used for retry entering filename
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("try to enter file name again:");
	filename = pIn->GetSrting(pOut);
}

void LoadAction::Execute()
{
	string dc, fc, s;
	int count, attempts;    //"count" to get number of figures need to be loaded
	attempts = 0;     //"attempts to set number of times to retry loading file

	ifstream inf;


	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	inf.open(filename + ".txt");

	while (inf.is_open() == false && attempts != 1)
	{
		Re_ReadActionParameters();
		inf.open(filename + ".txt");
		attempts++;
	}
	if (inf.is_open() == true) {
		pOut->ClearDrawArea();
		inf >> dc;  UI.DrawColor = pManager->str_clr(dc);
		inf >> fc;  UI.FillColor = pManager->str_clr(fc);
		pManager->clearFigures();
		inf >> count;
		CFigure* f = NULL;
		for (int i = 0; i < count; i++)       //checking type of figure to allocate it to load its data in
		{
			inf >> s;
			if (s == "TRIA")
				f = new Ctriangle;
			else if (s == "RECT")
				f = new CRectangle;
			else if (s == "CIRC")
				f = new Ccircle;
			else if (s == "HEXA")
				f = new Chexagon;
			else if (s == "SQUA")
				f = new Csquare;
			f->Load(inf);
			pManager->AddFigure(f);
		}
		pManager->UpdateInterface();
		pOut->ClearStatusBar();
		pOut->PrintMessage("Loaded Successfully");
	}
	else
		pOut->PrintMessage("failed to load the file needed");
}
