#include<iostream>
#include<string>

using namespace std;

struct Person{
    private:
    string name;
     string adress; 
    public:
    string ret_name()const {return name;}
    string ret_adress()const{return adress;}
};