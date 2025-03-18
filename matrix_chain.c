#include<stdio.h>
#include<climits>
int main()
{
	int p[6]={4,10,3,12,20,7};
	int n=5;
	int i,j,k,l;
	int m[6][6];
	int s[6][6];
	for(i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<j;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("MINIMUM NUMBER OF MULTIPLICATIONS : %d\n",m[1][n]);
	printf("Matrix m:\n");
    for (i = 1; i <= n; i++) 
	{
        for (j = 1; j <= n; j++) 
		{
            if (i <= j) 
			{
			    printf("%8d ", m[i][j]);
		    }
            else 
			{
			    printf("         ");
		    }
        }
        printf("\n");
    }
    printf("\nMatrix s:\n");
    for (i = 1; i <= n; i++) 
	{
        for (j = 1; j <= n; j++) 
		{
            if (i < j) 
            {
			    printf("%8d ", s[i][j]);
		    }
            else 
            {
			    printf("         ");
		    }
        }
        printf("\n");
    }
	return 0;
}
