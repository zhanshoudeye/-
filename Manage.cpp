#include<iostream>
#include<cstring>
#include"BookData.h"

extern BookData book[];
void setTitle(const char* title, int x)
{
	strcpy_s(book[x].bookTitle, title);
}
//����ISBN��
void setISBN(const char* ISBN, int x)
{
	strcpy_s(book[x].isbn, ISBN);
}
//���ÿ����
void setQty(int Qty, int x)
{
	book[x].qtyOnHand = Qty;
}
//�������ۼ�
void setRetail(double Retail, int x)
{
	book[x].retail = Retail;
}
//��������
void setAuthor(const char* Author, int x)
{
	strcpy_s(book[x].author, Author);
}
//���ó�����
void setPub(const char* Pub, int x)
{
	strcpy_s(book[x].pub, Pub);
}
//���ý�������
void setDateAdded(const char* Data, int x)
{
	strcpy_s(book[x].date, Data);
}
//����������
void setWholesale(double Wholesale, int x)
{
	book[x].wholesale = Wholesale;
}
//ͨ�����������鼮������ʾ�����ϸ����
static void lookUpBook(int MAX_SIZE)
{
	int found = 0;//�ж��Ƿ��ҵ���ı���
	char t[51];
	std::cout << "����������:";
	std::cin >> t;
	for (int i = 0;i < MAX_SIZE;i++)
	{
		if (strcmp(book[i].bookTitle, t) == 0)
		{
			book[i].BookInfo(book[i]);
			found = 1;//��ʾ�ҵ���
			break;
		}

	}
	if (found == 0)//������
	{
		std::cout << "���󣡣���" << std::endl;
		std::cout << "���������롣" << std::endl;
		lookUpBook(MAX_SIZE);//���µ��ú���
	}
}
// �ж��鼮������ĳһ�����Ƿ�Ϊ��
static int isEmpty(int x)
{
	if (book[x].bookTitle[0] == '\0') return 1;//��������Ԫ��Ϊ�գ������ǿյ�
	else return 0;
}
//�����鼮
static void AddBook(int MAX_SIZE)
{
	char title[51];
	int x = 0;
	char ISBN[14];
	char Author[30];
	char Pub[30];
	int Qty;
	char Date[11];
	double Retail,Wholesale;
	for (int i = 0;i < MAX_SIZE;i++)
	{
		if (isEmpty(i))//Ѱ�ҷǿն���
		{
			x = i;
			break;
		}
	}
	//��������
	std::cout << "������������";
	std::cin >> title;
	setTitle(title, x);
	
	//����ISBN��
	std::cout << "������ISBN�ţ�";
	std::cin >> ISBN;
	setISBN(ISBN, x);
	
	//���ÿ��
	std::cout << "�������棺";
	std::cin >> Qty;
	setQty(Qty, x);
	
	//�������ۼ�
	std::cout << "���������ۼۣ�";
	std::cin >> Retail;
	setRetail(Retail, x);
	
	//��������
	std::cout << "���������ߣ�";
	std::cin >> Author;
	setAuthor(Author, x);
	//���ó�����
	std::cout << "����������磺";
	std::cin >> Pub;
	setISBN(Pub, x);
	
	//���ý�������
	std::cout << "������������ڣ�";
	std::cin >> Date;
	setDateAdded(Date, x);
	
	//����������
	std::cout << "�����������ۣ�";
	std::cin >> Wholesale;
	setWholesale(Wholesale, x);
}
//�޸Ķ����е�ĳ������
static void editBook(int MAX_SIZE)
{
	char t[51];
	char title[51];
	char ISBN[14];
	int Qty;
	double Retail;
	int index = 0;
	int found = 0;//�����ж��Ƿ��ҵ�����
	int echoice;
	int a = 1;
	std::cin >> t;
	std::cout << "������������";//ͨ����������
	for (int i = 0;i < MAX_SIZE;i++)
	{
		if (strcmp(book[i].bookTitle, t) == 0)//ͨ�������ж��Ƿ��ҵ���Ӧ�鼮
		{
			index = i;//�ҵ���Ӧ����Ԫ�ص��±�
			found = 1;//��ʾ�ҵ���
			break;
		}

	}
	if (found == 1)//�ҵ���ʼ�޸�
	{
		while (a)
		{
			std::cout << "1.����" << std::endl;
			std::cout << "2.ISBN��" << std::endl;
			std::cout << "3.���" << std::endl;
			std::cout << "4.���ۼ�" << std::endl;
			std::cout << "5.���ص�������˵�" << std::endl;
			std::cout << "\n";
			std::cout << " ������Ҫ�޸ĵ�������" << std::endl;
			std::cin >> echoice;//ѡ��Ҫ�޸ĵ���
			switch (echoice)
			{
			case 1:
				std::cout << "������������";
				std::cin >> title;
				setTitle(title, index);//�޸�����

				break;
			case 2:
				std::cout << "������ISBN�ţ�";
				std::cin >> ISBN;
				setISBN(ISBN, index);//�޸�ISBN��
				break;
			case 3:
				std::cout << "�������棺";
				std::cin >> Qty;
				setQty(Qty, index);//�޸Ŀ��
				break;
			case 4:
				std::cout << "�����뵥�ۣ�";
				std::cin >> Retail;
				setRetail(Retail, index);//�޸ĵ���
				break;
			case 5:
				a = 0;//�ı�a��ֵ��ʹѭ����ֹ�����ص�������˵�
				break;
			default:
				std::cout << "�����������������롣" << std::endl;//������
			}
		}
	}
	else
	{
		std::cout << "���󣡣���" << std::endl;
		std::cout << "���������롣" << std::endl;
		editBook(MAX_SIZE);
	}
}
//�Ƴ��鼮
static void removeBook(int MAX_SIZE)
{
	char t[51];
	int x;//���ڱ�ʾ�±�
	int found = 0;//�����ж��Ƿ��ҵ�����
	std::cout << "������������";
	std::cin >> t;
	for (int i = 0;i < MAX_SIZE;i++)
	{
		if (strcmp(book[i].bookTitle, t) == 0)//ͨ�������ж��Ƿ��ҵ���Ӧ�鼮
		{
			x = i;//�ҵ���Ӧ����Ԫ�ص��±�
			found = 1;//��ʾ�ҵ���

			break;
		}

	}
	if (found == 1)//��ʼ�Ƴ�
	{
		book[x].bookTitle[0] = '\0';//ͨ������Ԫ�ر��'\0'���޷����ҵ����鼮����ϸ��Ϣ
		book[x].isbn[0] = '\0';//ͨ������Ԫ�ر��'\0'���޷����ҵ����鼮����ϸ��Ϣ


	}
	else//������
	{
		std::cout << "���󣡣���" << std::endl;
		std::cout << "���������롣" << std::endl;
		removeBook(MAX_SIZE);//���µ��ú���

	}
}
//��ʾ������˵��������û�ѡ��ͬ��ѡ��
void Manage(int MAX_SIZE)
{

	int mchoice;
	
	while (1)
	{
		std::cout << "       ����ͼ�����ϵͳ" << std::endl;
		std::cout << "          ������ģ��" << std::endl;
		std::cout << "1.����ĳ�������Ϣ" << std::endl;
		std::cout << "2.������" << std::endl;
		std::cout << "3.�޸������Ϣ" << std::endl;
		std::cout << "4.ɾ����" << std::endl;
		std::cout << "5.���ص����˵�" << std::endl;
		std::cout << "\n";
		std::cout << "  ����ѡ��";
		std::cin >> mchoice;
		switch (mchoice)
		{
		case 1:

			lookUpBook(MAX_SIZE);//���ò��Һ���
			break;
		case 2:
			AddBook(MAX_SIZE);//���������鼮����

			break;
		case 3:
			editBook(MAX_SIZE);//�����޸��������
			break;
		case 4:
			removeBook(MAX_SIZE);//�����Ƴ��鼮����
			break;
		case 5:

			break;
		default:
			std::cout << "�����������������롣" << std::endl;//�������ٴ�ѭ��
		}
		if (mchoice == 5)
		{
			break;
		}
	}
}