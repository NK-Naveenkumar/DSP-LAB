// C Program for Floyd Warshall 
#include<stdio.h> 

#define V 6 

// A large value to represent infinite
#define INF 100 

// A function to print the solved Adjacency matrix 
void print_AdjMatrix(int dist[][V]); 

void floyd_Warshall (int graph[][V]) 
{ 
	int dist[V][V], i, j, k; 
	// intialize the distances same as graph distance
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 
	for (k = 0; k < V; k++) 
	{ 
		// picking one by one as source 
		for (i = 0; i < V; i++) 
		{ 
	    // Picking all vertices as destination for the above picked source 
			for (j = 0; j < V; j++) 
			{ 
		// if k as intermediate is shorter,then update the value of dist[i][j] 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		}
		printf("After %d iteration:\n",k+1);
		print_AdjMatrix(dist); 
	} 
	printf ("This Final Adjacency matrix shows shortest path between Nodes\n"); 
	print_AdjMatrix(dist); 
	
} 

void print_AdjMatrix(int dist[][V]) 
{ 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				printf("%5s", "INF"); 
			else
				printf ("%5d", dist[i][j]); 
		} 
		printf("\n"); 
	} 
} 

int main() 
{ 

	int graph[V][V] = { {0, 5, 6, INF, INF, INF}, 
						{5, 0, 8, 3, 4, INF}, 
						{6, 8, 0, INF, 6, INF}, 
						{INF, 3, INF, 0, 3, 7},
						{INF, 4, 6, 3, 0, 7},
						{INF, INF, INF, 7, 7, 0},
					}; 
	floyd_Warshall(graph); 
	return 0; 
} 
