#include<iostream>
#include<string>
using namespace std;

struct sales_date{
    unsigned units_sold=0;
    double revenue =0.0;
    string bookNo;

    string isbn() const{
        return bookNo;
    }
    sales_date & combine(const sales_date &rhs);
    
};

sales_date & sales_date::combine(const sales_date &rhs)
{
    revenue+=rhs.revenue;
    units_sold+=rhs.units_sold;
    return *this;
}