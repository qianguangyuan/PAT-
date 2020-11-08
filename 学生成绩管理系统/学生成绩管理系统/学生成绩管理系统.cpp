#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
#include<string.h>

struct Student
{
    int num;//学号
    char name[8];//姓名
    int* score;//分数数组
    int rank;//排名
};

static int a, b;
Student* stu;


void Init()
{
    printf("请输入班级人数：");
    scanf("%d", &a);
    printf("\n请输入分数科目：");
    scanf("%d", &b);
    stu = (Student*)malloc(sizeof(Student) * a);
    for (int i = 0; i < a; i++)
    {
        stu[i].score = (int*)malloc(sizeof(int) * b);
        stu[i].rank = 0;
    }

    for (int i = 0; i < a; i++)
    {
        printf("请输入第%d个人的学号：",i+1);
        scanf("%d", &stu[i].num);
        printf("请输入第%d个人的姓名：",i+1);
        scanf("%s", stu[i].name);
        for (int j = 0; j < b; j++)
        {
            printf("请输入第%d个人第%d科的分数：", i + 1,j+1);
            int sco;
            scanf("%d", &sco);
            stu[i].score[j] = sco;
        }
    }
}

int sumStuscore(Student s)//某个学生的总成绩
{
    int sum = 0;
    for (int i = 0; i < b; i++)
        sum += s.score[i];
    return sum;
}

int sumCourscore(int num)//某个课程的总分
{
    int sum=0;
    for (int i = 0; i < a; i++)
    {
        sum += stu[i].score[num-1];
    }
    return sum;
}

void Rank()//排名，把排序放到结构体中
{
    Student temp;
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j <= a - i; j++)//冒泡排序，最大的放后面
        {
            if (sumStuscore(stu[j]) < sumStuscore(stu[j - 1]))
            {
                temp = stu[j];
                stu[j] = stu[j - 1];
                stu[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        stu[i].rank = i + 1;
    }
}

void ScoreList()
{
    Rank();
    for (int i = a; i >0; i--)
    {
        printf("第%d名的是：", a-i+1);
        printf(stu[i-1].name);
        printf("\n");
    }
}

void scoredic()
{
    Student temp;
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j <=a - i; j++)//冒泡排序，最大的放后面
        {
            if (strcmp(stu[j].name,stu[j - 1].name)<0)
            {
                temp = stu[j];
                stu[j] = stu[j - 1];
                stu[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < a; i++)
    {

        printf("第%d个的是：", i + 1);
        printf("%d", stu[i].num);
        printf("\n");
    }
}

void scoreNum()
{
    Student temp;
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j < a - i; j++)//冒泡排序，最大的放后面
        {
            if (sumStuscore(stu[j]) < sumStuscore(stu[j - 1]))
            {
                temp = stu[j];
                stu[j] = stu[j - 1];
                stu[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < a; i++)
    {

        printf("第%d名的是：", i + 1);
        printf("%d",stu[a-i-1].num);
        printf("\n");
    }
}
    
void SearchByNum()
{
    Rank();
    printf("请输入你要查找的学号：");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < a; i++)
    {
        if (stu[i].num == num)
        {
            for (int j = 0; j < b; j++)
            {
                printf("第%d科的成绩为：%d  ", j + 1, stu[i].score[j]);
           }
            printf("排名为:%d\n", stu[i].rank);
            return;
        }
    }
    printf("未查此人！\n");
}

void Analysis()
{
    for (int i = 0; i < b; i++)//科目数
    {
        float excellent = 0;
        float good = 0;
        float medium = 0;
        float pass = 0;
        float unpass = 0;
        for (int j = 0; j < a; j++)//人数
        {

            if (stu[j].score[i] >= 90)
                excellent++;
            else if (stu[j].score[i] >= 80)
                good++;
            else if (stu[j].score[i] >= 70)
                medium++;
            else if (stu[j].score[i] >= 60)
                pass++;
            else
                unpass++;
        }
        printf("优秀数：%.1f 占比为：%.2f %%", excellent, excellent / b*100);
        printf(" 良好数：%.1f 占比为：%.2f %%", good, good / b*100);
        printf(" 中等数：%.1f 占比为：%.2f %%", medium, medium / b * 100);
        printf(" 及格数：%.1f  占比为：%.2f %%", pass, pass / b * 100);
        printf(" 不及格数：%.1f 占比为：%.2f %%\n", unpass, unpass / b * 100);
    }
}

void fun2()
{
    for (int i = 0; i < b; i++)
    printf("第%d科的总分为：%d，平均分为：%d  \n", i + 1, sumCourscore(i+1), sumCourscore(i+1) / a);
}

void fun3()
{
    for (int i = 0; i < a; i++)
    {
        printf("学号：%d", stu[i].num);
        printf(" 姓名：%s", stu[i].name);
        printf(" 总分：%d", sumStuscore(stu[i]));
        printf(" 平均分：%d\n", sumStuscore(stu[i]) / b);
    }
}


void Listrecord()
{
    for (int i = 0; i < a; i++)
    {
        printf("学号：%d", stu[i].num);
        printf(" 姓名：%s", stu[i].name);
        printf(" 总分：%d", sumStuscore(stu[i]));
        printf(" 平均分：%d\n", sumStuscore(stu[i]) / b);
        for (int j = 0; j < b; j++)
            printf("第%d科的成绩为：%d  \n", j + 1, stu[i].score[j]);
    }

    for (int i = 0; i <b; i++)
        printf("第%d科的总分为：%d，平均分为：%d  \n\n", i + 1, sumCourscore(i+1),sumCourscore(i+1)/a);
}

void SearchByName()
{
    printf("请输入你要查找的姓名：");
    char name[8];
    scanf("%s", name);
    for (int i = 0; i < a; i++)
    {
        if (strcmp(name,stu[i].name)==0)
        {
            for (int j = 0; j < b; j++)
            {
                printf("第%d科的成绩为：%d  ", j + 1, stu[i].score[j]);
            }
            printf("排名为:%d", stu[i].rank);
        }
    }
}

void showchoice()
{
    printf("1. Input record\n");
    printf("2. Caculate total and average score of every course\n");
    printf("3. Caculate total and average score of every student\n");
    printf("4. Sort in decending order by total socre of every student\n");
    printf("5. Sort in ascending order by number\n");
    printf("6. Sort in ascending order by name\n");
    printf("7. Search by number\n");//
    printf("8. Search by name\n");//
    printf("9. Statistic analysis for every course\n");//
    printf("10. List reocrd\n");
    printf("0. Exit\n");
    printf("*******************************************************\n");
    printf("Please enter your choice:");
    int i; scanf("%d", &i);
    switch(i)
    {
    case 1:Init(); break;
    case 2:fun2(); break;
    case 3:fun3(); break;
    case 4:ScoreList(); break;
    case 5:scoreNum(); break;
    case 6:scoredic(); break;
    case 7:SearchByNum(); break;
    case 8:SearchByName(); break;
    case 9:Analysis(); break;
    case 10:Listrecord(); break;
    default:
        break;
    }
}

int main()
{
    while(1)
    showchoice();
    return 0;
}
