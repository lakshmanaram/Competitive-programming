// make a unrooted tree rooted and assigning rank
#include <bits/stdc++.h>
using namespace std;
struct node {
    vector<long> children;
    vector<pair<long,long long> > tickets;
    long parent;
    long rank;
    long long tval;
};
class tree{
public:
    vector<node> nodes;
    tree(long n){
        nodes.resize(n);
        for(long i=1;i<n;i++){
            long x,y;
            cin>>x>>y;
            x--,y--;
            nodes[x].children.push_back(y);
            nodes[y].children.push_back(x);
        }
    }
    void root_the_tree_util(long x, long parent, long rank){
        nodes[x].parent = parent;
        nodes[x].rank = rank;
        for(long i=0;i<nodes[x].children.size();i++){
            if(nodes[x].children[i] == parent){
                nodes[x].children.erase(nodes[x].children.begin()+i);
                i--;
            } else {
                root_the_tree_util(nodes[x].children[i],x,rank+1);
            }
        }
    }
    void root_the_tree(long x){
        // x becomes the new root
        root_the_tree_util(x,-1,0);
    }
    void fill_tickets(long m){
        while(m--){
            long v,k;
            long long w;
            cin>>v>>k>>w;
            v--;
            nodes[v].tickets.push_back(make_pair(k,w));
            // cout<<"ticket on node "<<v<<" -> "<<k<<" "<<w<<endl;
        }
    }
    void fill_min_ticket_values_util(long x, set<pair<long,long long> > ticketstack){
        if(ticketstack.empty()){
            nodes[0].tval = 0;
            ticketstack.insert(make_pair(0,0));
        }
        else {
            vector<pair<long, long long> > ticks = nodes[x].tickets;
            long cur_rank = nodes[x].rank;
            long long mintval = 0;
            for(long i=0;i<ticks.size();i++){
                long hops = ticks[i].first;
                long cur_rank = nodes[x].rank;
                long reachable_rank = cur_rank - hops;
                // if(x==6){
                //     cout<<"Reachable rank is "<<reachable_rank<<endl;
                // }
                set<pair<long,long long> >::iterator setit = ticketstack.upper_bound(make_pair(reachable_rank-1,1000000000000000000));
                long long newminval = (*setit).second + ticks[i].second;
                // if(x==6)
                //     cout<<newminval<<" "<<(*setit).first<<" "<<(*setit).second<<endl;
                if(i==0)
                    mintval = newminval;
                else if(mintval > newminval)
                    mintval = newminval;
                // if((*setit).first == 0)
                //     break;
            }
            nodes[x].tval = mintval;
            pair<long, long long> curticket = make_pair(cur_rank,mintval);
            set<pair<long,long long> >::iterator setit = ticketstack.end();
            setit--;
            while(setit!=ticketstack.begin()){
                set<pair<long,long long> >::iterator tempsetit = setit;
                if((*setit).second >= curticket.second)
                    ticketstack.erase(tempsetit);
                else
                    break;
                setit--;
            }
            ticketstack.insert(curticket);
        }
        for(long i=0;i<nodes[x].children.size();i++){
            fill_min_ticket_values_util(nodes[x].children[i],ticketstack);
        }
    }
    void fill_min_ticket_values(){
        set<pair<long,long long> > ticketstack;
        fill_min_ticket_values_util(0,ticketstack);
    }
};
int main(){
    long n,m;
    cin>>n>>m;
    tree t(n);
    t.root_the_tree(0);
    t.fill_tickets(m);
    t.fill_min_ticket_values();
    long q;
    cin>>q;
    while(q--){
        long x;
        cin>>x;
        x--;
        cout<<t.nodes[x].tval<<endl;
    }
    return 0;
}
