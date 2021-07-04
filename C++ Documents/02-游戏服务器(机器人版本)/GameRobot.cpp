#include "GameRobot.h"
#include "WorldManager.h"
#include "zinx.h"
#include "GameMsg.h"
#include "GameProtocol.h"
#include "msg.pb.h"

GameRobot::GameRobot()
{
}


GameRobot::~GameRobot()
{
}

bool GameRobot::Init()
{
	
	//ID������
	this->mPlayerId = 10000 + smRoleCount++;
	//this->mPlayerName = "Player_" + to_string(this->mPlayerId);
	this->mPlayerName = "Tom Tom";

	//���������ֵ
	x = 70;
	y = 0;
	z = 70;
	v = 0;
	//��Ѫ��1000
	hp = 1000;

	//��ȡ�ڶ�������
	mCurrentWorld = WorldManager::GetInstance().GetWorld(2);

	//����ǰ�����ӵ������ͼ��
	//AOI_World::GetWorld()->AddPlayer(this);
	mCurrentWorld->AddPlayer(this);

	auto players = mCurrentWorld->GetSurPlayers(this);

	for (auto r : players)
	{
		//�ж��Ƿ�Ϊ�Լ�
		if (this == r)
		{
			continue;
		}

		auto role = dynamic_cast<GameRole*>(r);

		//��ǰ��Ҵ���λ����Ϣ
		auto pMsg = MakeInitPosBroadcast();
		if(role->mProtocol != NULL)
		SendData(pMsg, role->mProtocol);

		//pMsg = role->MakeInitPosBroadcast();
		//SendData(*pMsg, *mProtocol);

	}

	ZinxTimerDeliver::GetInstance().RegisterProcObject(*this);

	return true;
}

void GameRobot::Proc()
{//�Զ�����
	AutoAttack();
// �Զ��ƶ�
//
}

int GameRobot::GetTimerSec()
{
	return 2;
}

void GameRobot::AutoAttack()
{
	//�Զ���������
	
	// 1 ��ȡ��Χ���
	auto sround = mCurrentWorld->GetSurPlayers(this);
	for (auto it : sround)
	{
		GameRole* prole = dynamic_cast<GameRole*>(it);
		if (prole != NULL)
		{
			// 2 ���幥�����ݰ�
			auto p = new pb::SkillTrigger();

			p->set_pid(mPlayerId);// ��ɫ��id
			p->set_skillid(1);// ����ID
			static int count = 1;
			p->set_bulletid(count++);// �ӵ�ID
			pb::Position* pos = p->mutable_p();// λ����Ϣ 
			pos->set_x(x);
			pos->set_y(y);
			pos->set_z(z);
			pos->set_v(v);
			pos->set_bloodvalue(hp);
			pb::Velocity* pvel = p->mutable_v();//
			pvel->set_x(x);
			pvel->set_y(y);
			pvel->set_z(z);
			//���л�����
			auto single = new GameSingleTLV(GameSingleTLV::GAME_MSG_SKILL_BROAD, p);

			auto *retMsg = new GameMsg;
			retMsg->m_MsgList.push_back(single);
			
			// 3 �㲥�������ݰ�
			SendData(retMsg, prole->mProtocol);
			if (prole->mProtocol == NULL)
			{
				delete retMsg;
			}
		}
	}
	

}
