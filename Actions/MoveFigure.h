#ifndef MOVE_FIGURE_ACTION_H
#define MOVE_FIGURE_ACTION_H
#include "Action.h"
class MoveFigure :public Action
{
private:
	Point vec;
public:
	MoveFigure(ApplicationManager* pApp);
	virtual void PlayRec();
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif