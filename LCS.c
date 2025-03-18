#include<stdio.h>
#include<string.h>
int dp[100][100];
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int lcs(char x[],char y[])
{
	int m,n;
	int i,j;
	m=strlen(x),n=strlen(y);
	for(i=0;i<=m;++i)
	{
		dp[i][0]=0;
	}
	for(j=0;j<=n;++j)
	{
		dp[0][j]=0;
	}
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(x[i-1]==y[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	for(i=0;i<=m;++i)
	{
		for(j=0;j<=n;++j)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	return dp[m][n];
}
int main()
{
	char str1[20]="acbcf",str2[20]="abcdaf";
	int length=lcs(str1,str2);
	printf("\nLENGTH OF LCS : %d\n",length);
	return 0;
}
