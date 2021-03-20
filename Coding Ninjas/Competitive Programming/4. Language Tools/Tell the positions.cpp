/* In a class there are ‘n’ number of students. 
They have three different subjects: 
Data Structures, Algorithm Design & Analysis and Operating Systems. 
Marks for each subject of all the students are provided to you. 
You have to tell the position of each student in the class. 
Print the names of each student according to their position in class. 
Tie is broken on the basis of their roll numbers. 
Between two students having same marks, 
the one with less roll number will have higher rank. 
The input is provided in order of roll number. */

#include <bits/stdc++.h>

using namespace std;

class student
{
public:
    string name;
    int marks;
    int roll;
};

bool myCompare(student a, student b)
{
    if (a.marks != b.marks)
    {
        return (a.marks > b.marks);
    }
    else
    {
        return (a.roll < b.roll);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<student> stud;

    for (int i = 0; i < n; i++)
    {
        string temp_name;
        int sub1, sub2, sub3;

        cin >> temp_name >> sub1 >> sub2 >> sub3;

        int sum = sub1 + sub2 + sub3;

        student s;
        s.name = temp_name;
        s.marks = sum;
        s.roll = i + 1;

        stud.push_back(s);
    }

    sort(stud.begin(), stud.end(), myCompare);

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << stud.at(i).name << endl;
    }

    return 0;
}
