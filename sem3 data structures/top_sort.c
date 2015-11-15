#include <stdio.h>
#include <stdbool.h> //for the use of bool
struct graph{
    int v;
    bool adj_mat[50][50];
    // adjaceny matrix with enough space to accomodate 49 elements
}g;
int top;
// A recursive function used by topologicalSort
void topologicalSortUtil(int v, bool visited[], int stack[]){
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    bool *neighbours = g.adj_mat[v];
    int i;
    for(i=1;i<=g.v;i++){
        if(neighbours[i]==true){
            if(visited[i]==false)
                topologicalSortUtil(i,visited,stack);
        }
    }
    // Push current vertex to stack which stores result
    stack[top++] = v;
}

//adding an edge from u to v in the graph g  
//directed graph- so careful with the matrix
void addEdge(int u, int v){
    g.adj_mat[u][v]=true;   //v is u's neighbour
    return;
}



//The function to do Topological Sort. It uses recursive 
// topologicalSortUtil()
// prints a Topological Sort of the complete graph
void topologicalSort()
{
    int stack[50];      //to accomodate at max 50 elements
    top=0;              //initializing stack array

    int i;
    bool visited[50];
    // Mark all the vertices as not visited
    for(i=1;i<=g.v;i++){
        visited[i] = false;
    }

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (i = 1; i <= g.v; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, stack);

    // Print contents of stack
    while (top!=0)
    {
        top--;
        printf("%d ",stack[top]);
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    // printf("Enter the number of vertices: ");
    // int vertices;
    // scanf("%d",&vertices);
    // g.v = vertices;
    // printf("Enter number of edges: ");
    // int edges;
    // scanf("%d",&edges);
    // for(int i=0;i<edges;i++){
    //     printf("enter vertices in the correct order (u -> v) : ");
    //     int u,v;
    //     scanf("%d %d",&u,&v);
    //     addEdge(u,v);
    // }
    // printf("Following is a Topological Sort of the given graph \n");
    // topologicalSort();

    g.v = 6;

    addEdge(6, 3);
    addEdge(6, 1);
    addEdge(5, 1);
    addEdge(5, 2);
    addEdge(3, 4);
    addEdge(4, 2);

    printf("Following is a Topological Sort of the given graph \n");
    topologicalSort();

    return 0;
}