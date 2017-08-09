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
    vector<bool> vis;
    vector<vector<long> > arr;
    tree(long n){
        nodes.resize(n);
        vector<long> temp(log2(n)+1, -1);
        arr.resize(n,temp);
        vis.resize(n, false);
        for(long i=1;i<n;i++){
            long x;
            scanf("%ld", &x);
            x--;
            nodes[x].children.push_back(i);
            nodes[i].children.push_back(x);
        }
    }
    void process() {
    	long i, j;
		for (i = 0; i < nodes.size(); i++)
			arr[i][0] = nodes[i].parent;
		for (j = 1; 1 << j < nodes.size(); j++)
			for (i = 0; i < nodes.size(); i++)
				if (arr[i][j - 1] != -1)
					arr[i][j] = arr[arr[i][j - 1]][j - 1];
    }
    void rank_the_tree_util(long x, long parent, long rank){
    	vis[x] = true;
        nodes[x].parent = parent;
        nodes[x].rank = rank;
        for(long i=0;i<nodes[x].children.size();i++){
        	if(!vis[nodes[x].children[i]])
            	rank_the_tree_util(nodes[x].children[i],x,rank+1);
        }
    }
    void rank_the_tree(){
        rank_the_tree_util(0,-1,0);
        process();
    }
    long get_lca(long x, long y){
        // while(nodes[x].rank > nodes[y].rank)
        //     x = nodes[x].parent;
        // while(nodes[y].rank > nodes[x].rank)
        //     y = nodes[y].parent;
        // while(x != y) {
        //     x = nodes[x].parent;
        //     y = nodes[y].parent;
        // }
        // return x;
    	long log, i;
    	if (nodes[x].rank < nodes[y].rank)
    		swap(x,y);
    	for (log = 1; 1 << log <= nodes[x].rank; log++);
    		log--;
    	for (i = log; i >= 0; i--)
    		if (nodes[x].rank - (1 << i) >= nodes[y].rank)
    			x = arr[x][i];
		if (x == y)
			return x;
		for (i = log; i >= 0; i--)
			if (arr[x][i] != -1 && arr[x][i] != arr[y][i])
				x = arr[x][i], y = arr[y][i];
		if(nodes[x].parent == -1) return 0;
		return nodes[x].parent;
    }
    long answer(long s, long t, long f){
    	long k = get_lca(s,f);
    	long l = get_lca(t,f);
    	long m = get_lca(s,t);
    	if(k == l){
    		long n = get_lca(m,f);
    		return nodes[m].rank + nodes[f].rank - 2*nodes[n].rank+1;
    	} else {
    		if(nodes[k].rank > nodes[l].rank)
    			swap(k,l);
    		if(get_lca(k,l) != k)
    			cout<<-1;
    		return nodes[f].rank - nodes[l].rank + 1;
    	}
    }
};
int main(){
    long n, q;
    scanf("%ld %ld", &n, &q);
    tree t(n);
    t.rank_the_tree();
    while(q--){
    	long a, b, c;
    	scanf("%ld %ld %ld", &a, &b, &c);
    	a--;
    	b--;
    	c--;
    	printf("%ld\n", max(t.answer(a,b,c),max(t.answer(a,c,b),t.answer(b,c,a))));
    }
    return 0;
}
