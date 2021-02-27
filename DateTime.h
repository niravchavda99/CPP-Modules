#ifndef DATE_TIME
#define DATE_TIME
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

const int MONTH_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
    int dd, mm, yy;

    void initialize()
    {
        std::time_t t = std::time(0);
        std::tm *now = std::localtime(&t);
        dd = now->tm_mday;
        mm = now->tm_mon + 1;
        yy = now->tm_year + 1900;
    }

    static bool isLeap(int year)
    {
        return (year % 400 == 0) ? true : (year % 100 == 0) ? false
                                                            : (year % 4 == 0);
    }

    bool isValid(int dd, int mm, int yy)
    {
        bool valid = false, leap;

        leap = isLeap(yy);
        if (mm == 2 && leap)
        {
            if (dd > 0 && dd <= MONTH_DAYS[1] + 1)
                valid = true;
        }
        else if (mm == 2 && !leap)
        {
            if (dd > 0 && dd <= MONTH_DAYS[1])
                valid = true;
        }
        else if (mm > 0 && mm < 13)
        {
            if (dd > 0 && dd <= MONTH_DAYS[mm - 1])
                valid = true;
        }
        return valid;
    }

    static int getMonthDays(int month, int year)
    {
        if (month < 1 || month > 12)
            return NULL;
        if (month == 2)
            return isLeap(year) ? 29 : 28;
        return MONTH_DAYS[month - 1];
    }

public:
    Date()
    {
        initialize();
    }

    Date(int dd, int mm, int yy)
    {
        if (isValid(dd, mm, yy))
        {
            this->dd = dd;
            this->mm = mm;
            this->yy = yy;
        }
        else
            initialize();
    }

    void operator++()
    {
        dd++;
        if (dd > getMonthDays(mm, yy))
        {
            mm++;
            dd = 1;
        }
        if (mm > 12)
        {
            mm = 1;
            yy++;
        }
    }

    void operator++(int dummy)
    {
        dd++;
        if (dd > getMonthDays(mm, yy))
        {
            mm++;
            dd = 1;
        }
        if (mm > 12)
        {
            mm = 1;
            yy++;
        }
    }

    void operator--()
    {
        dd--;
        if (dd < 1)
            mm--;
        if (mm < 1)
        {
            mm = 12;
            yy--;
        }
        dd = getMonthDays(mm, yy);
    }

    void operator--(int dummy)
    {
        dd--;
        if (dd < 1)
        {
            mm--;
            if (mm < 1)
            {
                mm = 12;
                yy--;
            }
            dd = getMonthDays(mm, yy);
        }
    }

    Date operator+(int daysToAdvance) //Overloading + Operator
    {
        Date d = Date(dd, mm, yy);

        for (int i = 0; i < daysToAdvance; i++)
            d++;

        return d;
    }

    Date operator-(int daysToDecrease) //Overloading - Operator
    {
        Date d = Date(dd, mm, yy);

        for (int i = 0; i < daysToDecrease; i++)
            d--;

        return d;
    }

    void operator+=(int daysToAdvance) //Overloading += Operator
    {
        for (int i = 0; i < daysToAdvance; i++)
            (*this)++;
    }

    void operator-=(int daysToDecrease) //Overloading -= Operator
    {
        for (int i = 0; i < daysToDecrease; i++)
            (*this)--;
    }

    friend ostream &operator<<(ostream &out, Date &date)
    {
        out << setfill('0') << setw(2) << date.dd << "-" << setfill('0') << setw(2) << date.mm << "-" << date.yy;
        return out;
    }
};

class Time
{
    int hh, mm, ss;

    void initialize()
    {
        std::time_t t = std::time(0);
        std::tm *now = std::localtime(&t);
        this->hh = now->tm_hour;
        this->mm = now->tm_min;
        this->ss = now->tm_sec;
    }

    bool isValid(int hh, int mm, int ss)
    {
        return ((hh >= 0 && hh < 24) && (mm >= 0 && mm < 60) && (ss >= 0 && ss < 60));
    }

    void increment()
    {
        ss++;
        if (ss > 59)
        {
            ss = 0;
            mm++;
            if (mm > 59)
            {
                mm = 0;
                hh++;
                if (hh > 23)
                    hh = 0;
            }
        }
    }

    void decrement()
    {
        ss--;
        if (ss < 0)
        {
            ss = 59;
            mm--;
            if (mm < 0)
            {
                mm = 59;
                hh--;
                if (hh < 0)
                {
                    hh = 23;
                }
            }
        }
    }

public:
    Time()
    {
        initialize();
    }

    Time(int hh, int mm, int ss)
    {
        if (isValid(hh, mm, ss))
        {
            this->hh = hh;
            this->mm = mm;
            this->ss = ss;
        }
        else
            initialize();
    }

    void operator++()
    {
        increment();
    }

    void operator++(int dummy)
    {
        increment();
    }

    void operator--()
    {
        decrement();
    }

    void operator--(int dummy)
    {
        decrement();
    }

    friend ostream &operator<<(ostream &out, Time &t)
    {
        out << setfill('0') << setw(2) << t.hh << ":" << setfill('0') << setw(2) << t.mm << ":" << setfill('0') << setw(2) << t.ss;
        return out;
    }
};

#endif