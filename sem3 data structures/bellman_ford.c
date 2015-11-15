#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
struct graph{
	int v;
	int arr[50][50];
}g;
void add_edge(int u, int v, int d){
	g.arr[u][v] = d;
	return;
}


void set_source(int i, int d[], int p[]){
	d[i] = 0;
	p[i] = 0;
}
int min2(int a, int b){
	return (a<b)?a:b;
}

int change;
bool bellman_ford(int d[], int p[], int count){
	if(count > g.v) 					//to return after v iterations
	{
		if(change==0)						//will check the change value of the v'th iteration
			return true;
		else
			return false;
	}
	// v-1 iterations are only needed but extra one iteration is done to check whether distance array changes after v-1 iterations
	change = 0;				//change = 0
	int i,j;
	for(i=1;i<=g.v;i++){
		if(p[i] != -1){				//checking whether it has already been reached or not
	//initially only source has 0 in it's parent - so in the first iteration only source and the following elements are checked in the first iteration.
			for(j=1;j<=g.v;j++){
				//loop to check for neigbours
				if(g.arr[i][j]!=0){
					if(d[j]==INT_MAX){			//if it has never been visited before
						d[j] = d[i]+g.arr[i][j];
						p[j] = i;
						change++;
					}
					else{						//has been visited before
						int m = min2(d[j],d[i]+g.arr[i][j]);
						if(m!=d[j]){				//there is a new minimum through i
							d[j] = d[i]+g.arr[i][j];
							p[j] = i;
							change++;
						}
					}
				}
			}
		}
	}
	if(change==0)	return true;
	else			return bellman_ford(d,p,count+1);
}
int main()
{
	int i,j;
	// printf("Enter the number of vertices: ");
    // int vertices;
    // scanf("%d",&vertices);
    // g.v = vertices;
    // printf("Enter number of edges: ");
    // int edges;
    // scanf("%d",&edges);
    // for(int i=0;i<edges;i++){
    //     printf("enter vertices in the correct order (u -> v) along with their weights : ");
    //     int u,v,d;
    //     scanf("%d %d %d",&u,&v,&d);
    //     addEdge(u,v,d);
    // }
	g.v = 6;				//number of vertices
	for(i=0;i<=g.v;i++){
		for(j=1;j<g.v;j++)
			g.arr[i][j] = 0;				//initializing adj matrix as 0
	}
	add_edge(1,2,10);
	add_edge(1,3,8);
	add_edge(3,5,1);
	add_edge(5,2,-4);
	add_edge(2,6,2);
	add_edge(6,4,-2);
	add_edge(4,2,1);
	add_edge(5,6,-1);
	int count = 1;
	int distance[g.v+1];					//=32768 in the beginning
	int parent[g.v+1];						//=-1 in the beginning
	for(i=1;i<=g.v;i++){
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
	set_source(1,distance, parent);
	if(bellman_ford(distance,parent,count)){
		for(i=1;i<=g.v;i++){
			printf("%d ",distance[i]);
		}
		printf("\n");
		for(i=1;i<=g.v;i++){
			printf("%d ",parent[i]);
		}
	}
	else{
		printf("There is a cycle with negative sum weight\n");
	}
	return 0;
} 