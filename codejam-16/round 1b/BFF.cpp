// dfs template - everything is 0 indexed
#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{
    vector<int> children;
};
class graph{
    public:
    int nodes;
    vector<gnode> gnodes;
    int source;
    vector<int> ways2,ways1,ways0;
    graph(int k){
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        ways2.resize(k,0);
        ways1.resize(k,0);
        ways0.resize(k,0);
    }
    int dfs_recurse(int n, int a, int no_neighbour_flag){
        vector<int>::iterator it;
        a++;
        int x;
        int temp;
        vector<int> ans;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++){
            if(n == source)
                no_neighbour_flag = 0;
            else
                temp = no_neighbour_flag;
            if(*it == source){
                if(a == 1)
                    no_neighbour_flag = 1;
                else if(no_neighbour_flag == 0)
                    no_neighbour_flag = 2;
            }
            if(vis[*it]==false){
                vis[*it] = true;
                x = dfs_recurse(*it,a,no_neighbour_flag);
                ans.push_back(x);
                if(no_neighbour_flag == 2){
                    if(n == source){
                        ways2[n] = max(ways2[n],1+x);
                    }
                }
                else if(no_neighbour_flag == 1){
                    if(n == source){
                        ways1[n] = max(ways1[n],x);
                    }
                }
                else{
                    if(n == source){
                        ways0[n] = max(ways0[n],x);
                    }
                }
            }
            if(n!=source && temp == 0)
                no_neighbour_flag = temp;
            cout<<"neighbour_flag "<<no_neighbour_flag<<endl;
        }
        if(ans.size()==0)
            return a;
        else{
            sort(ans.begin(),ans.end());
            return ans[ans.size()-1];
        }
    }
    void dfs(int n){
        fill(vis.begin(),vis.end(),false);
        vis[n] = true;
        source = n;
        int a = -1;
        int no = 0;
        dfs_recurse(n,a,no);
    }
    void add_node(int c, int k){                                                //initializes graph nodes 0-indexed
        gnodes[c].children.push_back(k);
    }
};
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-small-attempt0.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int j=1;j<=t; j++){
        int ans = 0;
        int n;
        infile>>n;
        graph g(n);
        vector<int> bff(n);
        for(int i=0;i<n;i++){
            infile>>bff[i];
            bff[i]--;
            g.add_node(bff[i],i);
        }
        for(int i=0;i<n;i++){
        g.dfs(i);
        }
        for(int i=0;i<n;i++){
            cout<<g.ways0[i]<<" "<<g.ways1[i]<<" "<<g.ways2[i]<<endl;
        }
        outfile<<"Case #"<<j<<": "<<ans<<endl;
        cout<<endl<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
