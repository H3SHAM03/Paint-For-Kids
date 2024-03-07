#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "Action.h"
class AddTriAction:public Action
{
protected:
	Point p1, p2, p3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();
	virtual void PlayRec();
};
#endif
