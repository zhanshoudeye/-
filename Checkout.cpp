#include<iostream>
#include<cstring>
#include"BookData.h"

extern BookData book[];
//输入ISBN号和数量来进行收银

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
    money += m * x;//计算销售金额
    tax += money * 0.06;//计算税额
    total += money + tax;//计算总额
    std::cout << " " << x << "    " << y << "  " << z << "    RMB " << m << "        RMB " << m * x << std::endl;
}
void Checkout(int MAX_SIZE)
{

    while (1)
    {
        std::cout << "请输入ISBN号:" << std::endl;
        std::cin >> books[j].isbn;//输入ISBN号

        int found = 0;//用于判断是否找到对象
        for (int i = 0;i < MAX_SIZE;i++)
        {
            if (strcmp(book[i].isbn, books[j].isbn) == 0)//遍历数组通过ISBN寻找,判断是否找到
            {
                books[j] = book[i];
                found = 1;//表示找到了
                std::cout << "请输入数量:" << std::endl;
                std::cin >> num[j];//输入数量
                std::cout << "              前台销售模块" << std::endl;
                std::cout << "日期：2024年12月 日" << std::endl;
                std::cout << "数量     ISBN号         书名             单价          金额" << std::endl;
                for (int k = 1;k <= j;k++)
                {
                    Checkoutmenu(num[k], books[k].isbn , books[k].bookTitle,books[k].retail);
                }
                std::cout << "---------------------------------------------------" << std::endl;
                std::cout << "销售合计：RMB " << money << std::endl;
                std::cout << "零售税：RMB " << tax << std::endl;
                std::cout << "应付总额：RMB " << total << std::endl;
                std::cout << " " << std::endl;
                std::cout << "谢谢光临！" << std::endl;
                std::cout << "是否继续购买（y/n）?" << std::endl;
                std::cin >> choice2;
                break;

            }

        }
        if (choice2 == 'n')//若输入n
        {
            break;
        }
        if (choice2 == 'y')
        {
            j++;
        }

        if (found == 0)//错误处理
        {

            std::cout << "您输入的ISBN号错误!" << std::endl;
            std::cout << "是否再次输入（y/n）?" << std::endl;//用户选择是否再次输入
            std::cin >> choice1;
            if (choice1 == 'y')//若输入y
            {
                Checkout(MAX_SIZE);//重新调用函数
            }
            else break;

        }
    }
}
