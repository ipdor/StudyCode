#include "GameCmdRole.h"
#include "GameRole.h"
#include "msg.pb.h"
#include "GameMsg.h"
#include "GameProtocol.h"
#include <zinx.h>

GameCmdRole::GameCmdRole()
{
}


GameCmdRole::~GameCmdRole()
{
}

bool GameCmdRole::Init()
{
	return true;
}

UserData * GameCmdRole::ProcMsg(UserData & _poUserData)
{
	auto role_list = ZinxKernel::Zinx_GetAllRole();
	GET_REF2DATA(MultiMsg, input, _poUserData);

	for (auto single_msg : input.m_Msgs)
	{
		if (1 == dynamic_cast<pb::Cmd *> (single_msg->pMsg)->cmdid())
		{
			auto pMsg = new pb::Cmd();
			pMsg->set_cmdid(1);
			pMsg->set_req(dynamic_cast<pb::Cmd *>(single_msg->pMsg)->req());
			auto pRet = new GameMsg(GameMsg::MSG_TYPE_CMD, pMsg);
			std::string szResp;
			for (auto single : role_list)
			{
				auto pRole = dynamic_cast<GameRole *>(single);
				if (NULL != pRole)
				{
					szResp.append(pRole->szName);
					szResp.push_back('\n');
				}
			}
			pMsg->set_resp(szResp);
			ZinxKernel::Zinx_SendOut(*pRet, *m_proto);
		}
	}
	

	return nullptr;
}

void GameCmdRole::Fini()
{
}
