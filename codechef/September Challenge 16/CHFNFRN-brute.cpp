#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > graph;
vector<pair<long,long> > degree;
void getMatrixRepresentation(long n, long m){
	//n - no of nodes, m - no of edges
	vector<bool> temp(n,false);
	vector<long> deg(n,0);
	vector<vector<bool> > mat(n,temp);
	while(m--){
		long a,b;
		cin>>a>>b;
		mat[a-1][b-1] = true;
		mat[b-1][a-1] = true;
		deg[a-1]++;
		deg[b-1]++;
	}
	graph = mat;
	degree.clear();
	for(long i=0;i<n;i++){
		degree.push_back(make_pair(deg[i],i));
	}
	sort(degree.begin(),degree.end());
}
bool addToSet(set<long> table, long g) {
	if(table.size() == 0)
		return true;
	set<long>::iterator it = table.begin();
	bool insflag = true;
	for(;it!=table.end();it++){
		if(!graph[g][*it]){
			return false;
		}
	}
	return true;
}
bool brute(vector<pair<long, long> > excess, set<long> t1, set<long> t2){
	if(excess.size() == 0)
		return true;
	long curDegree = excess[0].first;
	long curNode = excess[0].second;
	excess.erase(excess.begin());
	if(curDegree >= t1.size()){
		bool table1 = addToSet(t1,curNode);
		if(table1){
			set<long> tempt = t1;
			tempt.insert(curNode);
			bool tempretval = brute(excess,tempt,t2);
			if(tempretval)
				return true;
		}
	}
	if(curDegree >= t2.size()){
		bool table2 = addToSet(t2,curNode);
		if(table2){
			set<long> tempt = t2;
			tempt.insert(curNode);
			bool tempretval = brute(excess,t1,tempt);
			if(tempretval)
				return true;
		}
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		getMatrixRepresentation(n,m);
		set<long> t1,t2;
		if(n <= 200){
			if(brute(degree,t1,t2))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		} else {
			bool YES = true;
			vector<pair<long, long> > excess;
			for(long i=0;i<degree.size();i++){
				bool table1 = addToSet(t1,degree[i].second), table2 = addToSet(t2,degree[i].second);
				if(table1 && t2.size() == 0)
					table2 = false;
				if(table1 && table2){
					if(i >= n)
						excess.push_back(degree[i]);
					else 
						degree.push_back(degree[i]);
				} else if(table1)
					t1.insert(degree[i].second);
				else if(table2)
					t2.insert(degree[i].second);
				else{
					YES = false;
					break;
				}
			}
			if(YES){
				long presentSize;
				do{
					presentSize = excess.size();
					for(long i=0;i<excess.size();i++){
						bool table1 = addToSet(t1,excess[i].second), table2 = addToSet(t2,excess[i].second);
						if(table1 && table2){
							continue;
						} else if(table1){
							t1.insert(excess[i].second);
							excess.erase(excess.begin()+i);
							i--;
						}
						else if(table2){
							t2.insert(excess[i].second);
							excess.erase(excess.begin()+i);
							i--;	
						}
						else{
							YES = false;
							break;
						}
					}
				}while(excess.size() != presentSize);
				if(excess.size()!=0){
					YES = brute(excess,t1,t2);
				}
				if(YES)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}