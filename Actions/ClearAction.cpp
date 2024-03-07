#include"ClearAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ClearAction::ClearAction(ApplicationManager* pApp) : Action(pApp)
{}

void ClearAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Clear Drawing Area, click on the icon again to clear.");
	confirm = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void ClearAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	

	// Deleting all figures
	pManager->Clear();
	pOut->ClearDrawArea();
	pOut->PrintMessage("Cleared Successfully");
	

	//SaveAction save(pManager);
	//save.saveForUndo();
}