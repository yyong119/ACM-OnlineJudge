#include <iostream>
#include <cstdio>
double a,b,c,d,e,f;
int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    printf("%.2lf%s%.2lf\n",a+c," ",b+d);
    printf("%.2lf%s%.2lf\n",a-c," ",b-d);
    printf("%.2lf%s%.2lf\n",a*c-b*d," ",a*d+b*c);
    e=(a*c+b*d)/(c*c+d*d); f=(b*c-a*d)/(c*c+d*d);
    printf("%.2lf%s%.2lf\n",e," ",f);
    e=a+c; f=b+d; a=e; b=f;
    printf("%.2lf%s%.2lf\n",a," ",b);
    e=a-c; f=b-d; a=e; b=f;
    printf("%.2lf%s%.2lf\n",a," ",b);
    e=a*c-b*d; f=a*d+b*c; a=e; b=f;
    printf("%.2lf%s%.2lf\n",a," ",b);
    e=(a*c+b*d)/(c*c+d*d); f=(b*c-a*d)/(c*c+d*d); a=e; b=f;
    printf("%.2lf%s%.2lf",a," ",b);
    return 0;
}