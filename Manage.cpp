#include<iostream>
#include<cstring>
#include"BookData.h"

extern BookData book[];
void setTitle(const char* title, int x)
{
    strcpy_s(book[x].bookTitle, title);
}
//设置ISBN号
void setISBN(const char* ISBN, int x)
{
    strcpy_s(book[x].isbn, ISBN);
}
//设置库存量
void setQty(int Qty, int x)
{
    book[x].qtyOnHand = Qty;
}
//设置零售价
void setRetail(double Retail, int x)
{
    book[x].retail = Retail;
}
//设置作者
void setAuthor(const char* Author, int x)
{
    strcpy_s(book[x].author, Author);
}
//设置出版社
void setPub(const char* Pub, int x)
{
    strcpy_s(book[x].pub, Pub);
}
//设置进书日期
void setDateAdded(const char* Data, int x)
{
    strcpy_s(book[x].date, Data);
}
//设置批发价
void setWholesale(double Wholesale, int x)
{
    book[x].wholesale = Wholesale;
}
//通过书名查找书籍，并显示书的详细资料
static void lookUpBook(int MAX_SIZE)
{
    int found = 0;//判断是否找到书的变量
    char t[51];
    std::cout << "请输入书名:";
    std::cin >> t;
    for (int i = 0;i < MAX_SIZE;i++)
    {
        if (strcmp(book[i].bookTitle, t) == 0)
        {
            book[i].BookInfo(book[i]);
            found = 1;//表示找到了
            break;
        }

    }
    if (found == 0)//错误处理
    {
        std::cout << "错误！！！" << std::endl;
        std::cout << "请重新输入。" << std::endl;
        lookUpBook(MAX_SIZE);//重新调用函数
    }
}
// 判断书籍数组中某一对象是否为空
static int isEmpty(int x)
{
    if (book[x].bookTitle[0] == '\0') return 1;//若书名首元素为空，代表是空的
    else return 0;
}
//增加书籍
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
        if (isEmpty(i))//寻找非空对象
        {
            x = i;
            break;
        }
    }
    //设置书名
    std::cout << "请输入书名：";
    std::cin >> title;
    setTitle(title, x);

    //设置ISBN号
    std::cout << "请输入ISBN号：";
    std::cin >> ISBN;
    setISBN(ISBN, x);

    //设置库存
    std::cout << "请输入库存：";
    std::cin >> Qty;
    setQty(Qty, x);

    //设置零售价
    std::cout << "请输入零售价：";
    std::cin >> Retail;
    setRetail(Retail, x);

    //设置作者
    std::cout << "请输入作者：";
    std::cin >> Author;
    setAuthor(Author, x);
    //设置出版社
    std::cout << "请输入出版社：";
    std::cin >> Pub;
    setISBN(Pub, x);

    //设置进书日期
    std::cout << "请输入进书日期：";
    std::cin >> Date;
    setDateAdded(Date, x);

    //设置批发价
    std::cout << "请输入批发价：";
    std::cin >> Wholesale;
    setWholesale(Wholesale, x);
}
//修改对象中的某数据项
static void editBook(int MAX_SIZE)
{
    char t[51];
    char title[51];
    char ISBN[14];
    int Qty;
    double Retail;
    int index = 0;
    int found = 0;//用于判断是否找到对象
    int echoice;
    int a = 1;
    std::cin >> t;
    std::cout << "请输入书名：";//通过书名查找
    for (int i = 0;i < MAX_SIZE;i++)
    {
        if (strcmp(book[i].bookTitle, t) == 0)//通过书名判断是否找到相应书籍
        {
            index = i;//找到相应数组元素的下标
            found = 1;//表示找到了
            break;
        }

    }
    if (found == 1)//找到后开始修改
    {
        while (a)
        {
            std::cout << "1.书名" << std::endl;
            std::cout << "2.ISBN号" << std::endl;
            std::cout << "3.库存" << std::endl;
            std::cout << "4.零售价" << std::endl;
            std::cout << "5.返回到书库管理菜单" << std::endl;
            std::cout << "\n";
            std::cout << " 请输入要修改的数据项" << std::endl;
            std::cin >> echoice;//选择要修改的项
            switch (echoice)
            {
                case 1:
                    std::cout << "请输入书名：";
                    std::cin >> title;
                    setTitle(title, index);//修改书名

                    break;
                case 2:
                    std::cout << "请输入ISBN号：";
                    std::cin >> ISBN;
                    setISBN(ISBN, index);//修改ISBN号
                    break;
                case 3:
                    std::cout << "请输入库存：";
                    std::cin >> Qty;
                    setQty(Qty, index);//修改库存
                    break;
                case 4:
                    std::cout << "请输入单价：";
                    std::cin >> Retail;
                    setRetail(Retail, index);//修改单价
                    break;
                case 5:
                    a = 0;//改变a的值，使循环终止，返回到书库管理菜单
                    break;
                default:
                    std::cout << "输入有误，请重新输入。" << std::endl;//错误处理
            }
        }
    }
    else
    {
        std::cout << "错误！！！" << std::endl;
        std::cout << "请重新输入。" << std::endl;
        editBook(MAX_SIZE);
    }
}
//移除书籍
static void removeBook(int MAX_SIZE)
{
    char t[51];
    int x;//用于表示下标
    int found = 0;//用于判断是否找到对象
    std::cout << "请输入书名：";
    std::cin >> t;
    for (int i = 0;i < MAX_SIZE;i++)
    {
        if (strcmp(book[i].bookTitle, t) == 0)//通过书名判断是否找到相应书籍
        {
            x = i;//找到相应数组元素的下标
            found = 1;//表示找到了

            break;
        }

    }
    if (found == 1)//开始移除
    {
        book[x].bookTitle[0] = '\0';//通过将首元素变成'\0'，无法查找到该书籍的详细信息
        book[x].isbn[0] = '\0';//通过将首元素变成'\0'，无法查找到该书籍的详细信息


    }
    else//错误处理
    {
        std::cout << "错误！！！" << std::endl;
        std::cout << "请重新输入。" << std::endl;
        removeBook(MAX_SIZE);//重新调用函数

    }
}
//显示书库管理菜单，方便用户选择不同的选项
void Manage(int MAX_SIZE)
{

    int mchoice;

    while (1)
    {
        std::cout << "       教育图书管理系统" << std::endl;
        std::cout << "          书库管理模块" << std::endl;
        std::cout << "1.查找某本书的信息" << std::endl;
        std::cout << "2.增加书" << std::endl;
        std::cout << "3.修改书的信息" << std::endl;
        std::cout << "4.删除书" << std::endl;
        std::cout << "5.返回到主菜单" << std::endl;
        std::cout << "\n";
        std::cout << "  输入选择：";
        std::cin >> mchoice;
        switch (mchoice)
        {
            case 1:

                lookUpBook(MAX_SIZE);//调用查找函数
                break;
            case 2:
                AddBook(MAX_SIZE);//调用增加书籍函数

                break;
            case 3:
                editBook(MAX_SIZE);//调用修改数据项函数
                break;
            case 4:
                removeBook(MAX_SIZE);//调用移除书籍函数
                break;
            case 5:

                break;
            default:
                std::cout << "输入有误，请重新输入。" << std::endl;//错误处理，再次循环
        }
        if (mchoice == 5)
        {
            break;
        }
    }
}