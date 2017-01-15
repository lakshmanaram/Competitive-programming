#include <bits/stdc++.h>
#define ll long long 
using namespace std;
class graph{
    public:
    long nodes;
    vector<vector<ll> > edges;
    vector<pair<int,int> > pairs;
    graph(long k){
        nodes = k;
        vector<ll> temp(k,-1);
        edges.resize(k,temp);
        for(int i=0;i<nodes;i++)
            edges[i][i] = 0;
    }
    void add_node(long c, long k, ll val){
        if(edges[c][k] == -1)
            edges[c][k] = val;
        edges[c][k] = min(edges[c][k],val);
        if(edges[k][c] == -1)
            edges[k][c] = val;
        edges[k][c] = min(edges[k][c],val);
    }
    void floyd_warshall() {
        for(long k=0; k<nodes; k++)
            for(long i=0;i<nodes;i++)
                for(long j=0;j<nodes;j++){
                    if(edges[i][k] != -1 && edges[k][j] != -1){
                        if(edges[i][j] == -1)
                            edges[i][j] = edges[i][k]+edges[k][j];
                        edges[i][j] = min(edges[i][j],edges[i][k]+edges[k][j]);
                    }
                }
    }
    ll get_ans_util(int pos, ll dval, ll pval) {
        if ( pos == pairs.size() - 2 ) {
            ll ans = -1;
            if(edges[pairs[pos].second][pairs[pos+1].second]!=-1 && dval!=-1)
                ans = dval+edges[pairs[pos].second][pairs[pos+1].second];

            if(pval!=-1 && edges[pairs[pos+1].first][pairs[pos+1].second]!=-1){
                if(ans == -1)
                    ans = pval+edges[pairs[pos+1].first][pairs[pos+1].second];
                ans = min(ans,pval+edges[pairs[pos+1].first][pairs[pos+1].second]);
            }
            return ans;
        }
        if(pval == -1 && dval == -1)
            return -1;
        ll ansd = -1, ansp = -1;
        if (dval != -1 && edges[pairs[pos].second][pairs[pos+1].second] != -1)
            ansd = dval+edges[pairs[pos].second][pairs[pos+1].second];
        if (pval!=-1 && edges[pairs[pos+1].first][pairs[pos+1].second] != -1) {
            if(ansd == -1)
                ansd = edges[pairs[pos+1].first][pairs[pos+1].second]+pval;
            ansd = min(ansd,edges[pairs[pos+1].first][pairs[pos+1].second]+pval);
        }
        if(edges[pairs[pos+1].second][pairs[pos+2].first] == -1)
            return -1;
        if(ansd != -1)
            ansd += edges[pairs[pos+1].second][pairs[pos+2].first];

        if(dval != -1 && edges[pairs[pos].second][pairs[pos+2].first] != -1)
            ansp = dval+edges[pairs[pos].second][pairs[pos+2].first];
        if(pval != -1 && edges[pairs[pos+1].first][pairs[pos+2].first] != -1) {
            if(ansp == -1)
                ansp = pval+edges[pairs[pos+1].first][pairs[pos+2].first];
            ansp = min(ansp,pval+edges[pairs[pos+1].first][pairs[pos+2].first]);
        }
        if(ansp != -1)
            ansp += edges[pairs[pos+1].second][pairs[pos+2].first];
        return get_ans_util(pos+1,ansp,ansd);
    }
    ll get_ans() {
        ll ansd = -1, ansp = -1;
        ll init = edges[0][pairs[0].first];
        if(init == -1)
            return -1;
        if(pairs.size() == 1) {
            if(edges[pairs[0].first][pairs[0].second] == -1)
                return -1;
            else
                return init + edges[pairs[0].first][pairs[0].second];
        }
        if(edges[pairs[1].first][pairs[0].second] == -1)
            return -1;
        ll te = edges[pairs[1].first][pairs[0].second]+init;
        if(edges[pairs[0].first][pairs[0].second]!=-1)
            ansp = edges[pairs[0].first][pairs[0].second]+te;
        if(edges[pairs[0].first][pairs[1].first] != -1)
            ansd = edges[pairs[0].first][pairs[1].first]+te;
        return get_ans_util(0,ansd,ansp);
    }
};
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("manic_moving.txt");
    outfile.open("output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        int n,m,k;
        infile>>n>>m>>k;
        graph g(n);
        for(int i=0;i<m;i++){
            int a,b,c;
            infile>>a>>b>>c;
            g.add_node(a-1,b-1,c);
        }
        for(int i=0;i<k;i++) {
            int s,t;
            infile>>s>>t;
            g.pairs.push_back(make_pair(s-1,t-1));
        }
        g.floyd_warshall();
        outfile<<"Case #"<<tk<<": "<<g.get_ans()<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
