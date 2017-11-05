#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define SULL(n) scanf("%llu", &n)
#define INF 1e18
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

vector<bool> vis;
int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

struct node {
	vi adj;
};

vi start_time(100005), end_time(100005), subtree_sum(100005,0), skills(100005);
vector<node> tree;
ll timer = -1;

void dfs(ll u) {
	vis[u] = true;
	ll i, v, len = tree[u].adj.size();
	start_time[u] = ++timer;
	subtree_sum[u] = skills[u];

	FOR(i,0,len) {
		v = tree[u].adj[i];
		if(!vis[v]){
			dfs(v);
			subtree_sum[u] += subtree_sum[v];
		}
	}

	end_time[u] = timer;
}
void build_rangesum_tree(ll* t, ll n)   {
    ll i;
    for(i=n-1; i>0; i--)    {
        t[i] = t[i<<1] + t[i<<1|1];
    }
    /*for(i=1; i<2*n; i++)
        cout<<t[i]<<" ";
    cout<<endl;*/
}
ll range_query(ll* t, ll n, ll l, ll r)   {
    ll sum=0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)    {
        if(l & 1)
            sum = (sum + t[l++]);
        if(r & 1)
            sum = (sum + t[--r]);
    }
    return sum;
}

void point_update(ll* t, ll n, ll index, ll key) {
	index += n;
	// t[index] = t[index] - oldkey + newkey;
	t[index] = key;
	for(; index>1; index>>=1) {
		t[index>>1] = (t[index] + t[index^1]);
	}
}

int main() {
	ll i,j,t,u,v,x,n,m,s;
	n = read_ll();
	m = read_ll();

	vis.resize(n+1);
	tree.resize(n+1);
	ll seg_tree1[2*n+2];

	FOR(i,0,2*n+2) {
		seg_tree1[i] = 0;
	}
	FOR(i,1,n+1) {
		skills[i] = read_ll();
	}
	FOR(i,0,n-1) {
		u = read_ll();
		v = read_ll();
		tree[u].adj.pb(v);
		tree[v].adj.pb(u);
	}
	dfs(1);
	FOR(i,1,n+1) {
		seg_tree1[n+start_time[i]] = skills[i];
	}
	build_rangesum_tree(seg_tree1,n);
	// FOR(i,1,n+1) {
	// 	printf("i = %lld st = %lld et = %lld ss = %lld \n", i,start_time[i],end_time[i],subtree_sum[i]);
	// }
	// cout<<"==========================================================\n";
	// FOR(j,1,2*n+2) {
	// 	cout<<seg_tree1[j]<<" ";
	// }
	// cout<<"\n==========================================================\n";
	FOR(i,0,m) {
		char ch;
		cin >> ch;

		if (ch == 'U') {
			s = read_ll();
			x = read_ll();

			point_update(seg_tree1, n, start_time[s], x);
			// cout<<"==========================================================\n";
			// FOR(j,1,2*n+2) {
			// 	cout<<seg_tree1[j]<<" ";
			// }
			// cout<<"\n==========================================================\n";
		}
		else {
			s = read_ll();
			ll val = range_query(seg_tree1, n, start_time[s], end_time[s]+1);			

			printf("%lld\n", val);
		}
	}
	return 0;
}