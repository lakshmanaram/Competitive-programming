#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<vector<long long> > comp;
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
void compute_util(set<int> x,int k,long long pf){
    if(x.empty())
        return;
    set<int>::iterator it;
    while(!x.empty()){
        set<int> temp;
        it = x.end();
        --it;
        set_intersection(x.begin(),x.end(),coprimes[*it].begin(),coprimes[*it].end(),inserter(temp,temp.begin()));
        int elements_lost = x.size()-temp.size();
        comp[comp.size()-1][k+1] += (pf*elements_lost)%mod;
        comp[comp.size()-1][k+1] %= mod;
        compute_util(temp,k+1,(pf*elements_lost)%mod);
        x = temp;
    }
}
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
}
vector<long long> factorial;
long long pow(long long a, long long b, long long MOD) {
    long long x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
long long mmi(long long a) {
    return pow(a,mod-2,mod);
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
    return (k>=0 && k<=n && n>=0)?(findfac(n)*mmi(findfac(n-k))%mod):0;
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
    while(cur_value<101){
        compute(cur_value++);
    }
    for(int ti=0;ti<t;ti++){
        long long ans = 0,n;
        int m;
        cin>>n>>m;
        for(int i=0;i<comp[m].size();i++){
            ans += ((nCk(n,i)%mod)*(comp[m][i]%mod))%mod;
            ans %= mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
