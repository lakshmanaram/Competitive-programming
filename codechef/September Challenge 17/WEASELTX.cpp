// Assigning rank to a rooted tree
#include <bits/stdc++.h>
using namespace std;
struct node {
    vector<long> children;
    long parent;
    long rank;
    long long val;
};
class tree{
public:
    vector<node> nodes;
    vector<bool> vis;
    vector<long long> arr;
    vector<long long> ans;
    long long period;
    long long a;
    map<long long, long long> m;
    tree(long n){
    // n -> number of nodes
        nodes.resize(n);
        vis.resize(n);
        for(long i=1;i<n;i++){
            long x, y;
            scanf("%ld %ld",&x,&y);
            nodes[x].children.push_back(y);
            nodes[y].children.push_back(x);
        }
        for(long i=0;i<n;i++){
            long long val;
            scanf("%lld",&val);
            nodes[i].val = val;
        }
        period = pow(2,ceil(log2(n)));
        ans.resize(period+1,0);
    }
    void rank_the_tree_util(long x, long rank){
        vis[x] = true;
        nodes[x].rank = rank;
        if(rank < arr.size())
            arr[rank] = arr[rank] ^ nodes[x].val;
        else arr.push_back(nodes[x].val);
        for(long i=0;i<nodes[x].children.size();i++){
            if(!vis[nodes[x].children[i]])
                rank_the_tree_util(nodes[x].children[i], rank+1);
        }
    }
    void rank_the_tree(){
        fill(vis.begin(),vis.end(),false);
        rank_the_tree_util(0, 0);
    }
    // void find_all_ans(){
    //     ans[0] = nodes[0].val;

    // }
    long long find_ans(long long del) {
        if(m.find((del-1) % period) != m.end()) 
            return m[(del-1) % period];
        a = 0;
        ans_util(0, (del-1) % period, period);
        m[(del-1) % period] = a;
        return a;
    }
    void ans_util(long prefix, long i, long per){
        if(per == 1) {
            if(prefix < arr.size())
                a ^= arr[prefix];
            return;
        } 
        long long new_per = per/2;
        ans_util(prefix, i%new_per, new_per);
        if(i < new_per){
            ans_util(prefix+new_per, i, new_per);
        }
    }
    void show_arr(){
        for(long i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    long n, q;
    cin>>n>>q;
    tree t(n);
    t.rank_the_tree();
    // t.find_all_ans();
    // t.show_arr();
    while(q--){
        long long del;
        scanf("%lld",&del);
        printf("%lld\n",t.find_ans(del));
    }
    return 0;
}
