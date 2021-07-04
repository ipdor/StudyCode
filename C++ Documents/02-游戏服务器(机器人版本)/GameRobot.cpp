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
	
	//ID和名字
	this->mPlayerId = 10000 + smRoleCount++;
	//this->mPlayerName = "Player_" + to_string(this->mPlayerId);
	this->mPlayerName = "Tom Tom";

	//坐标随机赋值
	x = 70;
	y = 0;
	z = 70;
	v = 0;
	//满血是1000
	hp = 1000;

	//获取第二个场景
	mCurrentWorld = WorldManager::GetInstance().GetWorld(2);

	//将当前玩家添加到世界地图中
	//AOI_World::GetWorld()->AddPlayer(this);
	mCurrentWorld->AddPlayer(this);

	auto players = mCurrentWorld->GetSurPlayers(this);

	for (auto r : players)
	{
		//判断是否为自己
		if (this == r)
		{
			continue;
		}

		auto role = dynamic_cast<GameRole*>(r);

		//当前玩家创建位置消息
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
{//自动攻击
	AutoAttack();
// 自动移动
//
}

int GameRobot::GetTimerSec()
{
	return 2;
}

void GameRobot::AutoAttack()
{
	//自动攻击函数
	
	// 1 获取周围玩家
	auto sround = mCurrentWorld->GetSurPlayers(this);
	for (auto it : sround)
	{
		GameRole* prole = dynamic_cast<GameRole*>(it);
		if (prole != NULL)
		{
			// 2 定义攻击数据包
			auto p = new pb::SkillTrigger();

			p->set_pid(mPlayerId);// 角色的id
			p->set_skillid(1);// 技能ID
			static int count = 1;
			p->set_bulletid(count++);// 子弹ID
			pb::Position* pos = p->mutable_p();// 位置信息 
			pos->set_x(x);
			pos->set_y(y);
			pos->set_z(z);
			pos->set_v(v);
			pos->set_bloodvalue(hp);
			pb::Velocity* pvel = p->mutable_v();//
			pvel->set_x(x);
			pvel->set_y(y);
			pvel->set_z(z);
			//序列化对象
			auto single = new GameSingleTLV(GameSingleTLV::GAME_MSG_SKILL_BROAD, p);

			auto *retMsg = new GameMsg;
			retMsg->m_MsgList.push_back(single);
			
			// 3 广播攻击数据包
			SendData(retMsg, prole->mProtocol);
			if (prole->mProtocol == NULL)
			{
				delete retMsg;
			}
		}
	}
	

}
