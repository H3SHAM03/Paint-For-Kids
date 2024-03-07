#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H
#include "Action.h"
class AddHexaAction:public Action
{
protected:
	Point c; //center point of hexagon 
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();
	virtual void PlayRec();
};
#endif
