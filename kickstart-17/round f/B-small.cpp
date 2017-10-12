#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    vector<int> memo(1,0);
    for(long i=1;i<100010;i++){
        int ans = 1+memo[i-1];
        for(long j=1;j*j <= i; j++){
            ans = min(ans, 1 + memo[i-j*j]);
        }
        memo.push_back(ans);
    }
    long long t;
    infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long long ans = 0;
        long n;
        infile>>n;
        // cout<<n<<endl;
        // while(n){
        //     // cout<<n<<endl;
        //     n -= (long) sqrt(n) * ((long) sqrt(n));
        //     ans++;
        // }
        outfile<<"Case #"<<tk<<": "<<memo[n];
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}