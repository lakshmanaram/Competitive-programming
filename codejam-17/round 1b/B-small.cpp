#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long n;
        infile >> n;
        long r,g,y,b,o,v;
        infile>>r>>o>>y>>g>>b>>v;
        bool answerf = true;
        if( g >= r || o >= b || v >= y)
            answerf = false;
        r -= g;
        b -= o;
        y -= v;
        r--;
        b--;
        y--;
        vector<pair<long,char> > arr;
        arr.push_back(make_pair(r+g,'R'));
        arr.push_back(make_pair(y+v,'Y'));
        arr.push_back(make_pair(b+o,'B'));
        sort(arr.begin(),arr.end());
        if(arr[0].first + arr[1].first < arr[2].first){
            answerf = false;
        }
        if(answerf) {
            string s = "";
            char fi, sec, th;
            fi = arr[0].second;
            sec = arr[1].second;
            th = arr[2].second;
            long excess = arr[0].first - (arr[2].first - arr[1].first);
            long secval = arr[1].first;
            while(n) {
                cout<<n<<endl;
                if(th == 'R') {
                    if(r){
                        s += 'R';
                        r--;
                        n--;
                    } else if(g) {
                        s += 'R';
                        while(g--)
                            s += "GR";
                        g = 0;
                        n -= g*2+1;
                    }
                } else if (th == 'B') {
                    if(b){
                        s += 'B';
                        b--;
                        n--;
                    } else if(o) {

                        s += 'B';
                        while(o--)
                            s += "OB";
                        o = 0;
                        n -= o*2+1;
                    }
                } else {
                    if(y){
                        s += 'Y';
                        y--;
                        n--;
                    } else if(v) {
                        s += 'Y';
                        while(v--)
                            s += "VY";
                        v = 0;
                        n -= v*2+1;
                    }
                }
                if(secval){
                    secval--;
                    if(sec == 'R') {
                        if(r){
                            s += 'R';
                            r--;
                            n--;
                        } else if(g) {
                            s += "RGR";
                            g--;
                            n -= 3;
                        }
                    } else if (sec == 'B') {
                        if(b){
                            s += 'B';
                            b--;
                            n--;
                        } else if(o) {
                            s += "BOB";
                            o--;
                            n -= 3;
                        }
                    } else {
                        if(y){
                            s += 'Y';
                            y--;
                            n--;
                        } else if(v) {
                            s += "YVY";
                            v--;
                            n -= 3;
                        }
                    }
                } else {
                    if(fi == 'R') {
                        if(r){
                            s += 'R';
                            r--;
                            n--;
                        } else if(g) {
                            s += "RGR";
                            g--;
                            n -= 3;
                        }
                    } else if (fi == 'B') {
                        if(b){
                            s += 'B';
                            b--;
                            n--;
                        } else if(o) {
                            s += "BOB";
                            o--;
                            n -= 3;
                        }
                    } else {
                        if(y){
                            s += 'Y';
                            y--;
                            n--;
                        } else if(v) {
                            s += "YVY";
                            v--;
                            n -= 3;
                        }
                    }
                }
                if(excess) {
                    excess--;
                    if(fi == 'R') {
                        if(r){
                            s += 'R';
                            r--;
                            n--;
                        } else if(g) {
                            s += "RGR";
                            g--;
                            n -= 3;
                        }
                    } else if (fi == 'B') {
                        if(b){
                            s += 'B';
                            b--;
                            n--;
                        } else if(o) {
                            s += "BOB";
                            o--;
                            n -= 3;
                        }
                    } else {
                        if(y){
                            s += 'Y';
                            y--;
                            n--;
                        } else if(v) {
                            s += "YVY";
                            v--;
                            n -= 3;
                        }
                    }

                }
            }
            outfile<<"Case #"<<tk<<": "<<s;
            outfile<<endl;
        } else {
            r += 2*g;
            b += 2*o;
            y += 2*v;
            if ( r == 0 && b == 0 && o == 0 && g == 0 && y == v) {
                string s = "";
                while(y--) s += "YV";
                outfile<<"Case #"<<tk<<": "<<s<<endl;
            } else if (y == 0 && b == 0 && o == 0 && v == 0 && r == g) {
                string s = "";
                while(r--) s += "RG";
                outfile<<"Case #"<<tk<<": "<<s<<endl;
            } else if (y == 0 && r == 0 && g == 0 && v == 0 && b == o) {
                string s = "";
                while(b--) s += "BO";
                outfile<<"Case #"<<tk<<": "<<s<<endl;
            } else {
                outfile<<"Case #"<<tk<<": IMPOSSIBLE"<<endl;
            }
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
