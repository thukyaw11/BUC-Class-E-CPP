#include <iostream>
using namespace std;

class Car
{
private:
    int yearModel;
    string make;
    int speed;

public:
    Car(int yearM, string mke, int sp = 0)
    {
        yearModel = yearM;
        make = mke;
        speed = sp;
    }
    void setYearModel(int yearM)
    {
        yearModel = yearM;
    }
    void setMake(string mke)
    {
        make = mke;
    }
    void setSpeed(int sp)
    {
        speed = sp;
    }

    int getyearModel()
    {
        return yearModel;
    }

    string getMake()
    {
        return make;
    }

    int getSpeed()
    {
        return speed;
    }

    void accelerate()
    {
        speed += 5;
    }

    void brake()
    {
        speed -= 5;
    }
};

int main()
{
    Car toyota(2002, "Japan");

    cout << "Accelerate" << endl;
    for (int i = 0; i < 5; i++)
    {
        toyota.accelerate();
        cout << "Current Speed: " << toyota.getSpeed() << endl;
    }

    cout << "Decelerate" << endl;
    for (int i = 0; i < 5; i++)
    {
        toyota.brake();
        cout << "Current Speed: " << toyota.getSpeed() << endl;
    }
}