#include "MyDate.h"
MyDate::MyDate()
{
    this->day = 1;
    this->month = 1;
    this->year = 1900;
}
MyDate::MyDate(int d, int m, int y)
{
    if (y >= 1900)
    {
        this->year = y;
    }
    else
    {
        this->year = 1900;

    }
    if (m > 0)
    {
        this->month = m;
    }
    else {
        this->month = 1;

    }
    if (isLeapYear(this->year))
    {
        if (d > 0 && d <= this->daysOFMonthINLeapYearp[this->month - 1])
        {
            this->day = d;
        }
        else {
            this->day = 1;
        }
    }
    else {

        if (d > 0 && d <= this->daysOFMonthINNormalYearp[this->month - 1])
        {
            this->day = d;
        }
        else {
            this->day = 1;
        }
    }


}

MyDate::MyDate(const MyDate& d)
{
    if (d.year >= 1900)
    {
        this->year = d.year;
    }
    else
    {
        this->year = 1900;

    }
    if (d.month > 0)
    {
        this->month = d.month;
    }
    else {

        this->month = 1;
    }
    if (isLeapYear(this->year))
    {
        if (d.day > 0 && d.day <= this->daysOFMonthINLeapYearp[this->month - 1])
        {
            this->day = d.day;
        }
        else {
            this->day = 1;
        }
    }
    else {

        if (d.day > 0 && d.day <= this->daysOFMonthINNormalYearp[this->month - 1])
        {
            this->day = d.day;
        }
        else {
            this->day = 1;
        }
    }

}
void MyDate::setDay(int d) {
    if (isLeapYear(this->year))
    {
        if (d > 0 && d <= this->daysOFMonthINLeapYearp[this->month - 1])
        {
            this->day = d;
        }
        else {
            this->day = 1;
        }
    }
    else {

        if (d > 0 && d <= this->daysOFMonthINNormalYearp[this->month - 1])
        {
            this->day = d;
        }
        else {
            this->day = 1;
        }
    }
}

void MyDate::setMonth(int m)
{
    if (m > 0)
    {
        this->month = m;
    }
    else {

        this->month = 1;
    }
}
void  MyDate::setYear(int y)
{
    if (y >= 1900)
    {
        this->year = y;
    }
    else
    {
        this->year = 1900;

    }
}
int MyDate::getDay()
{
    return this->day;
}
int MyDate::getMonth()
{
    return this->month;
}
int MyDate::getYear()
{
    return this->year;
}
void MyDate::displayDate()
{
    cout << this->monthNames[this->month - 1] << " " << this->day << ", " << this->year << "\n";
}
string MyDate::getDate()
{
    return (this->monthNames[this->month - 1]) + " " + to_string(this->day) + ", " + to_string(this->year) + "\n";

}
bool MyDate::isLeapYear(int year)
{
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}