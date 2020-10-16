#include<iostream>

using namespace std;

int main()
{
	int i=2;
	const int &r1=i;
	const int &r2=2;
	const int &r3=r1*2;
	int &r4=r1*2;//错误，试图让一个非常量引用指向一个常量对象
}
