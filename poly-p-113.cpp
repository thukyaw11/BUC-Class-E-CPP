#include<iostream>
using namespace std;

class person {
    public: 
        virtual void age() = 0;
        virtual void email() = 0;

        virtual int getAge() = 0;
        virtual string getEmail() = 0;

        int a;
        string e;
};

class student: public person {
    private:
        int a;
        string e;
    public: 
        void age() {
            cout << "Enter age of student: " ;
            cin >> a;
        }
        void email() {
            cout << "Enter email of student ";
            cin >> e;
        }

        int getAge() {
            return a;
        }
        string getEmail() {
            return e;
        }
};

class staff : public person {
    private:
        int a;
        string e;
    public: 
        void age() {
            cout << "Enter age of staff";
            cin >> a;
        }
        void email() {
            cout << "Enter email of staff";
            cin >> e;
        }
        int getAge () {
            return a;
        }
        string getEmail() {
            return e;
        }
};

int main () {
    int choice;
    person *person = NULL;

    cout << "Who would you like to input 1 or 2" << endl;
    cin >> choice;
    if(choice == 1) {
        person = new student();
        person->age();
        person->email();
    } else if(choice == 2) {
        person = new staff();
        person->age();
        person->email();
    
    }

        cout << "Age: "<< person->getAge() << endl;
        cout << "Email: "<<person->getEmail() ;

    return 0;

}