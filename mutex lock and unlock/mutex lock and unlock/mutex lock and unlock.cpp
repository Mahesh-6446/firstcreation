#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int arr[10];
mutex m;
void fun1()
{
	//m.lock();
	lock_guard<mutex>lock(m);
	for (int i = 0;i < 10;i++)
	{
		arr[i] = i;
	}
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//m.unlock();
}
void fun2()
{ 
	//m.lock();
	lock_guard<mutex>lock2(m);  // TO AVOID THE DEAD LOCK IN PROGRAM
	for (int i = 0;i < 10;i++)   // WHAT IS DEAD LOCK , if we forget the unlock process in the program we can get RACE CONDITION
	{                             // SO we need to avoid dead lock we use the lock_guard
		arr[i] = i*10;

	}
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//m.unlock();
}
int main()
{
	thread t1(fun1);
	thread t2(fun2);
	t2.join();
	t1.join();
	
	
}