#pragma once
#include "GameRole.h"
#include "ZinxTimerDeliver.h"

// ��������  ���ؼ̳��� GameRole  �� TimerOutProc
class GameRobot :
	public GameRole, public TimerOutProc
{
public:
	GameRobot();
	virtual ~GameRobot();

	virtual bool Init() override;
	// ͨ�� TimerOutProc �̳�
	virtual void Proc() override;
	virtual int GetTimerSec() override;


	void AutoAttack();
};

