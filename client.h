#include"iostream"
#include <deque>
#include <thread>
#include <chrono>
using namespace std;

class client
{
public:
	void run();
	void waitCmd(); //�ȴ�����
	void receive(); //���շ�������Ϣ

	void send();//������Ϣ

	void addTask(int ta);//�������
private:
	deque<int>		m_taskArray; //�������
	thread*         m_thNetworkThread; //����Ϣ�߳�
};