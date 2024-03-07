#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H
#include "Action.h"
#include <string>
#include <fstream>
class SaveAction :public Action
{
private:
	string filename;
	int nfg;     //variable to put number of figures  
public:

	SaveAction(ApplicationManager* pApp, int FigCount);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void PlayRec() {};
};
#endif

