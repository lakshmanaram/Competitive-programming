#include<bits/stdc++.h>
#define maxm 1000000001
#define maxn 100001
using namespace std;
vector<long long> modInverse(maxn+1);
vector<long long> fac;
void initializeArray(void) {
    modInverse[1] = 1;
    modInverse[0] = 1;
    fac.push_back(1);
    fac.push_back(1);
    for(int i = 2; i <= maxn; i++) {
        modInverse[i] = (-(maxm/i) * modInverse[maxm % i]) % maxm + maxm;
    }
    for(int i = 2; i <= maxn; i++) {
        modInverse[i] = (modInverse[i]*modInverse[i-1])%maxm;
        fac.push_back((i*fac[i-1])%maxm);
    }      
    return;
}
long long choose(long n, long r)
{
    long long a=fac[n]*modInverse[r];
    a %= maxm;
    a *= modInverse[n-r];
    a %= maxm;
    if(a<0)
    a+=maxm;
    return a;
}
struct node{
	long left;
	long right;
	long nol;
	long nor;
}ntree[100001];
void init(long a){
	ntree[a].left = 0;
	ntree[a].right = 0;
	ntree[a].nol = 0;
	ntree[a].nor = 0;
}
void insnode(long a,long b){
	init(b);
	if(ntree[a].left==0)
		ntree[a].left = b;
	else
		ntree[a].right = b;
	return;
}
long findno(long a){
	if(ntree[a].left==0&&ntree[a].right==0)
		return 1;
	else if(ntree[a].left==0){
		ntree[a].nor = findno(ntree[a].right);
		return 1+ntree[a].nor;
	}
	else if(ntree[a].right==0){
		ntree[a].nol = findno(ntree[a].left);
		return 1+ntree[a].nol;
	}
	ntree[a].nol = findno(ntree[a].left);
	ntree[a].nor = findno(ntree[a].right);
	return 1+ntree[a].nol+ntree[a].nor;
}
long long func(long a)
{
	if(ntree[a].nol == 0 && ntree[a].nor == 0){
		return 1;
	}
	else if(ntree[a].nol == 0){
		return (2*func(ntree[a].right))%maxm;
	}
	else if(ntree[a].nor == 0){
		return (2*func(ntree[a].left))%maxm;
	}
	long long val1 = func(ntree[a].left);
	long long val2 = func(ntree[a].right);
	return choose(val1+val2,val1);
}
int main()
{
	initializeArray();
	long t;
	cin>>t;
	while(t--){
		init(1);
		long n,i,x,y;
		cin>>n;
		for(i=1;i<n;i++){
			cin>>x>>y;
			insnode(x,y);
		}
		long no = findno(1);
		cout<<func(1);
	}
	return 0;
}

