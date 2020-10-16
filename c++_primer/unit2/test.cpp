#include<iostream>

using namespace std;

int main()
{
	const int p=3,q=1;
	//cout<< sizeof(p)<<"\t"<<&p<<"\t"<<sizeof(3.211)<<endl;
	const int &r=p;
	cout<<r<<endl;
	//r=q;// errror:assignment of read-only reference ‘r’
	//int &x=p;error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
	cout<<x<<endl;
	//cout<<r<<endl;
	return 0;

}
