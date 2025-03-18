#include<stdio.h>
int n,m;
int w[100],p[100];
int v[100][100];
int max(int a,int b) 
{
    return (a>b)?a:b;
}
int knapsack()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		v[i][0]=0;
	}
	for(j=1;j<=n;j++)
	{
		v[0][j]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(w[i]>j)
			{
				v[i][j]=v[i-1][j];
			}
			else
			{
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
			}
		}
	}
	return v[n][m];
}
int main() {
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter weights and profits:\n");
    for(int i=1;i<=n;i++)
	{
        scanf("%d %d",&w[i],&p[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d",&m);
    int max_profit=knapsack();
    printf("Maximum Profit: %d\n",max_profit);
    return 0;
}
