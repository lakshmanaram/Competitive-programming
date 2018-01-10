#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(),S.end()
#define S(a) scanf("%lld", &n)
using namespace std;
class obj{
public:
	ll t;
	bool option;
	long enemy;
	ll health;
	ll max_h;
	ll start_h;
	ll regen;
	long seek;
};
struct comp {
	bool operator()(const obj &a, const obj &b) const {
		if (a.t > b.t)
			return true;
		else if (a.t < b.t)
			return false;
		return a.option;
	}
};
int main(){
	long n;
	cin>>n;
	long m;
	cin>>m;
	bool ans_there = true;
	ll bounty, increase, damage;
	scanf("%lld %lld %lld", &bounty, &increase, &damage);
	if(increase != 0) {
		vector<obj> arr(n);
		vector<long> no_t(n, 0);
		vector<bool> vis(n, false);
		ll remaining  = 0;
		priority_queue<obj, vector<obj>, comp> pq;
		for(long i=0;i<n;i++){
			scanf("%lld %lld %lld", &arr[i].max_h, &arr[i].start_h, &arr[i].regen);
			arr[i].option = false;
			if(arr[i].start_h > damage)
				continue;
			if(arr[i].max_h <= damage){
				ans_there = false;
				break;
			}
			remaining ++;
			no_t[i] = 1;
			arr[i].enemy = i;
			arr[i].seek = 1;
			vis[i] = true;
			if(arr[i].regen != 0)
				arr[i].t = (damage - arr[i].start_h)/arr[i].regen;
			else 
				continue;
			pq.push(arr[i]);
		}
		if(!ans_there){
			printf("-1\n");
			return 0;
		}
		while(m--){
			obj x;
			scanf("%lld %ld %lld", &x.t, &x.enemy, &x.health);
			x.enemy--;
			x.option = true;
			pq.push(x);
		}
		ll ans = 0;
		while(!pq.empty()){
			obj x = pq.top();
			pq.pop();
			if(x.option){
				x.option = false;
				x.start_h = x.health;
				if(vis[x.enemy]){
					no_t[x.enemy]++;
					x.seek = no_t[x.enemy];
					if(x.start_h > damage) {
						ans = max(ans, remaining*(bounty + (x.t-1)*increase));
						remaining--;
						vis[x.enemy] = false;
						continue;
					}
					if(arr[x.enemy].regen != 0)
						x.t += (damage - x.start_h)/arr[x.enemy].regen;
					else
						continue;
				} else {
					if(x.start_h > damage) continue;
					no_t[x.enemy]++;
					x.seek = no_t[x.enemy];
					vis[x.enemy] = true;
					remaining++;
					if(arr[x.enemy].regen != 0)
						x.t += (damage - x.start_h)/arr[x.enemy].regen;
					else
						continue;
				}
				pq.push(x);
				// printf("%lld %ld %lld\n", x.t, x.enemy, x.health);
			} else {
				ll tempans = 0;
				if(no_t[x.enemy] == x.seek){
					tempans = remaining*(bounty + x.t*increase);
					remaining--;
					vis[x.enemy] = false;
				}
				ans = max(ans, tempans);
			}
		}
		if(remaining > 0) printf("-1\n");
		else printf("%lld\n", ans);
	} else {
		vector<obj> arr(n);
		vector<long> no_t(n, 0);
		vector<bool> vis(n, false);
		ll remaining  = 0;
		priority_queue<obj, vector<obj>, comp> pq;
		for(long i=0;i<n;i++){
			scanf("%lld %lld %lld", &arr[i].max_h, &arr[i].start_h, &arr[i].regen);
			arr[i].option = false;
			if(arr[i].start_h > damage)
				continue;
			if(arr[i].max_h <= damage){
				remaining++;
				vis[i] = true;
				continue;
			}
			remaining ++;
			no_t[i] = 1;
			arr[i].enemy = i;
			arr[i].seek = 1;
			vis[i] = true;
			if(arr[i].regen != 0)
				arr[i].t = (damage - arr[i].start_h)/arr[i].regen;
			else 
				continue;
			pq.push(arr[i]);
		}
		while(m--){
			obj x;
			scanf("%lld %ld %lld", &x.t, &x.enemy, &x.health);
			x.enemy--;
			x.option = true;
			pq.push(x);
		}
		ll ans = 0;
		while(!pq.empty()){
			obj x = pq.top();
			pq.pop();
			if(arr[x.enemy].max_h <= damage) continue;
			if(x.option){
				x.option = false;
				x.start_h = x.health;
				if(vis[x.enemy]){
					no_t[x.enemy]++;
					x.seek = no_t[x.enemy];
					if(x.start_h > damage) {
						ans = max(ans, remaining*(bounty + (x.t-1)*increase));
						remaining--;
						vis[x.enemy] = false;
						continue;
					}
					if(arr[x.enemy].regen != 0)
						x.t += (damage - x.start_h)/arr[x.enemy].regen;
					else
						continue;
				} else {
					if(x.start_h > damage) continue;
					no_t[x.enemy]++;
					x.seek = no_t[x.enemy];
					vis[x.enemy] = true;
					remaining++;
					if(arr[x.enemy].regen != 0)
						x.t += (damage - x.start_h)/arr[x.enemy].regen;
					else
						continue;
				}
				pq.push(x);
			} else {
				ll tempans = 0;
				if(no_t[x.enemy] == x.seek){
					tempans = remaining*(bounty + x.t*increase);
					remaining--;
					vis[x.enemy] = false;
				}
				ans = max(ans, tempans);
			}
		}
		if(ans == 0) ans = remaining*bounty;
		printf("%lld\n", ans);
	}
	return 0;
}