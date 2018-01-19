#include <iostream>
using namespace std;
int monthDays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct date {
    int year;
    int month;
    int day;
    int dayForWeek;
};


int getWeek(const date &d) {
    int m = d.month, y = d.year;
    if(d.month <= 2) {
        m += 12;
        --y;
    }
    int dayForWeek = (d.day + 2 + 2 * m + 3 * (m + 1) / 5 - 1 + y + y / 4 - y / 100 + y / 400) % 7;
    return dayForWeek;
}

int countDays(const date& d1, const date& d2) {
    bool isLeap(int);
    int count = 0, month, year;
    if(d1.year == d2.year)
        if(d1.month == d2.month)
            return (d2.day - d1.day + 1);
        else  {
            count = monthDays[d1.month] - d1.day + 1 + d2.day;
            for (month = d1.month + 1; month < d2.month; ++month) count += monthDays[month];
            if (2 >= d1.month && 2 < d2.month && isLeap(d1.year)) ++count;
            return count;
        }
    else {
        date d3 = {d1.year, 12, 31}, d4 = {d2.year, 1, 1};
        count = countDays(d1, d3) + countDays(d4, d2);
        for(year = d1.year + 1; year < d2.year; ++year) {
            count += 365;
            if(isLeap(year)) ++count;
        }
        return count;
    }
}

bool isLeap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool betwDays(date &d1,date &d2,date &d3) {

    if (d1.year < d3.year && d3.year < d2.year) return true;
    else if(d3.year < d1.year || d3.year > d2.year) return false;
    else if(d3.year == d1.year)
        if(d1.year == d2.year) {
            if(d1.month < d3.month && d3.month < d2.month) return true;
            else if(d3.month < d1.month || d3.month > d2.month) return false;
            else if(d3.month == d1.month)
                if(d1.month == d2.month)
                    if(d1.day <= d3.day && d3.day <= d2.day)return true;
                    else return false;
                else
                    if(d3.day >= d1.day) return true;
                    else return false;
            else
                if(d3.day <= d2.day)return true;
                else return false;
        }
        else {
            date d4 = {d1.year, 12, 31};
            return (betwDays(d1, d4, d3));
        }
    else {
        date d4 = {d2.year, 1, 1};
        return (betwDays(d4, d2, d3));
    }
}

void dayUp(date &d) {
    bool isLeap(int);
    ++d.day;
    if(d.day > monthDays[d.month] + (d.month == 2 && isLeap(d.year))) {
        d.day=1;
        ++d.month;
        if(d.month > 12) {
            d.month = 1;
            ++d.year;
        }
    }
    ++d.dayForWeek;
    if(d.dayForWeek > 6) d.dayForWeek = 0;
}

int main() {

    date d1, d2, dtemp;
    char eat;
    int n, *p, i, j, daysNum, holidays, year;
    cin >> n;
    p = new int[n];
    for(i = 0; i < n; ++i) {
        cin >> d1.year >> eat >> d1.month >> eat >> d1.day;
        cin >> d2.year >> eat >> d2.month >> eat >> d2.day;
        d1.dayForWeek = getWeek(d1);
        d2.dayForWeek = getWeek(d2);
        daysNum = countDays(d1, d2);
        holidays = daysNum / 7 * 2;
        for(dtemp = d1, j = 0; j < daysNum % 7; ++j) {
            if(dtemp.dayForWeek == 0 || dtemp.dayForWeek == 6) ++holidays;
            dayUp(dtemp);
        }
        for(year = d1.year; year <= d2.year; ++year) {
            dtemp.year = year;
            dtemp.month = dtemp.day = 1;
            dtemp.dayForWeek = getWeek(dtemp);
            if(year != d1.year && year != d2.year || betwDays(d1, d2, dtemp))
            holidays += (dtemp.dayForWeek != 0 && dtemp.dayForWeek != 6);
            dtemp.month = 5;
            dtemp.day = 1;
            dtemp.dayForWeek = getWeek(dtemp);
            for(j = 0; j < 3; ++j) {
                if(year != d1.year && year != d2.year || betwDays(d1, d2, dtemp))
                    holidays += (dtemp.dayForWeek != 0 && dtemp.dayForWeek != 6);
                dayUp(dtemp);
            }
            dtemp.month = 10;
            dtemp.day = 1;
            dtemp.dayForWeek = getWeek(dtemp);
            for(j = 0; j < 7; ++j) {
                if(year != d1.year && year != d2.year || betwDays(d1, d2, dtemp))
                    holidays += (dtemp.dayForWeek != 0 && dtemp.dayForWeek != 6);
                dayUp(dtemp);
            }
        }
        p[i] = daysNum - holidays;
    }
    for(i = 0; i < n; ++i) cout << p[i] << endl;
    delete [] p;
    return 0;
}