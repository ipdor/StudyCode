#include "GameOpt.h"

class TcpClient :public Ichannel {
	int m_fd = -1;
	// Í¨¹ý Ichannel ¼Ì³Ð
	virtual bool Init() override
	{
		m_fd = socket(AF_INET, SOCK_STREAM, 0);
		struct sockaddr_in server;
		inet_aton("192.168.64.146", &(server.sin_addr));
		server.sin_family = AF_INET;
		server.sin_port = htons(9988);
		connect(m_fd, (sockaddr*)(&server), sizeof(server));

		return true;
	}
	virtual bool ReadFd(std::string & _input) override
	{
		char buff[2048];
		auto len = recv(m_fd, buff, sizeof(buff), 0);
		_input.assign(buff, len);
		return true;
	}
	virtual bool WriteFd(std::string & _output) override
	{
		for (auto letter : _output)
		{
			send(m_fd, &letter, 1);
		}
		return true;
	}
	virtual void Fini() override
	{
	}
	virtual int GetFd() override
	{
		return 0;
	}
	virtual std::string GetChannelInfo() override
	{
		return std::string();
	}
	virtual AZinxHandler * GetInputNextStage(BytesMsg & _oInput) override
	{
		return nullptr;
	}
};

std::string GameOpt::GetAllPlayerName()
{

	return std::string();
}

GameOpt::GameOpt()
{
}


GameOpt::~GameOpt()
{
}
