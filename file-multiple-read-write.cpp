#include <iostream>
#include<array>
using namespace std;

class Validator
{
public:
    char checkMark(int mark)
    {
        if (mark >= 80)
        {
            return 'A';
        }
        else if (mark >= 60)
        {
            return 'B';
        }
        else if (mark >= 50)
        {
            return 'C';
        }
        else if (mark >= 40)
        {
            return 'D';
        }
        else
        {
            return 'E';
        }
    }
};

class Student
{
private:
    int id;
    string name;
    int mark;
    char grade;

public:
    void getStudent()
    {
        cout << "Enter student's ID: ";
        cin >> id;
        cout << "Enter student's name: ";
        cin >> name;
        cout << "Enter student's mark ";
        cin >> mark;
        Validator validator;
        grade = validator.checkMark(mark);
    }

    void showStudent()
    {
        cout << id << " " << name << " " << mark << " " << grade << endl;
    }

    Student()
    {
        id = 0;
        name = "";
        mark = 0;
        grade = '\0';
    }
    Student(int i, string n, int m)
    {
        id = i;
        name = n;
        mark = m;
        Validator validator;
        grade = validator.checkMark(m);
    }
};

Student S[10];
int count;


void inputStudent()
{
   
    int i = 0;

    cout << "Enter number of students :";
    cin >> ::count;
    if (::count < 10)
    {
        do
        {
            S[i].getStudent();
            i++;
        } while (i < ::count);
    }
    else
    {
        ::cout << "Array overflow";
        throw("over flow");
    }
}


void displayStudent() {
    for(int i = 0; i < ::count; i++) {
        S[i].showStudent();
    }
}


int main()
{
    char ans;
    int choice;

    do {

    cout << "---Operation Menu---";
    cout << endl
         << "1: Input Operation 🥳 ";
    cout << endl
         << "2: Output Operation 🗣️";
    cout << endl
         << "3: Exit 🧨" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        inputStudent();
        break;
    case 2:
        displayStudent();
        break;
    case 3:
        cout << "End of program";
        break;
    default:
        cout << "Invalid";
    }

    cout << "Do you want to continue (Y/N) ?";
    cin >> ans;
    } while( ans == 'y' || ans == 'Y');

    return 0;
}
