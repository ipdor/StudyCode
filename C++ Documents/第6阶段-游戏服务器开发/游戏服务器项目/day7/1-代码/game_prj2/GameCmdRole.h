#pragma once
#include <zinx.h>

class GameProtocol;
class GameCmdRole :
	public Irole
{
public:
	GameProtocol *m_proto = NULL;
	GameCmdRole();
	virtual ~GameCmdRole();

	// Í¨¹ý Irole ¼Ì³Ð
	virtual bool Init() override;
	virtual UserData * ProcMsg(UserData & _poUserData) override;
	virtual void Fini() override;
};

