#pragma once
#include<iostream>

class BookData
{
public:
	// BookData���Ĭ�Ϲ��캯��
	BookData() 
	{
		// ��ʼ����Ա����ΪĬ��ֵ
		isbn[0] = '\0';
		bookTitle[0] = '\0';
		author[0] = '\0';
		pub[0] = '\0';
		qtyOnHand = 0;
		retail = 0.0;
		wholesale = 0.0;
		date[0] = '\0';
	}
	char isbn[14];//�鼮ISBN��
	char bookTitle[51];//����
	int qtyOnHand;//�����
	double retail;//���ۼ�
	char author[30];
	char date[11];
	char pub[30];
	double wholesale;
	//��ʾ�鼮����ϸ��Ϣ
	void BookInfo(const BookData p)
	{
		int a = 1;
		while (a)//a����0ʱѭ����ֹ���˳�������˵�
		{
			std::cout << "       ����ͼ�����ϵͳ" << std::endl;
			std::cout << "            �������" << std::endl;
			std::cout << "ISBN�ţ�" << p.isbn << std::endl;
			std::cout << "�� ����" << p.bookTitle << std::endl;
			std::cout << "�������" << p.qtyOnHand << std::endl;
			std::cout << "���ۼۣ�" << p.retail << std::endl;
			std::cout << "\n";
			std::cout << "��0���˳�" << std::endl;
			std::cin >> a;
		}


	}
};

