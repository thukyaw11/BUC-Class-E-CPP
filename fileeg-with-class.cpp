#include <iostream>
#include <fstream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    void putData()
    {
        cout << "Enter name ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    void showData()
    {
        cout << name << "    " << age << endl;
    }
    void putName(string s)
    {
        name = s;
    }
    void putAge(int a)
    {
        age = a;
    }
};

int main()
{
    char ans;
    Person p;
    ofstream classEFile;
    classEFile.open("students.txt");
    do
    {
        p.putData();
        classEFile << p.getName() << endl
                   << p.getAge() << endl;
        cout << "Do you want to continue";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    classEFile.close();

    Person p1;
    string s;
    int a;

    ifstream infile;
    infile.open("students.txt");

    if (infile.is_open())
    {

        while (getline(infile, s))
        {
            infile >> a;
            infile.ignore();
            p1.putName(s);
            p1.putAge(a);
            p1.showData();
        }
    } else {
        cout << "unable to open";
    }
    // if (infile.is_open()) {
    //     while (getline(infile, line)) {
    //         cout << line << endl;
    //     }
    //     infile.close();
    // } else {
    //     cout << "Unable to open file";
    // }
    return 0;
}