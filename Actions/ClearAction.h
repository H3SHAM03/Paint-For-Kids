#ifndef CLEAR_H
#define CLEAR_H

#include "Action.h"

//Clear action class
class ClearAction : public Action
{
private:
	ActionType confirm;	//An ActionType variable to act as a confirmation for the action
public:
	ClearAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() ;
	virtual void Execute() ;
	virtual void PlayRec() {};
};

#endif

