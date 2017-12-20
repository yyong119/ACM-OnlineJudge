#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int integer[100005];
int r[100005];
int f[100005], pos[100005];
int int_length = 0;
int r_length = 0;
int cir_start;
int caseNum = 0;
int N, D;

void get_int()
{
    int n = N / D;
    if(n == 0) {
        integer[int_length++] = 0;
    }
    while(n > 0) {
        integer[int_length++] = n % 10;
        n /= 10;
    }
}

int main()
{
    fin >> N >> D;
    get_int();
    int quo = N / D;
    int remain = N - quo * D;
    //cout << remain << endl;
    f[remain] = 1;
    pos[remain] = 0;
    //cout << remain << endl;
    if(remain == 0)
        caseNum = 1;
    else
    {
        while(1)
        {
            remain *= 10;
            
            r[r_length++] = remain / D;
            remain = remain % D;
            //cout << remain << endl;
            if(remain == 0)
            {
                caseNum = 2;
                break;
            }

            else if(f[remain])
            {
                cir_start = pos[remain];
                break; 
            }
            else {
                f[remain] = 1;
                pos[remain] = r_length;
            }
            
        }
    }

    int counter;
    int index = 0;
    if(caseNum == 0) {
        counter = int_length + 1 + cir_start + 2 + r_length - cir_start;
        while(index < counter) {
            ++index;
            //if(index % 76 == 0) cout << endl;
            if(index <= int_length) {
                fout << integer[int_length - index];
            }
            if(index == int_length + 1) fout << ".";
            if(index - int_length - 1 > 0 && index <= int_length + 1 + cir_start) {
                fout << r[index - int_length - 2];
            }
            if(index == int_length + 1 + cir_start + 1) fout << "(";
            if(index > int_length + 1 + cir_start + 1 && index <= int_length + 1 + 1 + r_length) {
                fout << r[index - int_length - 3];
            }
            if(index == counter) fout << ")";
            if(index % 76 == 0 || index == counter) fout << endl;
        }
    }    
    if(caseNum == 1) {
        counter = int_length + 2;
        while(index < counter) {
            ++index;
            if(index <= int_length) fout << integer[int_length - index];
            if(index == int_length +1) fout << ".";
            if(index == int_length + 1) fout << "0";
            if(index % 76 == 0 || index == counter) fout << endl;
        }
    }

    if(caseNum == 2) {
        counter = int_length + 1 + r_length;
        while(index < counter) {
            ++index;
            if(index <= int_length) fout << integer[int_length - index];
            if(index == int_length + 1) fout << ".";
            if(index > int_length + 1) fout << r[index - int_length - 2];
            if(index % 76 == 0 || index == counter) fout << endl;
        }
    }
   
    return 0;
}