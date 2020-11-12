#include"7_4.h"
/*struct 版本*/
int main()
{
    Person a;
    cin>>a.name>>a.adress;
    for(auto c:a.name)
    {
        cout<<c;
    }
    for(auto c : a.adress)
    {
        cout<<c;
    }
    return 0;
}