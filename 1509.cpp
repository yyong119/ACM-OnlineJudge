#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

bool isLeapYear(int year) {

     int temp = year % 400;
     if (temp == 0) return true;
     else {
         temp = year % 4;
         int temp1 = year % 100;
         if (temp == 0 && temp1 != 0) return true;
         else return false;
    }
}

int days(bool leap, int month) {

    switch (month) {
         case 1:
             return 0;
         case 2:
             return 31;
         case 3:
             return leap ? 60 : 59;
         case 4:
             return leap ? 91 : 90;
         case 5:
             return leap ? 121 : 120;
         case 6:
             return leap ? 152 : 151;
         case 7:
             return leap ? 182 : 181;
         case 8:
             return leap ? 213 : 212;
         case 9:
             return leap ? 244 : 243;
         case 10:
             return leap ? 274 : 273;
         case 11:
             return leap ? 305 : 304;
         case 12:
             return leap ? 335 : 334;
    }
}

int monthDays(bool leap, int month) {

     switch (month) {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
             return 31;
         case 4:
         case 6:
         case 9:
         case 11:
         return 30;
         case 2:
             return leap ? 29 : 28;
    }
}

int main() {
	int month, week, day, year1, year2, leapCount(0);
	cin >> month >> week >> day >> year1 >> year2;
	for (int i = 1850; i < year1; i++)
		if (isLeapYear(i)) leapCount++;
	for (int i = year1; i <= year2; i++) {
		bool leap = isLeapYear(i);
		int totalDays = (i - 1850) * 365 + leapCount + days(leap, month);
		int weekDay = totalDays % 7 + 2;
		int weekCount = day < weekDay ? 1 : 2;
		int ans = 8 - weekDay + (week - weekCount) * 7 + day;
		if (ans <= monthDays(leap, month)) {
			cout << i << "/";
			if (month < 10)
				cout << 0;
			cout << month << "/";
			if (ans < 10)
				cout << 0;
			cout << ans << endl;
		}
		else cout << "none" << endl;
		if (leap) leapCount++;
	}
	return 0;
}