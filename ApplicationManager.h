#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/StartRec.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { MaxRecCount = 20 }; //Max no of recorded actions
private:
	int FigCount;		//Actual number of figures
	int RecActCount;		//Actual number of recorded figures
	bool FigListEmpty;
	bool RecListEmpty;
	bool IsRecording;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	color SelectedFigCol; //color of selected figure
	CFigure* SelectedFig; //Pointer to the selected figure	
	Action* RecList[MaxRecCount]; //List of recorded actions (Array of pointer)
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes 
	void SetSelectedFig(CFigure* S);
	CFigure* GetSelectedFig();
	void UnSelect();
	void EmptyRecList();
	void AddActionRec(Action* A);
	bool IsFigListEmpty();
	bool IsRecListEmpty();
	void SetIsRecording(bool);
	void Clear();
	void ExeRecList();
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFig();
	void clearFigures(); //clear all figures
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	
	void SaveAll(ofstream& outf);
	string clr_Str(color c);
	color str_clr(string c);

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif