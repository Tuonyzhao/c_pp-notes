#include<iostream>
#include<iterator>
#include<string>
using namespace std;

int main(int argc,char **argv)
{
	string str;//默认初始化，str是一个空串
	for(auto i=1;i!=argc;i++)
	{
		str+=argv[i];
	}
	cout<<argc<<endl;
	cout<<str<<endl;
	return 0;
}
