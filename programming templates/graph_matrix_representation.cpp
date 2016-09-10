#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > getMatrixRepresentation(long n, long m){
	//n - no of nodes, m - no of edges
	vector<bool> temp(n,false);
	vector<vector<bool> > mat(n,temp);
	while(m--){
		long a,b;
		cin>>a>>b;
		mat[a][b] = true;
		mat[b][a] = true;
	}
	return mat;
}
void showMatrixRepresentation(vector<vector<bool> > graph){
	for(long i=0;i<graph.size();i++) {
		for(long j=0;j<graph[i].size();j++){
			if(graph[i][j])
				cout<<"1";
			else cout<<"0";
			cout<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<bool> > graph = getMatrixRepresentation(n,m);
	showMatrixRepresentation(graph);
	return 0;
}