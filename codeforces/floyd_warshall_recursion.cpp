#include<bits/stdc++.h>
using namespace std;
int V = 4;

int printSolution_recurse(int i,int j, vector<vector<int> > dist, int &maxim){
    maxim = (dist[i][j]>maxim)?dist[i][j]:maxim;
    return 1;
}
int printSolution_recurse_j(int i,int j, vector<vector<int> > dist, int &maxim){
    int a = (j==V)?1:printSolution_recurse(i,j,dist,maxim);
    a = (j==V)?1:printSolution_recurse_j(i,j+1,dist,maxim);
    return 1;
}
int printSolution_recurse_i(int i,int j, vector<vector<int> > dist, int &maxim){
    int a = (i==V)?1:printSolution_recurse_j(i,j,dist,maxim);
    a = (i==V)?1:printSolution_recurse_i(i+1,j,dist,maxim);
    return 1;
}
void printSolution(vector<vector<int> > dist)
{
    int maxim = 0;
    int a = printSolution_recurse_i(0,0,dist,maxim);
    cout<<maxim;
}
int floydWarshell_recurse(int k, int i, int j, vector<vector<int> > &dist){
    dist[i][j] = (dist[i][k] + dist[k][j] < dist[i][j])?dist[i][k] + dist[k][j]:dist[i][j];
    return 1;
}
int floydWarshell_recurse_j(int k, int i, int j, vector<vector<int> > &dist){
    int a = (j==V)?1:floydWarshell_recurse(k,i,j,dist);
    a = (j==V)?1:floydWarshell_recurse_j(k,i,j+1,dist);
    return 1;
}
int floydWarshell_recurse_i(int k, int i, int j, vector<vector<int> > &dist){
    int a = (i==V)?1:floydWarshell_recurse_j(k,i,j,dist);
    a = (i==V)?1:floydWarshell_recurse_i(k,i+1,j,dist);
    return 1;
}
int floydWarshell_recurse_k(int k, int i, int j, vector<vector<int> > &dist){
    int a = (k==V)?1:floydWarshell_recurse_i(k,i,j,dist);
    a = (k==V)?1:floydWarshell_recurse_k(k+1,i,j,dist);
    return 1;
}
void floydWarshell (vector<vector<int> > graph)
{
    vector<vector<int> > dist;
    int i, j, k;
    dist = graph;
    int a = floydWarshell_recurse_k(0,0,0,dist);
    printSolution(dist);
}
int input_recurse(int i,int j, vector<vector<int> > &graph){
    cin>>graph[i][j];
    return 1;
}
int input_recurse_j(int i,int j, vector<vector<int> > &graph){
    int a = (j==V)?1:input_recurse(i,j,graph);
    a = (j==V)?1:input_recurse_j(i,j+1,graph);
    return 1;
}
int input_recurse_i(int i, int j, vector<vector<int> > &graph){
    int a = (i==V)?1:input_recurse_j(i,j,graph);
    a = (i==V)?1:input_recurse_i(i+1,j,graph);
    return 1;
}
int main()
{
    cin>>V;
    vector<int> temp(V,0);
    vector<vector<int> > graph(V,temp);
    int a = input_recurse_i(0,0,graph);
    floydWarshell(graph);
    return 0;
}
