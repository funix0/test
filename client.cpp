#include "client.h"

void client::run()
{
	//创建收消息线程
	if (m_thNetworkThread == NULL)
	{
		m_thNetworkThread = new thread(&client::receive, this);
	}
	m_thNetworkThread->detach();
	cout << "client run" << endl;

	waitCmd();
}

void client::waitCmd()
{
	while (true)
	{
		int cmdName;
		cout << "请输入您的命令： ";
		cin >> cmdName;

		addTask(cmdName);
	}

}

void client::receive()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(3));

		if (m_taskArray.size() > 0)
		{
			std::cout << "\n收到服务器应答:" << m_taskArray.front() << endl;
			m_taskArray.pop_front();
		}

	}
}

void client::send()
{

}

void client::addTask(int ta)
{
	m_taskArray.push_back(ta);
}
