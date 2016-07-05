#include <bits/stdc++.h>
using namespace std;
class gnod{
public:
	vector<int> children;
	int key;
};
long long ans = -1;
long long ansno = -1;
class graph{
public:
	vector<gnod> gnode;
	graph(int n, int e){
		vector<gnod> temp(n);
		for(int i=0;i<n;i++)
			cin>>temp[i].key;
		gnode = temp;
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
			add_edge(a-1,b-1);
		}
		MIS();
	}
	void add_edge(int a, int b){
		gnode[a].children.push_back(b);
		gnode[b].children.push_back(a);
	}
	void MIS(void){
		set<int> in,out;
		int count = 0;
		vector<bool> vis(gnode.size(),false);
		for(int i=0;i<gnode.size();i++){
			if(gnode[i].children.size()==0){
				in.insert(i);
				if(gnode[i].key == 0)
					count++;
				vis[i] = true;
			}
		}
		recurse_util(in,out,vis,count);
		cout<<ans<<" "<<ansno;
	}
	void recurse_util(set<int> in, set<int> out, vector<bool> vis, int count){
		set<int>::iterator init, outit;
		if(in.size()+out.size() == gnode.size()){
			long long temp = 0;
			for(init = in.begin();init!=in.end();init++){
				temp += gnode[*init].key;
			}
			if(ans < temp){
				ans = temp;
				ansno = 1;
			}else if(ans == temp){
				ansno += (1<<count);
			}
			return;
		}
		int node = 0;
		for(node=0;node<gnode.size();node++){
			if(!vis[node])
				break;
		}
		vis[node] = true;
		vector<int>::iterator neigh, nne;
		set<int> tempin = in, tempout = out;
		vector<bool> temp = vis;
		int tempcount = count;
		if(gnode[node].key == 0)
			tempcount++;
		tempin.insert(node);
		for(neigh = gnode[node].children.begin();neigh != gnode[node].children.end();neigh++){
			if(!temp[*neigh]){
				temp[*neigh] = true;
				tempout.insert(*neigh);
			}
		}
		recurse_util(tempin,tempout,temp,tempcount);
		for(neigh = gnode[node].children.begin();neigh != gnode[node].children.end();neigh++){
			if(!vis[*neigh]){
				tempin = in; 
				tempout = out;
				tempcount = count;
				temp = vis;
				tempout.insert(node);
				tempin.insert(*neigh);
				if(gnode[*neigh].key==0)
					tempcount++;
				temp[*neigh] = true;
				for(nne = gnode[*neigh].children.begin();nne != gnode[*neigh].children.end(); nne++){
					if(!temp[*nne]){
						temp[*nne] = true;
						tempout.insert(*nne);
					}
				}
				recurse_util(tempin,tempout,temp,tempcount);
			}
		}
	}
};
int main(){
	int n,e;
	cin>>n>>e;
	graph g(n,e);
	return 0;
}