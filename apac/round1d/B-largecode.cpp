#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long powd(long long i, long long a, long long kmod){
    if(a == 0)
        return 1;
    if(a==1)
        return i;
    long long val;
    if(a%2 == 0){
        val = powd(i,a/2,kmod);
        val %= kmod;
        return (val*val)%kmod;
    } else {
        val = powd(i,a/2,kmod);
        val %= kmod;
        val *= val;
        val %= kmod;
        val *= i;
        val %= kmod;
        return val;
    }
}
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("B-small-attempt0.in");
    outfile.open("B-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long long a,b,n,k;
        infile>>a>>b>>n>>k;
        long long ans = 0;
        long long actualk = k;
        if(n<k)
            k=n+1;
        vector<long long> valk(k,n/k);
        for(long long i=1;i<valk.size();i++){
            if(i <= (n%k))
                valk[i]++;
            else
                break;
        }
        map<long long,long long> mapa, mapb;
        vector<long long> vala(k);
        for(long long i=0;i<k;i++){
            vala[i] = powd(i,a,actualk);
            if(mapa.find(vala[i])!=mapa.end())
                mapa[vala[i]] += valk[i];
            else
                mapa[vala[i]] = valk[i];
        }
        vector<long long> valb(k);
        for(long long i=0;i<k;i++){
            valb[i] = powd(i,b,actualk);
            if(mapb.find(valb[i])!=mapb.end())
                mapb[valb[i]] += valk[i];
            else
                mapb[valb[i]] = valk[i];
        }
        map<long long,long long>::iterator mit;
        for(mit = mapa.begin() ;mit != mapa.end();mit++){
            map<long long,long long>::iterator mitb = mapb.find((actualk-(mit->first))%actualk);
            if(mitb != mapb.end()){
                ans += (mit->second) * (mitb->second);
                ans %= mod;
            }
        }
        cout<<tk<<" "<<ans<<endl;
        for(long long i=0;i<k;i++){
            if((vala[i]+valb[i])%actualk == 0){
                ans -= valk[i];
                if(ans < 0)
                    ans+=mod;
                ans %= mod;
            }
        }
        outfile<<"Case #"<<tk<<": "<<ans;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
