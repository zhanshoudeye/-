#pragma once
#include<iostream>

class BookData
{
public:
    // BookData类的默认构造函数
	BookData() 
	{
		// 初始化成员变量为默认值
		isbn[0] = '\0';
		bookTitle[0] = '\0';
		author[0] = '\0';
		pub[0] = '\0';
		qtyOnHand = 0;
		retail = 0.0;
		wholesale = 0.0;
		date[0] = '\0';
	}
	char isbn[14];//书籍ISBN号
	char bookTitle[51];//书名
	int qtyOnHand;//库存量
	double retail;//零售价
	char author[30];
	char date[11];
	char pub[30];
	double wholesale;
    //显示书籍的详细信息
	void BookInfo(const BookData p)
	{
		int a = 1;
		while (a)//a等于0时循环终止，退出到报告菜单
		{
			std::cout << "       教育图书管理系统" << std::endl;
			std::cout << "            书的资料" << std::endl;
			std::cout << "ISBN号：" << p.isbn << std::endl;
			std::cout << "书 名：" << p.bookTitle << std::endl;
			std::cout << "库存量：" << p.qtyOnHand << std::endl;
			std::cout << "零售价：" << p.retail << std::endl;
			std::cout << "\n";
			std::cout << "按0键退出" << std::endl;
			std::cin >> a;
		}


	}
};

