#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<long long> comp;
vector<int> p;
vector<set<int> > coprimes(101);
bool checkPrime(int x){
    for(int i=0;i<p.size();i++){
        if(p[i] == x)
            return true;
    }
    return false;
}
int gcdEuclid(int a, int b){
    if (b==0)
        return a;
    return gcdEuclid(b,a%b);
}
void precompute(){
    for(int i=2;i<101;i++){
        for(int j=i+1;j<101;j++){
            if(checkPrime(j) || gcdEuclid(i,j)==1){
                coprimes[j].insert(i);
            }
        }
    }
}
void compute_util(set<int> x,int k,int pf){
    if(x.empty())
        return;
        // return 1;
    set<int>::iterator it;
    // long long ans = 0;
    while(!x.empty()){
        set<int> temp;
        it = x.end();
        --it;
        set_intersection(x.begin(),x.end(),coprimes[*it].begin(),coprimes[*it].end(),inserter(temp,temp.begin()));
        int elements_lost = x.size()-temp.size();
        while(comp.size()<=k+1)
            comp.push_back(0);
        comp[k+1] += pf*elements_lost;
        comp[k+1] %= mod;
        compute_util(temp,k+1,pf*elements_lost);
        // ans += elements_lost*compute_util(temp,k+1);
        // ans %= mod;
        // cout<<x.size()<<" "<<temp.size()<<" "<<*it<<" "<<k<<endl;
        x = temp;
    }
    // comp[k+1] += ans;
    // comp[k+1] %= mod;
    // return ans;
}
/*
void compute(int val){
    if(checkPrime(val)){
        comp.push_back(comp[comp.size()-1]);
        comp[comp.size()-1].push_back(comp[comp.size()-1][comp[comp.size()-1].size()-1]);
        for(int i=comp[comp.size()-1].size()-2;i>0;i--){
            comp[comp.size()-1][i] = comp[comp.size()-1][i] + comp[comp.size()-1][i-1];
        }
    } else{
        comp.push_back(comp[comp.size()-1]);
        comp[comp.size()-1][1] = val-1;
        compute_util(coprimes[val],1,1);
    }
}*/
vector<long long> factorial;
vector<long long> modInverseArray;
long long mmi(long long n) {
	if(modInverseArray.size() > n)
        return modInverseArray[n];
    // If Empty
	if(modInverseArray.size() == 0){
        // Value for 0 ignored and 1 is 1
        modInverseArray.push_back(0);
        modInverseArray.push_back(1);
    }
	for(long long i = modInverseArray.size(); i <= n; i++)
		modInverseArray.push_back((-(mod/i) * modInverseArray[mod % i]) % mod + mod);
    return modInverseArray[n];
}
long long findfac(long long a){
    if(factorial.size() > a)
        return factorial[a];
    if(factorial.size() == 0)
        factorial.push_back(1);
    for(long long i = factorial.size(); i <= a;i++)
        factorial.push_back((factorial[i-1]*i)%mod);
    return factorial[a];
}
long long nCk(long long n, long long k){
    return (k>=0 && k<=n && n>=0)?(findfac(n)*mmi(findfac(n-k))%mod):-1;
}
int main(){
    int pr_temp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<int> primes(pr_temp,pr_temp + sizeof(pr_temp) / sizeof (pr_temp[0]));
    p = primes;
    vector<long long> temp;
    temp.push_back(1);
    comp.push_back(temp);
    comp.push_back(temp);
    temp.push_back(1);
    comp.push_back(temp);
    int cur_value = 3;
    precompute();
    int t;
    cin>>t;
    // vector<long long> n(t);
    // vector<int> m(t);
    // int maxm = 0;
    // for(int ti=0;ti<t;ti++){
    //     cin>>n[ti]>>m[ti];
    //     if(m[ti]>maxm)
    //         maxm = m[ti];
    // }
    // while(cur_value<=maxm){
    //     compute(cur_value++);
    // }
    for(int ti=0;ti<t;ti++){
        long long ans = 0;
        // for(int i=0;i<comp[m[ti]].size();i++){
        // ans += ((nCk(n[ti],i)%mod)*(comp[m[ti]][i]%mod))%mod;
        cin>>n>>m;
        set<int> s;
        comp.clear();
        comp.push_back(1);
        comp.push_back(m-1);
        for(int i=2;i<=m;i++){
            s.insert(i);
        }
        compute_util(s,0,1);
        for(int i=0;i<comp.size();i++){
        ans += ((nCk(n,i)%mod)*(comp[i]%mod))%mod;
        ans %= mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
