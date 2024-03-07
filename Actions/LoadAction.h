#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H
#include "Action.h"
#include <string>
#include <fstream>
class LoadAction :public Action
{
private:
	string filename;
	int noFig;      //number of figures to use it in loop of load functions
public:

	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void PlayRec() {};
	void Re_ReadActionParameters();
};
#endif
