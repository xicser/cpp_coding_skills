#include <iostream>
#include "thread_pool.h"

using namespace std;

int main()
{
	ThreadPool pool(15);

	//�����߳�����
	while (1) {
		std::chrono::milliseconds dura(2000);
		std::this_thread::sleep_for(dura);
	}
}
