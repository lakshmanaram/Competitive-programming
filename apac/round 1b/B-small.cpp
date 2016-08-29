#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long powd(long long i, long long a, long long kmod){
    if(i==0)
        return 0;
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
        for(int i =1; i<=n; i++){
            long long val = powd(i,a,k);
            for(int j=1;j<=n;j++) {
                if(i!=j){
                    long long val2 = powd(j,b,k);
                    if((val+val2) % k == 0){
                        ans++;
                        ans %= mod;
                    }
                }
            }
        }
        outfile<<"Case #"<<tk<<": "<<ans;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
