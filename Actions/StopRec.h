#ifndef STOP_REC_ACTION_H
#define STOP_REC_ACTION_H
#include "Action.h"

class StopRec:public Action
{
public:
	StopRec(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	virtual void PlayRec() {};
};
#endif
