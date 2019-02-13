#include<stdio.h>

int score()
{
	int n;
	scanf("%d",&n);
	int l[n];int u[n];int scores[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&l[i],&u[i]);
		scores[i]=0;
	}

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(l[i]<l[j] && u[i]>u[j])
			{
				scores[i]+=2;
				
			}
			else if(l[i]>l[j] && u[i]<u[j])
			{
				scores[j]+=2;
			}

			else
			{
				scores[i]+=1;
				scores[j]+=1;
			}
		}
	}

	print_score(scores,n);
}

int print_score(int scores[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",scores[i]);
	}
	printf("\n");
}

int main()
{
		score();

}

