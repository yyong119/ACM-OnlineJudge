#include <stdio.h>
#include <string.h>

int main()
{
    char m[555],n[555];
    int i,len_m,len_n;
    int a[555]={0},b[555]={0};
    scanf("%s",m);
    len_m =strlen(m);
    for(i=0;i<=len_m -1;i++)
        a[i]=m[len_m -1 -i]-'0';
    scanf("%s",n);
    len_n=strlen(n);
    for(i=0;i<=len_n -1;i++)
        b[i]=n[len_n -1 -i]-'0';
    if(len_m < len_n)	
    { 
    	printf("-");
    	for(i=0;i<len_n;i++)
    	{
   			b[i]-=a[i];
   			if(b[i]<0)
   			{
   				b[i]+=10;
   				b[i+1]--;
			}
		}
		i=len_n-1;
		while(b[i]==0)	i--; 
    	for(;i>=0;i--)
        	printf("%d",b[i]);
	}
	else
	{
    	for(i=0;i<len_m;i++)
    	{
   			a[i]-=b[i];
   			if(a[i]<0)
   			{
   				a[i]+=10;
   				a[i+1]--;
			}
		}
		i=len_m-1;
		while(a[i]==0)	i--; 
    	for(;i>=0;i--)
        	printf("%d",a[i]);
    }
    return 0;
}