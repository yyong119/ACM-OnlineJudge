#include <iostream>
#include <cstdio>
using namespace std;
 
typedef unsigned long long ULL;
 
 
int number[100000 + 10]; //下标是流水id 内容是身上的编号
 
int front[100000 + 10];//流水id的操作
int nex[100000 + 10];//流水id的操作
					 //模拟法
void out(int x) {
	nex[front[x]] = nex[x];
	front[nex[x]] = front[x];
}
 
void in(int x, int w) { //此处的W指的是流水id
	nex[w] = nex[x];
	nex[x] = w;
	front[nex[w]] = w;
	front[w] = x;
}
 
int main(int argc, char const *argv[])
{
	int M;//猴子的数量M
	int m; //操作的数量m
	cin >> M >> m;
	for (int i = 1; i <= M; ++i)
	{
		number[i] = i;//第i个猴子身上的编号是i
		front[i] = (i == 1) ? M : i - 1;
		nex[i] = (i == M) ? 1 : i + 1;
	}
	int cur = 1;//接下来要报1的猴子编号
	int cnt = M;//还有多少只猴子
	int K;//数到K要进行操作
	ULL res = ((1 + M)*M) / 2;
	for (int i = 0; i < m; ++i)//m次操作
	{
		int flag;
		scanf("%d", &flag);
		if (flag == 0) {//要开始删除猴子
			scanf("%d", &K);
			K %= (cnt);
			if (K == 0)    K += cnt;
			for (int i = 0; i < K - 1; ++i)
				cur = nex[cur];//报数的过程
			out(cur);
			res -= number[cur];//减少剩余猴子所组成的编号之和
			cur = nex[cur];
			cnt--;//出去一只猴子
 
		}
		else {
			//不删除 只加入
			int W;
			scanf("%d %d", &K, &W);
			K %= (cnt);
			number[++M] = W;//流水ID
			if (K == 0)    K += cnt;
			for (int i = 0; i < K - 1; ++i)
				cur = nex[cur];//报数的过程
			in(cur, M);//cur的后面加入一个W
			res += W;
			cur = M;
			cnt++;//加入一只猴子
		}
 
	}
 
	cout << res << endl;
	return 0;
}