#include <iostream>
#include<string>
using namespace std;
int getDaysBeforeThisMonth(int month);
int daysIntoYear(int year, int month, int day);

enum daysperMonth{
	JAN = 31, FEB = 28, MAR = 31,
        APR = 30, MAY = 31, JUN = 30,
        JUL = 31, AUG = 31, SEP = 30,
        OCT = 31, NOV = 30, DEC = 31
};

int getDaysBeforeThisMonth(int month){
    int numDays = 0;
    switch (month){
    case (12):
        numDays += NOV;
    case (11):
        numDays += OCT;
    case (10):
        numDays += SEP;
    case (9):
        numDays += AUG;
    case (8):
        numDays += JUL;
    case (7):
        numDays += JUN;
    case (6):
        numDays += MAY;
    case (5):
        numDays += APR;
    case (4):
        numDays += MAR;
    case (3):
        numDays += FEB;
    case (2):
        numDays += JAN;
    case (1):
        numDays += 0;
    }
    return numDays;
}

int addLeapYearDay(int year, int month){
    if (month >= 3){
        if (((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
            return 1;
        return 0;
    }
    return 0;
}

int daysIntoYear(int year, int month, int day){
    int numDays = getDaysBeforeThisMonth(month);
    numDays += day;
    numDays += addLeapYearDay(year, month);
    return numDays;
}

int main()
{
    /*Funny testing*/
    int y1 = 2000, m1 = 1, d1 = 1;
    int y2 = 2015, m2 = 3, d2 = 31;
    int day1 = 0, day2 = 0;
    day1 = daysIntoYear(y1,m1,d1);
    if(y1 == y2){
        day2 = daysIntoYear(y2,m2,d2);
    }else{
        day2 = daysIntoYear(y1,12,31);
        for(int i = 1; i < y2-y1; i++){
            day2 +=365;
            day2 +=addLeapYearDay(y1+i,12);
        }
        day2 += daysIntoYear(y2,m2,d2);
    }
    return day2-day1;
}
