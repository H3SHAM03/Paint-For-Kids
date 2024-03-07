#include "StartRec.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StartRec::StartRec(ApplicationManager* pApp) :Action(pApp)
{

}


void StartRec::ReadActionParameters()
{

}

void StartRec::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->IsFigListEmpty() == false)
	{
		pOut->PrintMessage("You need to clear to start recording");
	}
	else
	{
		pOut->PrintMessage("Recording Started Successfully");
		pManager->EmptyRecList();
		pManager->SetIsRecording(true);
	}
}
