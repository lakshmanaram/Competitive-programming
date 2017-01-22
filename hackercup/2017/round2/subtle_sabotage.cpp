#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long t;
    infile.open("subtle_sabotage.txt");
    outfile.open("output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        ll n,m,k;
        infile>>n>>m>>k;
        ll ans = -1;
        if( k < n && k < m) {
            ll temp = n;
            n = max(temp,m);
            m = min(temp,m);
            // cout<<"n = "<<n<<" m = "<<m<<" k = "<<k<<endl;
            if(2*k + 3 <= m) {
                if(ans == -1)
                    ans = ceil((double)n/(double)k);
                else
                    ans = min(ans,(ll)ceil((double)n/(double)k));
                if (2*k + 1 <= n) {
                    if( k == 1){
                        if (ans == -1)
                            ans = 5;
                        else
                            ans = min(ans,(ll)5);
                    } else {
                        if (ans == -1)
                            ans = 4;
                        else
                            ans = min(ans,(ll)4);
                    }
                }
            }
            if(2*k + 3 <= n) {
                if(ans == -1)
                    ans = ceil((double)m/(double)k);
                else
                    ans = min(ans,(ll)ceil((double)m/(double)k));
                if (2*k + 1 <= m) {
                    if( k == 1){
                        if (ans == -1)
                            ans = 5;
                        else
                            ans = min(ans,(ll)5);
                    } else {
                        if (ans == -1)
                            ans = 4;
                        else
                            ans = min(ans,(ll)4);
                    }
                }
            }
        }
        // cout<<ans<<endl;
        outfile<<"Case #"<<tk<<": "<<ans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
