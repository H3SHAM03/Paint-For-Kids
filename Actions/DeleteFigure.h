#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H
#include "Action.h"
class DeleteFigure :public Action
{
public:
	DeleteFigure(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void PlayRec();
};
#endif