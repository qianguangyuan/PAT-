#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

struct Student
{
    string name;
    char gender;
    string id;
    int grade;
};

bool compare(const Student& s1, const Student& s2)
{
    return s1.grade < s2.grade;
}

int main()
{
    int n;
    cin >> n;
    Student* stu = new Student[n];
    int m = n;
    while (m--)
    {
        cin >> stu[m].name >> stu[m].gender >> stu[m].id >> stu[m].grade;
    }
    int girl = 0;
    int grade1 = 0;
    int grade2 = 0;
    sort(stu, (stu+n),compare);
    for (int i = 0; i < n; i++)
    {
        if (stu[i].gender == 'F')
        {
            girl++;
        }
    }
    if (girl == 0)
        cout << "Absent" << endl;
    else
    {
        for (int i =n-1; i>=0; i--)
        {
            if (stu[i].gender == 'F')
            {
                cout << stu[i].name <<' '<< stu[i].id << endl;
                grade1 = stu[i].grade;
                break;
            }
        }
    }
    if(girl==n)
        cout << "Absent" << endl;
    else
    {
        for (int i = 0; i <n; i++)
        {
            if (stu[i].gender == 'M')
            {
                cout << stu[i].name << ' ' << stu[i].id << endl;
                grade2 = stu[i].grade;
                break;
            }
        }
    }
    
    if (girl == n || girl == 0)
    {
        cout << "NA";
    }
    else
        cout << grade1 - grade2;
    return 0;
}
