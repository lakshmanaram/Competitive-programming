#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll a){
	return a*(a+1)/2;
}
class construct{
public:
	int v;
	ll a, b, c;
	construct(){
		v = 0;
	}
	int size(){
		return v;
	}
	void push_back(ll x){
		switch(v){
			case 0: a = x;
			break;
			case 1: b = x;
			break;
			default: c = x;
		}
		v++;
	}
	ll get(int i){
		switch(i){
			case 0: return a;
			case 1: return b;
			default: return c;
		}
	}
	void clear(){
		v = 0;
	}
	ll get_ans(){
		if(v == 0) return 0;
		else if(v == 1) return f(a);
		else return f(a)+b+f(c);
	}
};
class node{
public:
	ll val;
	construct child;
};
construct func(construct &a, construct &b) {
	construct ans;
	if(b.size() == 0) return a;
	if(a.size() == 0) return b;
	if(b.size() == 1 && a.size() == 1){
		if(a.get(0) == -1 && b.get(0) == -1) return a;
		else if(a.get(0) == -1) {
			ans.push_back(0);
			ans.push_back(0);
			ans.push_back(b.get(0));
		} else if(b.get(0) == -1) {
			ans.push_back(a.get(0));
			ans.push_back(0);
			ans.push_back(0);
		} else 
			ans.push_back(a.get(0)+b.get(0));
		return ans;
	} else if (a.size() == 1){
		if(a.get(0) == -1){
			ans.push_back(0);
			ans.push_back(f(b.get(0))+b.get(1));
		} else {
			ans.push_back(a.get(0) + b.get(0));
			ans.push_back(b.get(1));
		}
		ans.push_back(b.get(2));
		return ans;
	} else if (b.size() == 1) {
		ans.push_back(a.get(0));
		if(b.get(0) == -1){
			ans.push_back(f(a.get(2))+a.get(1));
			ans.push_back(0);
		} else {
			ans.push_back(a.get(1));
			ans.push_back(a.get(2) + b.get(0));
		}
		return ans;
	}
	ans.push_back(a.get(0));
	ans.push_back(a.get(1) + f(a.get(2)+b.get(0)) + b.get(1));
	ans.push_back(b.get(2));
	return ans;
}
class segment_tree{
public:
	vector<node> tnodes;
	vector<node> arr;
	ll big_val;
	segment_tree(ll n, ll v){
		node temp;
		temp.val = 0;
		arr.resize(n,temp);
		big_val = v;
	}
	void build_segment_tree(ll index, ll start, ll end) {
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index].val = arr[start].val;
			tnodes[index].child.push_back((arr[start].val <= big_val)?1:-1);
		} else {
			ll mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index].child = func(tnodes[2*index+1].child, tnodes[2*index+2].child);
		}
	}
	construct query_range(ll index, ll start, ll end, ll l, ll r) {
		construct emptyc;
		if(start > r || end < l)
			return emptyc;
		if(start >= l && end <= r)
			return tnodes[index].child;
		ll mid = (start+end)/2;
		construct a1 = query_range(2*index+1,start,mid,l,r);
		construct a2 = query_range(2*index+2,mid+1,end,l,r);
		return func(a1,a2);
	}
	void update(ll index, ll start, ll end, ll updatepos, ll val) {
		// add val to updatepos indexed element
		if(start == end){
			arr[updatepos].val = val;
			tnodes[index].val = val;
			tnodes[index].child.clear();
			tnodes[index].child.push_back((arr[start].val <= big_val)?1:-1);
		} else {
			ll mid = (start+end)/2;
			if(start <= updatepos && mid >= updatepos)
				update(2*index+1,start,mid,updatepos,val);
			else
				update(2*index+2,mid+1,end,updatepos,val);
			tnodes[index].child = func(tnodes[2*index+1].child, tnodes[2*index+2].child);
		}
	}
};
int main(){
	ll n, q, L, R;
	cin >> n >> q >> L >> R;
	segment_tree stl(n, L-1), str(n, R);	
	stl.build_segment_tree(0,0,stl.arr.size()-1);
	str.build_segment_tree(0,0,str.arr.size()-1);
	while(q--){
		int type;
		ll arg1, arg2;
		scanf("%d %lld %lld", &type, &arg1, &arg2);
		arg1--;
		if(type == 1) {
			str.update(0,0,str.arr.size()-1,arg1,arg2);
			stl.update(0,0,stl.arr.size()-1,arg1,arg2);
		} else {
			arg2--;
			construct ans1 = str.query_range(0,0,str.arr.size()-1,arg1,arg2), ans2 = stl.query_range(0,0,stl.arr.size()-1,arg1,arg2);
			printf("%lld\n",ans1.get_ans() - ans2.get_ans());
		}
	}

	return 0;
}