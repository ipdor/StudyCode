#pragma once
#include "GameRole.h"
#include "ZinxTimerDeliver.h"

// 机器人类  多重继承与 GameRole  和 TimerOutProc
class GameRobot :
	public GameRole, public TimerOutProc
{
public:
	GameRobot();
	virtual ~GameRobot();

	virtual bool Init() override;
	// 通过 TimerOutProc 继承
	virtual void Proc() override;
	virtual int GetTimerSec() override;


	void AutoAttack();
};

