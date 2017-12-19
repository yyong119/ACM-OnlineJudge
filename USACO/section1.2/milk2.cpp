#include<fstream>
#include<iostream>
using namespace std;
struct Node
{
    int p, q;
};
Node set(int pt, int qt)
{
	Node a;
	a.p = pt;
	a.q = qt;
	return a;
}
Node a[5005];
void sort(int N)
{
	int i, j;
	bool flag;
	for(i = 1; i < N;++i)
	{
		flag = false;
		for(j = 0; j < N - i; ++j)
			if(a[j + 1].p < a[j].p)
			{
				Node tmp;
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
				flag = true;
			}
		if(!flag)
			break;
	}
}
ifstream fin("milk2.in");
ofstream fout("milk2.out");
 
int main()
{
    int N;
    fin >> N;
    for(int i = 0; i < N; ++i)
	{
		int num1, num2;
		fin >> num1 >> num2;
		a[i] = set(num1, num2);
	}
	sort(N);
	int yes = 0, no = 0, start = 0, flag = 1, max = 0;
	for(int i = 0; i < N; ++i)
	{
	    if(a[i].q > max)
            max = a[i].q;
		if(a[i + 1].p > max)
		{
			if(a[i + 1].p - max > no)
				no = a[i + 1].p - max;
			if(max - a[start].p > yes)
				yes = max - a[start].p;
			start = i + 1;
			flag = 0;
		}
	}
	if(flag != 0)
		yes = max - a[0].p;
	fout << yes << ' ' << no << endl;
	return 0;
}