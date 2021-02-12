#include<stdio.h>
#include<stdlib.h>
int parent[20];
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int unin(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void main()
{
	printf("\nEnter the no. of vertices:");
	int n;
	scanf("%d",&n);
	int cost[n][n];
	int i,j,k,a,b,u,v,ne=1;
    int min,mincost=0;
	printf("\nEnter cost matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree using kruskal's Algorithm are\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(unin(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nMinimum cost = %d\n",mincost);

}