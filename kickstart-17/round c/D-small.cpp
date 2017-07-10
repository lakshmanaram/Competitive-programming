#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("D-small-attempt0.in");
    outfile.open("D-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        int ans = 2;
        int mini, maxi, mean, med;
        infile>>mini>>maxi>>mean>>med;
        bool flag = false;
        if(mini <= maxi && med >= mini && med <= maxi) {
            if(mini == maxi && mini == med && mini == mean){
                ans = 1;
                flag = true;
            } else if(mini + maxi == med*2 && med == mean){
                ans = 2;
                flag = true;
            } else if(mini + maxi + med == mean*3) {
                ans = 3;
                flag = true;
            } else if(mini+med*2+maxi == mean*4) {
                ans = 4;
                flag = true;
            } else {
                int rem = mean*5 - mini - maxi - med;
                int maxval = maxi+med;
                int minval = mini+med;
                if(rem >= minval && rem <= maxval){
                    ans = 5;
                    flag = true;
                } else {
                    int rem = mean*6 - mini - maxi-med*2;
                    int maxx = min(maxi,2*med-mini);
                    int mixx = max(mini,2*med-maxi);
                    int maxval = maxi+maxx;
                    int minval = mini+med;
                    if(rem >= minval && rem <= maxval){
                        ans = 6;
                        flag = true;
                    } else {
                        int rem = mean*7 -mini-maxi-med;
                        int maxval = maxi*2+med*2;
                        int minval = mini*2+med*2;
                        if(rem >= minval && rem <= maxval) {
                            ans = 7;
                            flag = true;
                        } else {
                            int rem = mean*8 - mini - maxi-med*2;
                            int maxval = maxi*2+med*2;
                            int minval = mini*2+med*2;
                            if(rem >= minval && rem <= maxval){
                                ans = 8;
                                flag = true;
                            } 
                        }
                    }
                }
            }
        }

        if(flag)
            outfile<<"Case #"<<tk<<": "<<ans<<endl; 
        else{
            outfile<<"Case #"<<tk<<": IMPOSSIBLE"<<endl; 
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
