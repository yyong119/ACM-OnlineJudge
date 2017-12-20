#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("preface.in");
ofstream fout("preface.out");

int counter[7];

void count(int x)
{
    int a, b, c, d, tmp = x;
    a = tmp / 1000; tmp %= 1000;
    b = tmp / 100; tmp %= 100;
    c = tmp / 10; tmp %= 10;
    d = tmp;
    //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    counter[6] += a;
    if(b == 9) {counter[6] += 1; counter[4] += 1;}
    if(b == 4 || b == 5) {counter[4] += 5 - b; counter[5] += 1;}
    if(b >= 1 && b <= 3) {counter[4] += b;}
    if(b >= 6 && b <= 8) {counter[4] += b - 5; counter[5] += 1;}
    if(c == 9) {counter[4] += 1; counter[2] += 1;}
    if(c == 4 || c == 5) {counter[3] += 1; counter[2] += 5 - c;}
    if(c >= 1 && c <= 3) {counter[2] += c;}
    if(c >= 6 && c <= 8) {counter[3] += 1; counter[2] += c - 5;}
    if(d == 9) {counter[2] += 1; counter[0] += 1;}
    if(d == 4 || d == 5) {counter[1] += 1; counter[0] += 5 - d;}
    if(d >= 1 && d <= 3) {counter[0] += d;}
    if(d >= 6 && d <= 8) {counter[1] += 1; counter[0] += d - 5;}
}
int main()
{
    int N; fin >> N;
    for(int i = 1; i <= N; ++i) 
        count(i);
    if(counter[0] != 0) fout << "I " << counter[0] << endl;
    if(counter[1] != 0) fout << "V " << counter[1] << endl;
    if(counter[2] != 0) fout << "X " << counter[2] << endl;
    if(counter[3] != 0) fout << "L " << counter[3] << endl;
    if(counter[4] != 0) fout << "C " << counter[4] << endl;
    if(counter[5] != 0) fout << "D " << counter[5] << endl;
    if(counter[6] != 0) fout << "M " << counter[6] << endl;
    return 0;
}