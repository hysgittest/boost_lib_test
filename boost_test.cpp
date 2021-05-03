// smart_ptr
/*#ifndef __SMART_PTR_TEST__
#define __SMART_PTR_TEST__

#include <boost/scoped_ptr.hpp>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class ptr_test {
private:
	string str;
	int count;

public:
	ptr_test() {
		str = "null";
		count = 0;
	}

	ptr_test(string _str) {
		this->str = _str;
	}

	~ptr_test() { cout << "make destructor" << endl; }

	void print__ptr_info();
};

void ptr_test::print__ptr_info() {
	cout << "ptr : " << str << endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "USAGE : " << argv[0] << " <PTR>" << endl;

		exit(0);
	}

	if ((strcmp("scoped_ptr", argv[1])) == 0) {
		boost::scoped_ptr<ptr_test> scp(new ptr_test(argv[1]));

		scp->print__ptr_info();
	}
	else if ((strcmp("unique_ptr", argv[1])) == 0) {
		unique_ptr<ptr_test> unp(new ptr_test(argv[1]));

		unp->print__ptr_info();
	}
	else if ((strcmp("shared_ptr", argv[1])) == 0) {
		boost::shared_ptr<ptr_test> shp(new ptr_test(argv[1]));

		shp->print__ptr_info();
		cout << "now owner count : " << shp.use_count() << endl;

		auto shp1 = shp;
		cout << "now owner count : " << shp.use_count() << endl;

		shp1.reset();
		cout << "now owner count : " << shp.use_count() << endl;
	}
}
#endif*/

// chrono
/*#ifndef __CHRONO_TEST__
#define __CHRONO_TEST__

#include <iostream>
#include <boost/chrono.hpp>
#include <ratio>

int main() {
	boost::chrono::system_clock::time_point start_time = boost::chrono::system_clock::now();
	std::cout << "start time : " << start_time.time_since_epoch().count() << std::endl;


	int temp = 0;
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 100000; j++) {
			temp++;
		}
	}

	boost::chrono::system_clock::time_point end_time = boost::chrono::system_clock::now();
	std::cout << "end time : " << end_time.time_since_epoch().count() << std::endl;

	boost::chrono::duration<long long, boost::nano> nsec = boost::chrono::duration_cast<boost::chrono::nanoseconds>(end_time - start_time);
	std::cout << "nano end time : " << nsec.count() << std::endl;

	boost::chrono::duration<long long, boost::micro> usec = boost::chrono::duration_cast<boost::chrono::microseconds>(end_time - start_time);
	std::cout << "micro end time : " << usec.count() << std::endl;

	boost::chrono::duration<long long, boost::milli> msec = boost::chrono::duration_cast<boost::chrono::milliseconds>(end_time - start_time);
	std::cout << "miili end time : " << msec.count() << std::endl;

	boost::chrono::duration<long long> sec = boost::chrono::duration_cast<boost::chrono::seconds>(end_time - start_time);
	std::cout << "sec end time : " << sec.count() << std::endl;

	boost::chrono::duration<int, boost::ratio<60>> min = boost::chrono::duration_cast<boost::chrono::minutes>(end_time - start_time);
	std::cout << "min end time : " << min.count() << std::endl;

	boost::chrono::duration<int, boost::ratio<3600>> hour = boost::chrono::duration_cast<boost::chrono::hours>(end_time - start_time);
	std::cout << "hour end time : " << hour.count() << std::endl;
}


#endif*/

// timer
/*#ifndef __TIMER_TEST__
#define __TIMER_TEST__

#include <boost/timer/timer.hpp>

#include <iostream>
#include <cmath>
using namespace boost::timer;
int main()
{
	cpu_timer timer;
	auto_cpu_timer auto_timer;

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';

	timer.stop();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';

	timer.resume();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';

	timer.stop();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';

	timer.start();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << auto_timer.format() << '\n';

	auto_timer.stop();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << auto_timer.format() << '\n';
}

#endif*/

// function && bind
/*#ifndef __FUNCTION__TEST__
#define __FUNCTION__TEST__


#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>

int add(int a, int b) {
	return a + b;
}

int main() {
	boost::function<int(int, int)> f = boost::bind(add, _1, _2);
	boost::function<int(int)> f2 = boost::bind(add, _1, 10);
	boost::function<int(int, int)> f3 = boost::bind(add, 3, 4);
	std::cout << f(1, 2) << std::endl;	// 3
	std::cout << f2(2) << std::endl;	// 12
	std::cout << f3(1, 2) << std::endl;	// 7

	return 0;
}


#endif*/

// thread
/*#ifndef __THREAD_TEST__
#define __THREAD_TEST__

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

class thread_test
{
public:
	void thread_memfunc_1()
	{
		while (true)
		{
			cout << "first" << endl;
			boost::this_thread::sleep(boost::posix_time::millisec(1000));
		}
	}
	void thread_memfunc_2(string str)
	{
		while (true)
		{
			cout << str << endl;
			boost::this_thread::sleep(boost::posix_time::millisec(1000));
		}
	}

	void thread_memfunc_3(string str, int num2)
	{
		while (true)
		{
			cout << str << endl;
			boost::this_thread::sleep(boost::posix_time::millisec(1000));
		}
	}
};

int main()
{
	thread_test io;

	boost::thread th1 = boost::thread(boost::bind(&thread_test::thread_memfunc_1, &io));
	boost::thread th2 = boost::thread(boost::bind(&thread_test::thread_memfunc_2, &io, "second"));
	boost::thread th3 = boost::thread(boost::bind(&thread_test::thread_memfunc_3, &io, "third", NULL));

	th1.join();
	th2.join();
	th3.join();

	//th1.detach();
	//th2.detach();
	//th3.detach();

	return 0;
}


#endif*/

// mutex
/*#ifndef __MUTEX__TEST__
#define __MUTEX__TEST__

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

int value;
boost::mutex mutex_test;

void increase_value()
{
	// 뮤텍스를 이용하여 동기화
	mutex_test.lock();
	value++;

	cout << "thread[" << value << "] : ";

	int count = 0;
	for (int i = 0; i < value; i++) {
		cout << count << " ";
		count++;
	}
	cout << endl;
	mutex_test.unlock();
}

int main()
{
	value = 0;
	boost::thread t[10];

	for (auto i = 0; i < 10; i++)
	{
		t[i] = boost::thread(increase_value);
	}

	for (int i = 0; i < 10; i++)
	{
		t[i].join();
	}
}

#endif*/

// condition variable
#ifndef __CONDITION_TEST__
#define __CONDITION_TEST__


#include <boost/chrono.hpp>
#include <iostream>
#include <boost/thread.hpp>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void producer(queue<string>* downloaded_pages, boost::mutex* m,
	int index, boost::condition_variable* cv) {
	for (int i = 0; i < 5; i++) {
		// 웹사이트를 다운로드 하는데 걸리는 시간이라 생각하면 된다.
		// 각 쓰레드 별로 다운로드 하는데 걸리는 시간이 다르다.
		boost::this_thread::sleep_for(boost::chrono::milliseconds(100 * index));
		string content = "웹사이트 : " + to_string(i) + " from thread(" +
			std::to_string(index) + ")\n";

		// data 는 쓰레드 사이에서 공유되므로 critical section 에 넣어야 한다.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		// consumer 에게 content 가 준비되었음을 알린다.
		cv->notify_one();
	}
}

void consumer(queue<string>* downloaded_pages, boost::mutex* m,
	int* num_processed, boost::condition_variable* cv) {
	while (*num_processed < 25) {
		boost::unique_lock<boost::mutex> lk(*m);

		cv->wait(
			lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; });

		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		// 맨 앞의 페이지를 읽고 대기 목록에서 제거한다.
		string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		// content 를 처리한다.
		cout << content;
		boost::this_thread::sleep_for(boost::chrono::milliseconds(80));
	}
}

int main() {
	// 현재 다운로드한 페이지들 리스트로, 아직 처리되지 않은 것들이다.
	queue<std::string> downloaded_pages;
	boost::mutex m;
	boost::condition_variable cv;

	vector<boost::thread> producers;
	for (int i = 0; i < 5; i++) {
		producers.push_back(
			boost::thread(producer, &downloaded_pages, &m, i + 1, &cv));
	}

	int num_processed = 0;
	vector<boost::thread> consumers;
	for (int i = 0; i < 3; i++) {
		consumers.push_back(
			boost::thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
	}

	for (int i = 0; i < 5; i++) {
		producers[i].join();
	}

	// 나머지 자고 있는 쓰레드들을 모두 깨운다.
	cv.notify_all();

	for (int i = 0; i < 3; i++) {
		consumers[i].join();
	}
}


#endif