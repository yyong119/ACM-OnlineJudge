#include <stdio.h>
#include <string.h>

int main()
{
    char m[555],n[555],temp[555];
    int i,j,len_m,len_n;
    int a[555]={0},b[555]={0},c[1111]={0};
    scanf("%s",m);
    scanf("%s",n);
    if(strlen(m)<strlen(n))
    {
    	strcpy(temp,m);
		strcpy(m,n);
        strcpy(n,temp);
	}
    len_m =strlen(m);
    for(i=0;i<=len_m -1;i++)
        a[i]=m[len_m -1 -i]-'0';
    len_n=strlen(n);
    for(i=0;i<=len_n -1;i++)
        b[i]=n[len_n -1 -i]-'0';
    for(i=0;i<len_n;i++)
    	for(j=0;j<len_m;j++)
    		c[i+j]+=a[j]*b[i];
    for(i=0;i<2*len_m;i++)
    	if(c[i]>=10)
    	{
    		c[i+1]+=c[i]/10;
    		c[i]%=10;
		}
	i=2*len_m;
	while(c[i]==0)	i--;
	if(i<0)	printf("0");
	else	
	{
		for(;i>=0;i--)
			printf("%d",c[i]);
	}
    return 0;
}