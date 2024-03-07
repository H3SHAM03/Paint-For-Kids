#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H
#include "Action.h"
class AddCircAction:public Action
{
protected:
	Point c,on; //center point and onCircle point 
	GfxInfo CIRCGfxInfo; 
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();
	virtual void PlayRec();

};
#endif
