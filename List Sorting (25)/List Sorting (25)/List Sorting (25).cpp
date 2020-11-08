#include <iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

struct Student
{
    string name;
    int grade;
    string id;
};

bool compareid(const Student& s1, const Student& s2)
{
    return s1.id < s2.id;
}
bool compareName(const Student& s1, const Student& s2)
{
    if (s1.name == s2.name)
    {
        return s1.id < s2.id;
    }
    return s1.name < s2.name;
}
bool compareGrade(const Student& s1, const Student& s2)
{
    if (s1.grade == s2.grade)
    {
        return s1.id < s2.id;
    }
    return s1.grade < s2.grade;
}
int main()
{
    int n, c;
    cin >> n >> c;
    Student* stu = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].name >> stu[i].grade;
    }
    switch (c)
    {
    case 1:sort(stu, stu + n, compareid); for (int i = 0; i < n; i++) cout << stu[i].id <<" "<< stu[i].name <<" "<< stu[i].grade << endl; break;
    case 2:sort(stu, stu + n, compareName); for (int i = 0; i < n; i++) cout << stu[i].id <<" "<< stu[i].name <<" "<< stu[i].grade << endl; break;
    case 3:sort(stu, stu + n, compareGrade); for (int i = 0; i < n; i++) cout << stu[i].id <<" "<< stu[i].name <<" "<< stu[i].grade << endl; break;
    default:
        break;
    }
    return 0;
}

