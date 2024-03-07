#include "SaveAction.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include <fstream>
SaveAction::SaveAction(ApplicationManager* pApp, int FigCount) :Action(pApp)
{
	nfg = FigCount;
}
void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("enter filename :");
	filename = pIn->GetSrting(pOut);
}
void SaveAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ofstream outf;
	outf.open(filename + ".txt");
	outf << pManager->clr_Str(UI.DrawColor) << " " << pManager->clr_Str(UI.FillColor) << endl;
	outf << nfg << endl;
	pManager->SaveAll(outf);
	pOut->ClearStatusBar();
	outf.close();
	pOut->PrintMessage("Saved Successfully");
}
