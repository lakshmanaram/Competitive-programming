#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-large-practice.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        long long n,k;
        infile>>n>>k;
        long long x = 1;
        long long ans, nov, uv;
        if(k == 1) ans = n;
        else {
            while(x*2+1 < k && x*2+1 > x) x = x*2+1;
            k-=x;
            n-=x;
            x++;
            uv = n/x;
            if(n %x != 0) uv++;
            nov = uv*x - n;
            nov = x-nov;
            if(k <= nov) ans = uv;
            else ans = uv-1;
        }
        // ans = uv or uv-1;
        outfile<<"Case #"<<tk<<": "<<ans/2<<" "<<ans - ans/2 - 1<<endl;
        if(tk == 63) cout<<"x = "<<x<<" n = "<<n<<" uv = "<<uv<<" nov = "<<nov<<" k = "<<k<<" ans = "<<ans;
    }
    infile.close();
    outfile.close();
    return 0;
}
