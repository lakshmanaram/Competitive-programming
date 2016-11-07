#include <bits/stdc++.h>
using namespace std;
long long ans = 0;

int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-large.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        ans = 0;
        long n,d;
        infile>>n>>d;
        for(long i=d;i<=n;i+=d){
            if(n%i == 0)
                ans++;
            long x = 1;

            // ans += max((long)0,n/(i*(i+1)));
            //     outfile<<ans<<endl;
            // ans += max((long)0,n/(i*(i+2)));
            //     outfile<<"n"<<ans<<endl;
            while(x < n/i){
                if((n-i*x)%(i+1) == 0){
                    ans++;
                    ans += (n-i*x)/(i*(i+1));
                    if(n%i==0)
                        ans--;
                    break;
                } 
                x++;
            }
            x= 1;
            while(x < n/i){
                if((n-i*x)%(i+2) == 0){
                    ans++;
                } 
                x++;
            }
            x = 1;
            while(x < n/i){

                // if((n-i*x)%(i+1) == 0){
                //     ans++;
                // } 
                // if((n-i*x)%(i+2) == 0){
                //     ans++;
                // } 
                long temp = n-i*x;
                long y = 1;
                while( y < temp/(i+1)){
                    if((temp-(i+1)*y)%(i+2) == 0){
                        ans++;
                        ans += (temp-(i+1)*y)/((i+2) *(i+1));
                        if(temp % (i+1) == 0)
                            ans--;
                        break;
                    }
                    y++;
                }
                x++;
            }
            x = 1;
        }
        outfile<<"Case #"<<tk<<": "<<ans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
