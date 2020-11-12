#include"7_2.h"

int main()
{
    sales_date total;
    total.bookNo="abcdefg";
    total.revenue=0.2;
    total.units_sold=10;
     if (total.bookNo != "") {
        sales_date  trans; //保存和的变量
                          //读入并处理剩余交易记录
        trans.bookNo = "abcdefg";
        trans.revenue = 0.2;
        trans.units_sold = 10;

        //如果我们仍在处理相同的书
        if (total.isbn() == trans.isbn())
            total.combine(trans);///使用类函数
        //更新总销售额
        else {
            //打印前一本书的结果
            cout << total.units_sold * total.revenue << endl;
            total.units_sold = trans.units_sold;
            //total现在表示下一本书的销售额 
        }
    }
    cout << total.units_sold * total.revenue << endl;
    //打印最后一本书的结果 
    if (total.isbn() == "") {
        //没有输入！警告读者
        cerr << "No data?" << endl;
        return -1; //表示失败 
    }
    return 0;
    
}