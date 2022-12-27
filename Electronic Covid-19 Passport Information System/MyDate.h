#pragma once
#include<iostream>
#include<string>
using namespace std;
class MyDate
{
    int day;
    int month;
    int year;
    string monthNames[12] = { "January","Feburary","March","April","May","June","July","August","September","October","November","December" };
    int daysOFMonthINLeapYearp[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int daysOFMonthINNormalYearp[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
public:
    MyDate();
    MyDate(int, int, int);
    bool isLeapYear(int);
    MyDate(const MyDate&);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    void displayDate();
    string getDate();
};

