#include "StopRec.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StopRec::StopRec(ApplicationManager* pApp) :Action(pApp)
{

}

void StopRec::ReadActionParameters()
{

}

void StopRec::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->SetIsRecording(false);
	pOut->PrintMessage("Stopped Recording Successfully");
}