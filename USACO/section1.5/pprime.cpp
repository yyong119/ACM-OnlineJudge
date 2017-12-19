#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");


int a, b;
int sum = 0;
int en[] = {1, 10, 100, 1000,10000, 100000};
int opp[100005];

void opposite()
{
    int num, temp;
    for(int i = 1;i <= 10000; ++i)
    {
        num = i;
        temp = 0;
        while(num > 0)
        {
            temp = temp * 10 + num % 10;
            num /= 10;
        }
        opp[i] = temp;
    }
}
void isprim(int x)
{
	if(x<a||x>b)
		return;
	if((x%5==0&&x!=5)||x%3==0)
		return;
	if(x%11==0&&x!=11)
		return;
	if(x%2==0)
		return;
	int m=sqrt(x);
	for(int i=2;i<=m;i++)
		if(x%i==0)
			return;
	fout << x << endl;
}


void odd(int len)
{
	len=(len-1)/2;
	int i,m,prim;
	for(i=en[len-1];i<en[len];i++)
		for(m=0;m<=9;m++)
		{
			prim=i*en[len+1]+m*en[len]+opp[i];
			isprim(prim);
		}
}
void even(int len)
{
	len/=2;
	int i,prim;
	for(i=en[len-1];i<en[len];i++)
	{
		prim=i*en[len]+opp[i];
		isprim(prim);
	}
}

int get_bit(int num)
{
    int n = 0;
    while(num > 0) {
        num /= 10;
        ++n;
    }
    return n;
}


int main()
{
    fin >> a >> b;
    int a_bit = get_bit(a); 
    int b_bit = get_bit(b);
    opposite();
    for(int len = a_bit; len <= b_bit; ++len)
    {
        if(len&1)
            odd(len);
        else
            even(len);
    }
    return 0;
}
