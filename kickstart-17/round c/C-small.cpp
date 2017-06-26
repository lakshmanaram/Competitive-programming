#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-large.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        int n,q;
        infile>>n>>q;
        if(n == 1) {
            string fa, me;
            infile>>fa>>me;
            int score;
            infile>>score;
            int sa = score, nsa = q-score;
            int ans = 0;
            for(int i=0;i<q;i++){
                if(fa[i] == me[i] && sa > 0){
                    ans++;
                    sa--;
                } else if(fa[i] != me[i] && nsa > 0){ 
                    ans++;
                    nsa--;
                }
            }
            outfile<<"Case #"<<tk<<": "<<ans<<endl;
        } else {
            string fa, fb, me;
            infile>>fa>>fb>>me;
            int scorea, scoreb;
            infile>>scorea>>scoreb;
            int sa = scorea, nsa = q-scorea;
            int sb = scoreb, nsb = q-scoreb;
            int ans = 0;
            int c1, c2, c3, c4;
            c1 = c2 = c3 = c4 = 0;
            for(int i=0;i<q;i++){
                if(fa[i] == me[i] && fb[i] == me[i]){
                    // ans++;
                    // sa--;
                    // sb--;
                    c1++;
                } else if(fa[i] != me[i] && fb[i] != me[i] && nsa > 0 && nsb > 0){ 
                    // ans++;
                    // nsa--;
                    // nsb--;
                    c2++;
                    // cout<<"here 2"<<endl;
                } else if(fa[i] != me[i] && fb[i] == me[i] && nsa > 0 && sb > 0){
                    // ans++;
                    // nsa--;
                    // sb--;
                    // cout<<"here 3"<<endl;
                    c3++;
                } else if(fa[i] == me[i] && fb[i] != me[i] && sa > 0 && nsb > 0) {
                    // ans++;
                    // nsb--;
                    // sa--;
                    // cout<<"here 4"<<endl;
                    c4++;
                }
            }
            // c1+c4 <= sa
            // c1+c3 <= sb
            // c2+c3 <= nsa
            // c2+c4 <= nsb
            for(int i1 = 0;i1 <= min(c1,min(sa,sb)); i1++){
                for(int i2 = 0;i2 <= min(c2,min(nsa,nsb));i2++){
                    int i3 = min(min(sb-i1,nsa-i2),c3);
                    int i4 = min(min(sa-i1,nsb-i2),c4);
                    ans = max(i1+i2+i3+i4, ans);
                    // cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<endl;
                }
            }
            outfile<<"Case #"<<tk<<": "<<ans<<endl;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
