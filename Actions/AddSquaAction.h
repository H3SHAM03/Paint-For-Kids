#ifndef ADD_SQUA_ACTION_H
#define ADD_SQUA_ACTION_H
#include "Action.h"
class AddSquaAction:public Action
{
protected:
	Point c; //center of square
	GfxInfo SquaGfxInfo;
public:
	AddSquaAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
	virtual void PlayRec();
};
#endif
