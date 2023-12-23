#include <iostream>
using namespace std;

class Time_1
{
protected:
    int day, week, month;

public:
    Time_1()
    {
        day = 0;
        week = 0;
        month = 0;
    }
    Time_1(int d, int w, int m)
    {
        day = d;
        week = w;
        month = m;
    }

    void setDay(int d)
    {
        day = d;
    }
    int getDay()
    {
        return day;
    }

    void setWeek(int w)
    {
        week = w;
    }
    int getWeek()
    {
        return week;
    }

    void setMonth(int m)
    {
        month = m;
    }
    int getMonth()
    {
        return month;
    }
    void inputTime()
    {
        cout << "Enter day : ";
        cin >> day;
        cout << "Enter week : ";
        cin >> week;
        cout << "Enter month : ";
        cin >> month;
    }

    void showTime()
    {
        cout << day << "days: " << week << "weeks: " << month << "month" << endl;
    }

    Time_1 timeAdd(Time_1 a)
    {
        Time_1 temp;
        temp.day = day + a.day;
        temp.week = week + a.week;
        temp.month = month + a.month;

        return temp;
    }
};

class Time_2 : public Time_1
{
public:
    Time_2(int d =0 , int w = 0, int m = 0) : Time_1(d, w, m)
    {
        day = d;
        week = w;
        month = m;
    }


    void addTime(Time_2 x, Time_2 y)
    {
        day = x.day + y.day;
        week = x.week + y.week;
        month = x.month + y.month;
    }

    int totalDay()
    {
        return (day + (week * 7) + (month * 30));
    }
};

int main()
{
    Time_2 t1;
    Time_2 t2(4, 5, 3);
    t1.setDay(10);
    t1.setWeek(3);
    t1.setMonth(3);

    Time_1 t3;
    t3.inputTime();

    t1.showTime();
    t2.showTime();
    t3.showTime();
    Time_2 t4;
    t4.addTime(t1, t2);
    t4.showTime();

    return 0;
}