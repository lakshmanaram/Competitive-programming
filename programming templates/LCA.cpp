// Find LCA
#include <bits/stdc++.h>
using namespace std;
struct node {
    vector<long> children;
    long parent;
    long rank;
};
class tree{
public:
    vector<node> nodes;

    tree(long n){
    // n -> number of nodes
        nodes.resize(n);
        for(long i=1;i<n;i++){
            long x;
            cin>>x;
            x--;            // in case the nodes are 1-indexed
            nodes[x].children.push_back(i);
        }
    }
    void rank_the_tree_util(long x, long parent, long rank){
        nodes[x].parent = parent;
        nodes[x].rank = rank;
        for(long i=0;i<nodes[x].children.size();i++){
            rank_the_tree_util(nodes[x].children[i],x,rank+1);
        }
    }
    void rank_the_tree(){
        rank_the_tree_util(0,-1,0);
    }
    long get_lca(long x, long y){
        while(nodes[x].rank > nodes[y].rank)
            x = nodes[x].parent;
        while(nodes[y].rank > nodes[x].rank)
            y = nodes[y].parent;
        while(x != y) {
            x = nodes[x].parent;
            y = nodes[y].parent;
        }
        return x;
    }
};
int main(){
    long n;
    cin>>n;
    tree t(n);
    t.rank_the_tree();
    return 0;
}
