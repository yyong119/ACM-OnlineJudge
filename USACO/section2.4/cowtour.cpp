#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

const double oo= 2147400000000000000.0;   //表示不连通

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

int N;
double dis[155][155], dis_max[155];
int px[150], py[150];

double get_dis(int x1, int y1, int x2, int y2)
{
    return sqrt(double(x1-x2)*(x1-x2) + double(y1-y2)*(y1-y2));
}

void floyd()
{
    for(int k = 0; k < N; ++k)
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
            {
                 if(i != j && i != k && k != j && dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
}

int main()
{
    fin >> N;
    char str[155];
    double max_original=0.0, max_connect=oo;
    for(int i = 0; i < N; ++i)
    {
        fin >> px[i] >> py[i];
    }
    for(int i = 0; i < N; ++i)
    {
        fin >> str;
        for(int j = 0; j < N; ++j)
        {
            if(str[j] == '1')
                dis[i][j] = get_dis(px[i], py[i], px[j], py[j]);
            else
                dis[i][j] = oo;
        }
    }

    floyd(); //找出任意两点的最短距离
    //从这些距离中找出单个牧场(联通分量)单点出发最长距离
    for(int i = 0; i < N; ++i)
    {
        double tmp = 0;
        for(int j = 0; j < N; ++j)
        {
            if(dis[i][j] > tmp && dis[i][j] < oo)
                tmp = dis[i][j];
        }
        dis_max[i] = tmp;
        if(dis_max[i] > max_original)
            max_original = dis_max[i];
    }
    //连接两个不连接的牧场 计算出直径
    for(int i = 0; i < N-1; ++i)
    {
        for(int j = i+1; j < N; ++j)
        {
            if(i != j && dis[i][j] == oo)
            {
                double tmp = get_dis(px[i], py[i], px[j], py[j]);
                if(tmp + dis_max[i] + dis_max[j] < max_connect)
                    max_connect = tmp + dis_max[i] + dis_max[j];
                //printf("%f\n", max_connect);
            }
        }
    }

    //printf("%f %f\n", max_original, max_connect);
    fout <<setiosflags(ios::fixed)<<setprecision(6)<<(max_original > max_connect ? max_original:max_connect) << endl;
    return 0;
}