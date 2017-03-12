// Heavy Light Decomposition
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
class segment_tree{
public:
	vector<long> tnodes;
	vector<long> arr;
	void build_segment_tree(long index, long start, long end) {
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index] = arr[start];
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index] = max(tnodes[2*index+1],tnodes[2*index+2]);
		}
	}
	long query_range(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return 0;
		if(start >= l && end <= r)
			return tnodes[index];
		long mid = (start+end)/2;
		long val1 = query_range(2*index+1,start,mid,l,r);
		long val2 = query_range(2*index+2,mid+1,end,l,r);
		return max(val1,val2);
	}
	void update(long index, long start, long end, long updatepos, long val) {
		// add val to updatepos indexed element
		if(start == end){
			arr[updatepos] = val;
			tnodes[index] = val;
		} else {
			long mid = (start+end)/2;
			if(start <= updatepos && mid >= updatepos)
				update(2*index+1,start,mid,updatepos,val);
			else
				update(2*index+2,mid+1,end,updatepos,val);
			tnodes[index] = max(tnodes[2*index+1], tnodes[2*index+2]);
		}
	}
};
struct edge{
    long x, y, val;
    edge (long a, long b, long c) {
        x = a, y = b, val = c;
    }
};
struct gnode{
    vector<pair<long, long> > children;
    long chain_index, pos;
    long sub_size, parent, rank;
    gnode(){
        parent = -1;
        chain_index = -1;
    }
};
class HLD {
public:
    segment_tree st;
    vector<edge> edges;
    vector<gnode> gnodes;
    vector<bool> vis;
    long chain_no, index;
    vector<long> chain_head;
    HLD(long n) {
        gnodes.resize(n);
        for(long i=0;i<n-1;i++){
            long a, b, c;
            scanf("%ld %ld %ld",&a,&b,&c);
            add_edge(a-1,b-1,c);
        }
        dfs(0,-1,0);
        chain_no = index = 0;
        main_hld(0,0);
        st.build_segment_tree(0,0,st.arr.size()-1);
        while(1) {
			char s[100];
			scanf("%s", s);
			if(s[0]=='D')
				break;
			long a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='Q')
                printf("%ld\n",query(a-1,b-1));
            else
                update(a-1,b);
		}
    }
    void add_edge(long a, long b, long c) {
        int pos = edges.size();
        edge x(a,b,c);
        edges.pb(x);
        gnodes[a].children.pb(mp(b,pos));
        gnodes[b].children.pb(mp(a,pos));
    }
    void dfs(long cur_node, long parent, long rank) {
        long sub_sum = 0;
        for(long i=0; i < gnodes[cur_node].children.size(); i++) {
            if(gnodes[cur_node].children[i].first != parent) {
                long x = gnodes[cur_node].children[i].first;
                dfs(x,cur_node,rank+1);
                sub_sum += gnodes[x].sub_size;
            }
        }
        gnodes[cur_node].parent = parent;
        gnodes[cur_node].rank = rank;
        gnodes[cur_node].sub_size = sub_sum+1;
    }
    void main_hld(long n, long cost) {
        if(chain_head.size() == chain_no)
            chain_head.pb(n);
        gnodes[n].chain_index = chain_no;
        gnodes[n].pos = index++;
        st.arr.pb(cost);
        // cout<<n<<" ";
        long new_cost, schild = -1, temp_cost;
        for(long i=0;i<gnodes[n].children.size(); i++) {
            pair<long, long> x = gnodes[n].children[i];
            if(gnodes[n].parent == x.first) continue;
            if(schild == -1 || gnodes[schild].sub_size < gnodes[x.first].sub_size) {
                schild = x.first;
                new_cost = edges[x.second].val;
            }
        }
        if(schild != -1)
            main_hld(schild, new_cost);
        for(long i=0;i<gnodes[n].children.size(); i++) {
            pair<long, long> x = gnodes[n].children[i];
            if(gnodes[n].parent == x.first || schild == x.first ) continue;
            chain_no++;
            temp_cost = edges[x.second].val;
            main_hld (x.first, temp_cost);
        }
    }
    long lca(long a, long b) {
        long heada = chain_head[gnodes[a].chain_index];
        long headb = chain_head[gnodes[b].chain_index];
        while(heada != headb) {
            if(gnodes[heada].rank < gnodes[headb].rank){
                b = gnodes[headb].parent;
                headb = chain_head[gnodes[b].chain_index];
            } else {
                a = gnodes[heada].parent;
                heada = chain_head[gnodes[a].chain_index];
            }
        }
        while (gnodes[a].rank < gnodes[b].rank)
            return a;
        return b;
    }
    long query(long a, long b) {
        long lca_ab = lca(a,b);
        return max(query_util(a,lca_ab),query_util(b,lca_ab));
    }
    long query_util(long a, long b) {
        long ans = 0;
        while(gnodes[a].chain_index != gnodes[b].chain_index) {
            ans = max(ans,st.query_range(0, 0, st.arr.size()-1, gnodes[chain_head[gnodes[a].chain_index]].pos, gnodes[a].pos));
            a = chain_head[gnodes[a].chain_index];
            a = gnodes[a].parent;
        }
        if(a==b)
            return ans;
        else{
            return max(ans,st.query_range(0, 0, st.arr.size()-1, gnodes[b].pos+1, gnodes[a].pos));
        }
    }
    void update(long a, long val) {
        edge x = edges[a];
        if(gnodes[x.y].parent == x.x)
            swap(x.x,x.y);
        x.val = val;
        edges[a] = x;
        st.update(0,0,st.arr.size()-1, gnodes[x.x].pos, val);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--) {
        long n;
	    cin>>n;
        HLD h(n);
    }
	return 0;
}
