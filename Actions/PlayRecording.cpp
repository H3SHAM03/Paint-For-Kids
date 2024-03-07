#include "PlayRecording.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PlayRecording::PlayRecording(ApplicationManager* pApp) :Action(pApp)
{

}

void PlayRecording::ReadActionParameters()
{

}

void PlayRecording::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->clearFigures();
	pOut->ClearDrawArea();
	pOut->PrintMessage("Recording Playing");
	pManager->ExeRecList();
	pOut->PrintMessage("Recording Played");
}