#include<iostream>

#include"BookData.h"
#include"Manage.h"
#include"Checkout.h"
#include"Report.h"
const int MAX_SIZE = 100;//声明全局变量书库的最大容量

BookData book[MAX_SIZE];//声明全局书籍数组

//显示主菜单，方便用户选择不同的选项
void Mainmenu()
{

    // 初始化书籍数组索引
    int x = 0;

    // 设置第一本书的信息
    setTitle("C++ Primer", x);
    setISBN("0321714113", x);
    setQty(30, x);
    setRetail(59.99, x);
    setAuthor("Stanley B. Lippman", x);
    setPub("Addison-Wesley", x);
    setDateAdded("2022-05-15", x);
    setWholesale(44.99, x);

    // 设置第二本书的信息
    x = 1; // 移动到第二本书的索引
    setTitle("Effective Modern C++", x);
    setISBN("149190436", x);
    setQty(25, x);
    setRetail(39.99, x);
    setAuthor("Scott Meyers", x);
    setPub("O'Reilly Media", x);
    setDateAdded("2015-07-01", x);
    setWholesale(29.99, x);

    setQty(35, x);
    setTitle("Effective Modern C", 3);
    setISBN("1491904364", 3);
    setQty(25, 3);
    setRetail(39.99, 3);
    setAuthor("Scott Meyers", 3);
    setPub("O'Reilly Media", 3);
    setDateAdded("2015-08-01", 3);
    setWholesale(29.99, 3);
    int mainchoice;

    while (1) {
        std::cout << "       教育图书管理系统" << std::endl;
        std::cout << "            主菜单" << std::endl;
        std::cout << "1.收银模块" << std::endl;
        std::cout << "2.书库管理模块" << std::endl;
        std::cout << "3.报表模块" << std::endl;
        std::cout << "4.退出系统" << std::endl;
        std::cout << "\n";
        std::cout << "  输入选择：" << std::endl;
        std::cout << "  请输入1-4之间的数。" << std::endl;
        std::cin >> mainchoice;
        switch (mainchoice)
        {
            case 1:
                std::cout << "欢迎进入收银模块" << std::endl;
                Checkout(MAX_SIZE);//调用收银模块
                break;
            case 2:
                std::cout << "欢迎进入书库管理模块" << std::endl;
                Manage(MAX_SIZE);//调用书库管理模块，进入书库管理菜单
                break;
            case 3:
                std::cout << "欢迎进入报表模块" << std::endl;
                Report(MAX_SIZE);//调用报表模块，进入报表菜单
                break;
            case 4:
                std::cout << "退出系统" << std::endl;
                break;
            default:
                std::cout << "输入有误，请重新输入。" << std::endl;//错误处理，再次循环
        }
        if (mainchoice == 4)break;//退出循环，程序运行结束


    }


}