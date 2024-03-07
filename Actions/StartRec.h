#ifndef START_REC_ACTION_H
#define START_REC_ACTION_H
#include "Action.h"

class StartRec:public Action
{
public:
	StartRec(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void PlayRec() {};
};
#endif