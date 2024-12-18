#include<iostream>
#include<cstring>
#include"BookData.h"
#include"Manage.h"
#include"Checkout.h"
#include"Report.h"
const int MAX_SIZE = 100;//����ȫ�ֱ��������������

BookData book[MAX_SIZE];//����ȫ���鼮����

//��ʾ���˵��������û�ѡ��ͬ��ѡ��
void Mainmenu()
{
	
	// ��ʼ���鼮��������
	int x = 0;

	// ���õ�һ�������Ϣ
	setTitle("C++ Primer", x);
	setISBN("0321714113", x);
	setQty(30, x);
	setRetail(59.99, x);
	setAuthor("Stanley B. Lippman", x);
	setPub("Addison-Wesley", x);
	setDateAdded("2022-05-15", x);
	setWholesale(44.99, x);

	// ���õڶ��������Ϣ
	x = 1; // �ƶ����ڶ����������
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
		std::cout << "       ����ͼ�����ϵͳ" << std::endl;
		std::cout << "            ���˵�" << std::endl;
		std::cout << "1.����ģ��" << std::endl;
		std::cout << "2.������ģ��" << std::endl;
		std::cout << "3.����ģ��" << std::endl;
		std::cout << "4.�˳�ϵͳ" << std::endl;
		std::cout << "\n";
		std::cout << "  ����ѡ��" << std::endl;
		std::cout << "  ������1-4֮�������" << std::endl;
		std::cin >> mainchoice;
		switch (mainchoice)
		{
		case 1:
			std::cout << "��ӭ��������ģ��" << std::endl;
			Checkout(MAX_SIZE);//��������ģ��
			break;
		case 2:
			std::cout << "��ӭ����������ģ��" << std::endl;
			Manage(MAX_SIZE);//����������ģ�飬����������˵�
			break;
		case 3:
			std::cout << "��ӭ���뱨��ģ��" << std::endl;
			Report(MAX_SIZE);//���ñ���ģ�飬���뱨��˵�
			break;
		case 4:
			std::cout << "�˳�ϵͳ" << std::endl;
			break;
		default:
			std::cout << "�����������������롣" << std::endl;//�������ٴ�ѭ��
		}
		if (mainchoice == 4)break;//�˳�ѭ�����������н���


	}


}