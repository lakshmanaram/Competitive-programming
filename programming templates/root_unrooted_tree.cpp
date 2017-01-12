// make a unrooted tree rooted and assigning rank
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
        root_the_tree_util(x,-1,0);
    }
    void print_the_tree(void) {
        for(long i=0;i<nodes.size();i++){
            cout<<i<<" -> ";
            for(long j = 0; j < nodes[i].children.size();j++){
                cout<<nodes[i].children[j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    long n;
    cin>>n;
    tree t(n);
    t.root_the_tree(0);
    t.print_the_tree();
    return 0;
}
