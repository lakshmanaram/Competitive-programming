#include <bits/stdc++.h>
using namespace std;
int onex(int x){
    int y = x/3;
    int ans = y*2;
    ans += x%3;
    return ans;
}
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        int r,c;
        infile>>r>>c;
        int ans = 0;
        if(r == 1 || c == 1){
            ans = onex(max(r,c));
        } else if( r==2 || c == 2) {
            ans = 2*onex(max(r,c));
        } else {
            int rr = r%3;
            int rc = c%3;
            int x = r/3, y = c/3;
            ans = 6*x*y;
            if(rr == 1) {
                ans += 2*y;
            } else if(rr == 2){
                ans += 4*y;
            }
            if(rc == 1) {
                ans += 2*x;
            } else if(rc==2) {
                ans += 4*y;
            }
            if(rr == 1 && rc == 1) {
                ans += 1;
            } else if(rr == 2 && rc == 1) {
                ans += 2;
            } else if(rr == 1 && rc == 2) {
                ans += 2;
            } else if(rr == 2 && rc == 2) {
                ans += 3;
            }

        }
        outfile<<"Case #"<<tk<<": "<<ans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
