#include<iostream>
#include"BookData.h"
extern BookData book[];//声明全局书籍数组
static const int MAX_SIZE = 100;
//书库列表，列出所有书籍的ISBN号和书名
static void ListA()
{
    int a = 1;
    BookData books[MAX_SIZE];
    int j = 0;
    while (a)//a等于0时循环终止，退出到报告菜单
    {
        std::cout << "序号    ISBN         书名" << std::endl;

        for (int i = 0;i < MAX_SIZE;i++)
        {
            if (book[i].isbn[0] != '\0')//通过isbn数组的首个元素判断是否存在该书籍
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
        std::cout << "按0键退出" << std::endl;
        std::cin >> a;

    }

}
//零售价列表，列出所有书籍的零售价和库存
static void ListB()
{
    int a = 1;
    BookData books[MAX_SIZE];
    int j = 0;
    while (a)//a等于0时循环终止，退出到报告菜单
    {
        std::cout << "序号     ISBN        零售价       库存量" << std::endl;

        for (int i = 0;i < MAX_SIZE;i++)
        {
            if (book[i].isbn[0] != '\0')//通过isbn数组的首个元素判断是否存在该书籍
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
        std::cout << "按0键退出" << std::endl;
        std::cin >> a;

    }


}
//批发价列表，列出所有书籍的批发价和库存，及批发价总额
static void ListC()
{
    int a = 1;

    BookData books[MAX_SIZE];
    int j = 0;
    while (a)//a等于0时循环终止，退出到报告菜单
    {
        std::cout << "序号        ISBN      批发价    库存量     批发价总额" << std::endl;

        for (int i = 0;i < MAX_SIZE;i++)
        {
            if (book[i].isbn[0] != '\0')//通过isbn数组的首个元素判断是否存在该书籍
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
        std::cout << "按0键退出" << std::endl;
        std::cin >> a;
    }

}
//库存量列表，列出所有书籍的ISBN和库存，库存由大到小排列
static void ListD()
{
    int a = 1;
    BookData books[MAX_SIZE];
    int j = 0;

    while (a)//a等于0时循环终止，退出到报告菜单
    {
        std::cout << "序号       ISBN     库存量" << std::endl;
        for (int i = 0;i < MAX_SIZE;i++)
        {
            if (book[i].isbn[0] != '\0')//通过isbn数组的首个元素判断是否存在该书籍
            {
                books[j] = book[i];
                j++;
            }

        }

        for (int i = 0;i < j - 1 ;i++)
        {
            for (int k = 0;k < j - i - 1;k++)
            {
                if (books[k].qtyOnHand  < books[k + 1].qtyOnHand)//判断相邻元素的大小
                {
                    BookData temp = books[k];//交换相邻元素
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
        std::cout << "按0键退出" << std::endl;
        std::cin >> a;
    }

}
//批发价总额列表，列出所有书籍的ISBN，库存，批发价和批发价总额，批发价总额由大到小排列
static void ListE()
{
    int a = 1;
    BookData books[MAX_SIZE];
    int j = 0;

    while (a)//a等于0时循环终止，退出到报告菜单
    {
        std::cout << "序号       ISBN      批发价     库存量     批发价总额" << std::endl;
        for (int i = 0;i < MAX_SIZE;i++)
        {
            if (book[i].isbn[0] != '\0')//通过isbn数组的首个元素判断是否存在该书籍
            {
                books[j] = book[i];
                j++;
            }

        }

        for (int i = 0;i < j - 1;i++)
        {
            for (int k = 0;k < j - i - 1;k++)
            {
                if (books[k].qtyOnHand*books[k].wholesale < books[k + 1].qtyOnHand * books[k+1].wholesale)//判断相邻元素的大小
                {
                    BookData temp = books[k];//交换相邻元素
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
        std::cout << "按0键退出" << std::endl;
        std::cin >> a;
    }

}
//进书日期列表，列出所有书籍的ISBN和进书日期，进书日期由大到小排列
static void ListF()
{
    int a = 1;
    BookData books[MAX_SIZE];
    int j = 0;

    while (a)//a等于0时循环终止，退出到报告菜单
    {
        std::cout << "序号       ISBN     进书日期" << std::endl;
        for (int i = 0;i < MAX_SIZE;i++)
        {
            if (book[i].isbn[0] != '\0')//通过isbn数组的首个元素判断是否存在该书籍
            {
                books[j] = book[i];
                j++;
            }

        }

        for (int i = 0;i < j - 1;i++)
        {
            for (int k = 0;k < j - i - 1;k++)
            {
                if (strcmp(books[k].date,books[k+1].date)<0)//比较日期字符串来比较日期大小
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
        std::cout << "按0键退出" << std::endl;
        std::cin >> a;
    }

}
// 显示报表菜单，方便用户选择不同的选项
void Report()
{
    int rchoice;
    while (1)
    {
        std::cout << "       教育图书管理系统" << std::endl;
        std::cout << "            报表模块" << std::endl;
        std::cout << "1.书库列表" << std::endl;
        std::cout << "2.零售价列表" << std::endl;
        std::cout << "3.批发价列表" << std::endl;
        std::cout << "4.库存列表" << std::endl;
        std::cout << "5.价值额列表" << std::endl;
        std::cout << "6.进书日期列表" << std::endl;
        std::cout << "7.返回到主菜单" << std::endl;
        std::cout << "\n";
        std::cout << "  输入选择：";
        std::cin >> rchoice;
        switch (rchoice)
        {
            case 1:
                ListA();//列出书库列表
                break;
            case 2:
                ListB();//列出零售价列表
                break;
            case 3:
                ListC();//列出批发价列表
                break;
            case 4:
                ListD();//列出库存量列表
                break;
            case 5:
                ListE();//列出批发价总额列表
                break;
            case 6:
                ListF(); //列出进书日期列表
                break;
            case 7:
                break;
            default:
                std::cout << "输入有误，请重新输入。" << std::endl;//错误处理，再次循环
        }
        if (rchoice == 7)
        {
            break;//退出循环，回到主菜单
        }
    }
}