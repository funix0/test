#include"iostream"
#include <deque>
#include <thread>
#include <chrono>
using namespace std;

class client
{
public:
	void run();
	void waitCmd(); //等待任务
	void receive(); //接收服务器消息

	void send();//发送消息

	void addTask(int ta);//添加任务
private:
	deque<int>		m_taskArray; //任务队列
	thread*         m_thNetworkThread; //收消息线程
};