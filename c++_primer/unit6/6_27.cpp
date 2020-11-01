#include"main.h"

void conclude_num(initializer_list<int> num)
{
	int nm=0;
	for(auto i:num)
		nm+=i;
	cout<<nm<<endl;
}
