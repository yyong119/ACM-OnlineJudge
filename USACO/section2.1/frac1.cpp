#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("frac1.in");
ofstream fout("frac1.out");

struct frac
{
    int fenzi;
    int fenmu;
}; 
frac a[25000];
int N;
int num = 0;

void quick_sort(int low, int high)
{
    if(low >= high)
        return;
    int first = low;
    int last = high;
    frac key = a[first];
    while(first < last)
    {
        while(first < last && (a[last].fenzi * key.fenmu >= key.fenzi * a[last].fenmu))
            --last;
        a[first] = a[last];
        while(first < last && (a[first].fenzi * key.fenmu <= key.fenzi * a[first].fenmu))
            ++first;
        a[last] =a[first];
    }
    a[first] = key;
    quick_sort(low, first - 1);
    quick_sort(first + 1, high);
}

bool is_simply(int i, int j)
{
    if (i % j == 0 && j == 1) return true;
	if (i % j == 0 && j != 1) return false;
	return is_simply(j, i % j);
}
int main()
{
    fin >> N;
    for(int i = 2; i <= N; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            if(is_simply(i, j))
            {
                ++num;
                a[num].fenzi = j;
                a[num].fenmu = i;
                //cout << a[num].fenzi << " " << a[num].fenmu << endl;
            }
        }
    }
    //for(int i = 1; i <= num; ++i)
      //  cout << a[i].fenzi << "/" << a[i].fenmu << endl;
    quick_sort(1, num);
    fout << "0/1" << endl;
    for(int i = 1; i <= num; ++i)
        fout << a[i].fenzi << "/" << a[i].fenmu << endl;
    fout << "1/1" << endl;
    //cout << "fdsf" << endl;
    return 0;
}