#include<iostream>
#include"BookData.h"
extern BookData book[];//����ȫ���鼮����
static const int MAX_SIZE = 100;
//����б��г������鼮��ISBN�ź�����
static void ListA()
{
	int a = 1;
	BookData books[MAX_SIZE];
	int j = 0;
	while (a)//a����0ʱѭ����ֹ���˳�������˵�
	{
		std::cout << "���    ISBN         ����" << std::endl;
		
		for (int i = 0;i < MAX_SIZE;i++)
		{
			if (book[i].isbn[0] != '\0')//ͨ��isbn������׸�Ԫ���ж��Ƿ���ڸ��鼮
			{
				
				books[j] = book[i];
				j++;
			}

		}


		for (int i = 0;i < j;i++)
		{
			std::cout << i + 1 << ".     " << books[i].isbn << "  " << books[i].bookTitle << std::endl;
		}
		

		std::cout << "\n";
		std::cout << "��0���˳�" << std::endl;
		std::cin >> a;

	}

}
//���ۼ��б��г������鼮�����ۼۺͿ��
static void ListB()
{
	int a = 1;
	BookData books[MAX_SIZE];
	int j = 0;
	while (a)//a����0ʱѭ����ֹ���˳�������˵�
	{
		std::cout << "���     ISBN        ���ۼ�       �����" << std::endl;
		
		for (int i = 0;i < MAX_SIZE;i++)
		{
			if (book[i].isbn[0] != '\0')//ͨ��isbn������׸�Ԫ���ж��Ƿ���ڸ��鼮
			{
				
				books[j] = book[i];
				j++;
			}

		}


		for (int i = 0;i < j;i++)
		{
			std::cout << i + 1 << ".     " << books[i].isbn << "   RMB " << books[i].retail << "     " << books[i].qtyOnHand << std::endl;
		}
		std::cout << "\n";
		std::cout << "��0���˳�" << std::endl;
		std::cin >> a;
	
	}
		

}
//�������б��г������鼮�������ۺͿ�棬���������ܶ�
static void ListC()
{
	int a = 1;
	
	BookData books[MAX_SIZE];
	int j = 0;
	while (a)//a����0ʱѭ����ֹ���˳�������˵�
	{
		std::cout << "���        ISBN      ������    �����     �������ܶ�" << std::endl;
		
		for (int i = 0;i < MAX_SIZE;i++)
		{
			if (book[i].isbn[0] != '\0')//ͨ��isbn������׸�Ԫ���ж��Ƿ���ڸ��鼮
			{
				
				books[j] = book[i];
				j++;
			}

		}


		for (int i = 0;i < j;i++)
		{
			
			std::cout << i + 1 << ".     " << books[i].isbn << "   RMB " << books[i].wholesale << "     " << books[i].qtyOnHand << "       RMB " << books[i].qtyOnHand * books[i].wholesale << std::endl;
		}

		
		std::cout << "\n";
		std::cout << "��0���˳�" << std::endl;
		std::cin >> a;
	}

}
//������б��г������鼮��ISBN�Ϳ�棬����ɴ�С����
static void ListD()
{
	int a = 1;
	BookData books[MAX_SIZE];
	int j = 0;
	
	while (a)//a����0ʱѭ����ֹ���˳�������˵�
	{
		std::cout << "���       ISBN     �����" << std::endl;
		for (int i = 0;i < MAX_SIZE;i++)
		{
			if (book[i].isbn[0] != '\0')//ͨ��isbn������׸�Ԫ���ж��Ƿ���ڸ��鼮
			{
				books[j] = book[i];
				j++;
			}

		}

		for (int i = 0;i < j - 1 ;i++)
		{
			for (int k = 0;k < j - i - 1;k++)
			{
				if (books[k].qtyOnHand  < books[k + 1].qtyOnHand)//�ж�����Ԫ�صĴ�С
				{
					BookData temp = books[k];//��������Ԫ��
					books[k] = books[k + 1];
					books[k + 1] = temp;
				}
			}
		}
		
		for (int i = 0;i < j ;i++)
		{
			std::cout << i + 1 << ".     " << books[i].isbn << "     " << books[i].qtyOnHand << std::endl;
		
		}
		std::cout << "\n";
		std::cout << "��0���˳�" << std::endl;
		std::cin >> a;
	}

}
//�������ܶ��б��г������鼮��ISBN����棬�����ۺ��������ܶ�������ܶ��ɴ�С����
static void ListE()
{
	int a = 1;
	BookData books[MAX_SIZE];
	int j = 0;

	while (a)//a����0ʱѭ����ֹ���˳�������˵�
	{
		std::cout << "���       ISBN      ������     �����     �������ܶ�" << std::endl;
		for (int i = 0;i < MAX_SIZE;i++)
		{
			if (book[i].isbn[0] != '\0')//ͨ��isbn������׸�Ԫ���ж��Ƿ���ڸ��鼮
			{
				books[j] = book[i];
				j++;
			}

		}

		for (int i = 0;i < j - 1;i++)
		{
			for (int k = 0;k < j - i - 1;k++)
			{
				if (books[k].qtyOnHand*books[k].wholesale < books[k + 1].qtyOnHand * books[k+1].wholesale)//�ж�����Ԫ�صĴ�С
				{
					BookData temp = books[k];//��������Ԫ��
					books[k] = books[k + 1];
					books[k + 1] = temp;
				}
			}
		}

		for (int i = 0;i < j;i++)
		{
			std::cout << i + 1 << ".     " << books[i].isbn << "   RMB " << books[i].wholesale << "     " << books[i].qtyOnHand << "       RMB " << books[i].qtyOnHand*books[i].wholesale << std::endl;

		}
		std::cout << "\n";
		std::cout << "��0���˳�" << std::endl;
		std::cin >> a;
	}

}
//���������б��г������鼮��ISBN�ͽ������ڣ����������ɴ�С����
static void ListF()
{
	int a = 1;
	BookData books[MAX_SIZE];
	int j = 0;

	while (a)//a����0ʱѭ����ֹ���˳�������˵�
	{
		std::cout << "���       ISBN     ��������" << std::endl;
		for (int i = 0;i < MAX_SIZE;i++)
		{
			if (book[i].isbn[0] != '\0')//ͨ��isbn������׸�Ԫ���ж��Ƿ���ڸ��鼮
			{
				books[j] = book[i];
				j++;
			}

		}

		for (int i = 0;i < j - 1;i++)
		{
			for (int k = 0;k < j - i - 1;k++)
			{
				if (strcmp(books[k].date,books[k+1].date)<0)//�Ƚ������ַ������Ƚ����ڴ�С
				{
					BookData temp = books[k];
					books[k] = books[k + 1];
					books[k + 1] = temp;
				}
			}
		}

		for (int i = 0;i < j;i++)
		{
			std::cout << i + 1 << ".     " << books[i].isbn << "     " << books[i].date << std::endl;

		}
		std::cout << "\n";
		std::cout << "��0���˳�" << std::endl;
		std::cin >> a;
	}

}
// ��ʾ����˵��������û�ѡ��ͬ��ѡ��
void Report(const int MAX_SIZE)
{
	int rchoice;
	while (1)
	{
		std::cout << "       ����ͼ�����ϵͳ" << std::endl;
		std::cout << "            ����ģ��" << std::endl;
		std::cout << "1.����б�" << std::endl;
		std::cout << "2.���ۼ��б�" << std::endl;
		std::cout << "3.�������б�" << std::endl;
		std::cout << "4.����б�" << std::endl;
		std::cout << "5.��ֵ���б�" << std::endl;
		std::cout << "6.���������б�" << std::endl;
		std::cout << "7.���ص����˵�" << std::endl;
		std::cout << "\n";
		std::cout << "  ����ѡ��";
		std::cin >> rchoice;
		switch (rchoice)
		{
		case 1:
			ListA();//�г�����б�
			break;
		case 2:
			ListB();//�г����ۼ��б�
			break;
		case 3:
			ListC();//�г��������б�
			break;
		case 4:
			ListD();//�г�������б�
			break;
		case 5:
			ListE();//�г��������ܶ��б�
			break;
		case 6:
			ListF(); //�г����������б�
			break;
		case 7:
			break;
		default:
			std::cout << "�����������������롣" << std::endl;//�������ٴ�ѭ��
		}
		if (rchoice == 7)
		{
			break;//�˳�ѭ�����ص����˵�
		}
	}
}