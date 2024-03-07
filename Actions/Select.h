#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H
#include "Action.h"
class Select:public Action
{
protected:
	Point P;
public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void PlayRec();
};
#endif
