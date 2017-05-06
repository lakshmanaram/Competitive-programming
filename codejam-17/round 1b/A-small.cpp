#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("A-large.in");
    outfile.open("A-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long long d;
        long n;
        infile>>d>>n;
        vector<long long> k,s;
        long long x,y;
        for(long i=0;i<n;i++) {
            infile>>x>>y;
            k.pb(x);
            s.pb(y);
        }
        long ans = 0;
        for(long i=1;i<k.size();i++) {
            if ( (d - k[i]) * s[ans] >= s[i] * (d - k[ans]) ) {
                ans = i;
            }
        }    
        double as = d;
        as *= s[ans];
        as /= (d-k[ans]); 
    	outfile<<"Case #"<<tk<<": "<<std::fixed<<setprecision(6)<<as;
        if(tk == 86) {
            cout<<d<<" "<<n<<endl;
            for(long i=0;i<k.size();i++) {
                cout<<k[i]<<" "<<s[i]<<endl;
            }
        }
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
