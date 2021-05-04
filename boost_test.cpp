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
/*#ifndef __CONDITION_TEST__
#define __CONDITION_TEST__


#include <iostream>
#include <boost/thread.hpp>

boost::mutex m;
boost::condition_variable cond_var;

bool ready_status;

void shared_data_func() {
	std::cout << "Processing shared data." << std::endl;
}

void consumer_func() {
	std::cout << "Worker: Waiting for work." << std::endl;

	boost::unique_lock<boost::mutex> lck(m);
	cond_var.wait(lck, [] {return ready_status;});
	shared_data_func();
	std::cout << "Work done." << std::endl;
}

void producer_func() {
	boost::lock_guard<boost::mutex> lck(m);
	ready_status = true;
	std::cout << "Sender: Data is ready." << std::endl;
	cond_var.notify_one();
}

int main() {
	std::cout << std::endl;

	boost::thread t1(consumer_func);
	boost::thread t2(producer_func);

	t1.join();
	t2.join();

	std::cout << std::endl;
}

#endif*/

// deadline timer
/*#ifndef __DEADTIME_TEST__
#define __DEADTIME_TEST__

#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class printer
{
public:
	printer(boost::asio::io_context& io)
		: strand_(io),
		timer1_(io, boost::posix_time::seconds(1)),
		timer2_(io, boost::posix_time::seconds(1)),
		timer3_(io, boost::posix_time::seconds(1)),
		count_(0)
	{
		timer1_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&printer::print1, this)));
		timer2_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&printer::print2, this)));
		timer3_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&printer::print3, this)));
	}

	~printer()
	{
		std::cout << "Final count is " << count_ << std::endl;
	}

	void print1()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 1: " << count_ << std::endl;
			++count_;

			timer1_.expires_at(timer1_.expires_at() + boost::posix_time::seconds(1));

			timer1_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&printer::print1, this)));
		}
	}

	void print2()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 2: " << count_ << std::endl;
			++count_;

			timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));

			timer2_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&printer::print2, this)));
		}
	}

	void print3()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 3: " << count_ << std::endl;
			++count_;

			timer3_.expires_at(timer3_.expires_at() + boost::posix_time::seconds(1));

			timer3_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&printer::print3, this)));
		}
	}

private:
	boost::asio::io_context::strand strand_;

	boost::asio::deadline_timer timer1_;
	boost::asio::deadline_timer timer2_;
	boost::asio::deadline_timer timer3_;
	int count_;
};

int main()
{
	boost::asio::io_context io;
	printer p(io);
	boost::thread t(boost::bind(&boost::asio::io_context::run, &io));
	io.run();
	t.join();

	return 0;
}

#endif*/

// signal2
/*#ifndef __SIG2_TEST__
#define __SIG2_TEST__


#include <boost/signal.hpp> 
#include <iostream> 

void func1()
{
	std::cout << "Hello";
}

void func2()
{
	std::cout << ", world!" << std::endl;
}

void func3()
{
	std::cout << "I'm hys" << std::endl;
}

int main()
{
	boost::signal<void()> s;
	std::cout << "[slot connect]" << std::endl;
	s.connect(func1);
	s.connect(func2);
	s.connect(func3);

	std::cout << "slots num : " << s.num_slots() << std::endl; // 3


	std::cout << "[slot disconnect]" << std::endl;
	s.disconnect(func1);
	s.disconnect(func2);
	s.disconnect(func3);

	if (!s.empty()) {
		s();
		std::cout << "slots num : " << s.num_slots() << std::endl;
	}
	else {
		std::cout << "empty signal" << std::endl;
		std::cout << "slots num : " << s.num_slots() << std::endl; // 0
	}

	std::cout << "[slot connect]" << std::endl;
	s.connect(func1);
	s.connect(func2);
	s.connect(func3);

	if (!s.empty()) {
		s();  // hello, world!\n I'm hys
		std::cout << "slots num : " << s.num_slots() << std::endl; // 3
	}
	else
		std::cout << "empty signal" << std::endl;

	std::cout << "[slot all_disconnect]" << std::endl;
	s.disconnect_all_slots();
	std::cout << "slots num : " << s.num_slots() << std::endl; // 0
	s(); // disconnect -> not print
}


#endif*/

// asio
/*#ifndef __ASIO_TEST__
#define __ASIO_TEST__

#endif*/