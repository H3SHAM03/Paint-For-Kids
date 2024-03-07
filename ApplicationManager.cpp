#include "ApplicationManager.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddCircAction.h"
#include "Actions/AddHexaAction.h"
#include "Actions/AddSquaAction.h"
#include "Actions/AddTriAction.h"
#include "Actions/Select.h"
#include "Actions/ClearAction.h"
#include "Actions/DeleteFigure.h"
#include "Actions/MoveFigure.h"
#include "Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include "Actions/StartRec.h"
#include "Actions/StopRec.h"
#include "Actions/PlayRecording.h"
#include <fstream>
#include <Windows.h>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	FigCount = 0;
	RecActCount = 0;
	FigListEmpty = true;
	RecListEmpty = true;
	IsRecording = false;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
	}
	for (int i = 0; i < MaxRecCount; i++)
	{
		RecList[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			PlaySoundA("Sounds/Rectangle.WAV", NULL, SND_ASYNC);
			break;

		case DRAW_SQUA:
			pAct = new AddSquaAction(this);
			PlaySoundA("Sounds/Square.WAV", NULL, SND_ASYNC);
			break;


		case DRAW_TRIA:
			pAct = new AddTriAction(this);
			PlaySoundA("Sounds/Triangle.WAV", NULL, SND_ASYNC);
			break;

		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			PlaySoundA("Sounds/Hexagon.WAV", NULL, SND_ASYNC);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			PlaySoundA("Sounds/Circle.WAV", NULL, SND_ASYNC);
			break;

		case SELECT_ONE:
			pAct = new Select(this);
			break;

		case CLEAR:
			pAct = new ClearAction(this);
			break;

		case DELETE_ITM:
			pAct = new DeleteFigure(this);
			break;

		case MOVE_ITM:
			pAct = new MoveFigure(this);
			break;
		case SAVE:
			pAct = new SaveAction(this, FigCount);
			break;

		case LOAD:
				pAct = new LoadAction(this);
			break;

		case START_REC:
			if (IsRecording)
			{
				pOut->PrintMessage("You are already Recording");
			}
			else
			{
				if (RecActCount == 20)
				{
					pOut->PrintMessage("Recording Memory is full, please Clear All to start a new Recording");
				}
				else
					pAct = new StartRec(this);
			}
			break;

		case STOP_REC:
			if (IsRecording)
			{
				pAct = new StopRec(this);
			}
			else
			{
				pOut->PrintMessage("You need to start recording to stop it");
			}
			break;

		case PLAY:
			if (IsRecording)
			{
				pOut->PrintMessage("Recording in progress, please stop recording to play it");
			}
			else
				if (RecActCount == 0)
				{
					pOut->PrintMessage("No Recording to play");
				}
				else
					pAct = new PlayRecording(this);
			break;

		case EXIT:
			Clear();
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		if (IsRecording)
		{
			if (ActType != SAVE && ActType != LOAD && ActType != START_REC && ActType != PLAY && ActType!=TO_PLAY)
				AddActionRec(pAct);
			else
			{
				if (ActType != START_REC)
				{
					SetIsRecording(false);
					pOut->PrintMessage("Recording Stopped due to wrong input");
				}
			}
		}
		if (IsRecording==false)
			delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
		if (RecActCount == MaxRecCount)
		{
			SetIsRecording(false);
		}
	}
}

void ApplicationManager::SetSelectedFig(CFigure* S)
{
	UnSelect();
	SelectedFig = S;
	SelectedFigCol = SelectedFig->GetDrawCol();
	SelectedFig->ChngDrawClr(UI.HighlightColor);
	SelectedFig->SetSelected(true);
}

void ApplicationManager::UnSelect()
{
	if (SelectedFig != NULL)
	{
		SelectedFig->ChngDrawClr(SelectedFigCol);
		SelectedFig->SetSelected(false);
		SelectedFig = NULL;
	}
}

CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}

void ApplicationManager::EmptyRecList()
{
	for (int i = 0; i < RecActCount; i++)
	{
		delete RecList[i];
		RecList[i] = NULL;
	}
	RecActCount = 0;
}


bool ApplicationManager::IsFigListEmpty()
{
	for (int i = 0; i < MaxFigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			FigListEmpty = false;
			return false;
		}
	}
	FigListEmpty=true;
	return true;
}

bool ApplicationManager::IsRecListEmpty()
{
	for (int i = 0; i < MaxRecCount; i++)
	{
		if (RecList[i] != NULL)
		{
			RecListEmpty = false;
			return false;
		}
	}
	RecListEmpty = true;
	return true;
}

void ApplicationManager::AddActionRec(Action* A)
{
	if (IsRecording)
	{
		if (RecActCount < MaxRecCount)
		{
			RecList[RecActCount++] = A;
			if (RecActCount == MaxRecCount)
			{
				pOut->PrintMessage("Recording Stopped due to exceeded memory");
			}
		}
	}
}

void ApplicationManager::SaveAll(ofstream& outf)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->setID(i + 1);
		FigList[i]->Save(outf);
	}

}

string ApplicationManager::clr_Str(color c)
{
	if (c == RED)
		return "red";
	else if (c == BLACK)
		return "black";
	else if (c == GREEN)
		return "green";
	else if (c == BLUE)
		return "blue";
	else if (c == YELLOW)
		return "yellow";
	else if (c == ORANGE)
		return "orange";
}

color ApplicationManager::str_clr(string c)
{
	if (c == "black")
		return BLACK;
	else if (c == "green")
		return GREEN;
	else if (c == "blue")
		return BLUE;
	else if (c == "yellow")
		return YELLOW;
	else if (c == "red")
		return RED;
	else if (c == "orange")
		return ORANGE;
}

void ApplicationManager::SetIsRecording(bool b)
{
	IsRecording = b;
}

void ApplicationManager::ExeRecList()
{
	for (int i = 0; i < RecActCount; i++)
	{
		RecList[i]->PlayRec();
		UpdateInterface();
		Sleep(1000);
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		FigList[FigCount-1]->setID(FigCount);
	}
}

void ApplicationManager::DeleteFig()
{
	int c = SelectedFig->getID() - 1;
			delete FigList[c];
			FigList[c] = NULL;
			SelectedFig = NULL;
			FigCount--;
	for (c; c < FigCount; c++)
	{
		FigList[c] = FigList[c + 1];
		FigList[c + 1] = NULL;
		FigList[c]->setID(c+1);
	}
}

void ApplicationManager::clearFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}

void ApplicationManager::Clear()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	EmptyRecList();
	IsRecording = false;
	IsRecListEmpty();
	IsFigListEmpty();
}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	Point P; P.x = x; P.y = y;
	for (int i = FigCount-1; i >= 0; i--)
	{
		if (FigList[i]->IsInside(P))
		{
			return FigList[i];
		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < RecActCount; i++)
		delete RecList[i];
	delete pIn;
	delete pOut;
}
