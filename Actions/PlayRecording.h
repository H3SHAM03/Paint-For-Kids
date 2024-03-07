#ifndef PLAY_REC_ACTION_H
#define PLAY_REC_ACTION_H
#include "Action.h"
class PlayRecording:public Action
{
public:
	PlayRecording(ApplicationManager* pApp);
	virtual void PlayRec() {};
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
