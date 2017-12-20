#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int N;
void dfs(int sum, int left, int step, string res)
{
    if(step == N)
    {
        if(sum + left == 0) {
            fout << res << endl;
            return;
        }
        else 
            return;
    }
    //' '空格
    if(left < 0) 
        dfs(sum, left * 10 - step - 1, step + 1, res + " " + char(step + 1 + '0'));
    else
        dfs(sum, left * 10 + step + 1, step + 1, res + " " + char(step + 1 + '0'));
    //'+'
    dfs(sum + left, step + 1, step + 1, res + "+" + char(step + 1 + '0'));

    //'-'
    dfs(sum + left, -step-1, step + 1, res + "-" + char(step + 1 + '0'));
}
int main()
{
    fin >> N;
    dfs(0, 1, 1, "1");
    //cout << int(' ') << ' ' << int('+') << " " << int('-') << " ";
    //cout << "hello" << endl;
    return 0;
}