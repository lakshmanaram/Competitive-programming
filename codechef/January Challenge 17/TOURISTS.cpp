// dfs template - everything is 0 indexed
#include <bits/stdc++.h>
#define mp make_pair 
#define pb push_back
using namespace std;
vector<bool> vis;
struct gnode{
    vector<pair<long,long> > from,to;
    long f_start, t_start;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    vector<pair<long,long> > edges;
    vector<bool> bedges;
    vector<long> vno;
    long start_city;
    bool vis_city;
    long vk;
    vector<pair<long long, long> > keys;
    graph(long k, long e){
    	nodes = k;
        gnode temp;
        temp.f_start = temp.t_start = 0;
        gnodes.resize(k,temp);
        bedges.resize(e,false);
        vno.resize(nodes,0);
    }
    void add_node(long c, long k, long i){
        gnodes[c].from.pb(mp(k,i));
        gnodes[k].to.pb(mp(c,i));
        edges.pb(mp(c,k));
    }
    bool traverse(long current){
        // cout<<current<<endl;
        if(vno[current]!=vk && vno[current]!=0)
            vis_city = true;
        vno[current] = vk;
        if(current == start_city)
            return true;
        long i;
        for(i=gnodes[current].f_start;i<gnodes[current].from.size();i++){
            long j = gnodes[current].from[i].second;
            if(!bedges[j]){
                bedges[j] = true;
                gnodes[current].f_start = i+1;
                return traverse(gnodes[current].from[i].first);
            }
        }
        for(i=gnodes[current].t_start;i<gnodes[current].to.size();i++){
            long j = gnodes[current].to[i].second;
            if(!bedges[j]){
                bedges[j] = true;
                long temp = edges[j].first;
                edges[j].first = edges[j].second;
                edges[j].second = temp;
                gnodes[current].t_start = i+1;
                return traverse(gnodes[current].to[i].first);
            }
        }
        return false;
    }
    bool get_ans() {
        vk = 1;
        for(long i=0;i<bedges.size();i++) {
            if(!bedges[i]) {
                start_city = edges[i].first;
                bedges[i] = true;
                vis_city = true;
                if(i!=0)
                    vis_city = false;
                if(!traverse(edges[i].second))
                    return false;
                if(!vis_city)
                    return false;
                vk++;
            }
        }
        return true;
    }
    bool check() {
        for(long i=0;i<gnodes.size();i++){
            long k = gnodes[i].from.size()+gnodes[i].to.size();
            if((k==0) || (k&1))
                return false;
        }
        return true;
    }
    void print_edges() {
        for(long i=0;i<edges.size();i++) {
            cout<<edges[i].first+1<<" "<<edges[i].second+1<<endl;
        }
    }
};
int main(){
    string no = "NO", yes = "YES";
    long n,e;
    cin>>n>>e;
    graph g(n,e);
    for(long i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g.add_node(a-1,b-1,i);
    }
    if(g.check()){
        if(g.get_ans()){
            cout<<yes<<endl;
            g.print_edges();
        } else cout<<no;
    } else cout<<no<<endl;
    return 0;
}

