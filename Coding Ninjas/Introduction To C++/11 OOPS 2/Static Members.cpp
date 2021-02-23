#include <iostream>

using namespace std;

class Student
{
    static int totalStudents;

public:
    int rollNumber;
    int age;

    Student()
    {
        totalStudents++;
    }

    int getRollNumber()
    {
        return rollNumber;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }
};

int Student ::totalStudents = 0;

int main()
{
    Student s1;

    cout << s1.getRollNumber() << endl;

    Student s2, s3, s4, s5;

    cout << Student ::getTotalStudents() << endl;

    return 0;
}