#include<iostream>
#include<cstring>
#include"BookData.h"

extern BookData book[];
//����ISBN�ź���������������

static double total=0;
static double tax=0;
static double money=0;
int num[100];
static BookData books[100];
static int i = 0;
static int j = 1;
static char choice1, choice2;
static void Checkoutmenu(int x, char* y, char* z, double m)
{
	money += m * x;//�������۽��
	tax += money * 0.06;//����˰��
	total += money + tax;//�����ܶ�
	std::cout << " " << x << "    " << y << "  " << z << "    RMB " << m << "        RMB " << m * x << std::endl;
}
void Checkout(int MAX_SIZE)
{
	
	while (1)
	{
		std::cout << "������ISBN��:" << std::endl;
		std::cin >> books[j].isbn;//����ISBN��

		int found = 0;//�����ж��Ƿ��ҵ�����
		for (int i = 0;i < MAX_SIZE;i++)
		{
			if (strcmp(book[i].isbn, books[j].isbn) == 0)//��������ͨ��ISBNѰ��,�ж��Ƿ��ҵ�
			{
				books[j] = book[i];
				found = 1;//��ʾ�ҵ���
				std::cout << "����������:" << std::endl;
				std::cin >> num[j];//��������
				std::cout << "              ǰ̨����ģ��" << std::endl;
				std::cout << "���ڣ�2024��12�� ��" << std::endl;
				std::cout << "����     ISBN��         ����             ����          ���" << std::endl;
				for (int k = 1;k <= j;k++)
				{
					Checkoutmenu(num[k], books[k].isbn , books[k].bookTitle,books[k].retail);
				}
				std::cout << "---------------------------------------------------" << std::endl;
				std::cout << "���ۺϼƣ�RMB " << money << std::endl;
				std::cout << "����˰��RMB " << tax << std::endl;
				std::cout << "Ӧ���ܶRMB " << total << std::endl;
				std::cout << " " << std::endl;
				std::cout << "лл���٣�" << std::endl;
				std::cout << "�Ƿ��������y/n��?" << std::endl;
				std::cin >> choice2;
				break;
				
			}
			
		}
		if (choice2 == 'n')//������n
		{
			break;
		}
		if (choice2 == 'y')
		{
			j++;
		}

		if (found == 0)//������
		{
			
			std::cout << "�������ISBN�Ŵ���!" << std::endl;
			std::cout << "�Ƿ��ٴ����루y/n��?" << std::endl;//�û�ѡ���Ƿ��ٴ�����
			std::cin >> choice1;
			if (choice1 == 'y')//������y
			{
				Checkout(MAX_SIZE);//���µ��ú���
			}
			else break;

		}
	}
}
