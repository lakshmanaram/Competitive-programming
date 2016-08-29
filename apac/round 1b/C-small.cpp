#include <bits/stdc++.h>
using namespace std;
bool sortfunc(pair<long long, long long> a, pair<long long, long long> b){
    if(a.first < b.first)
        return true;
    return false;
}
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("C-small-attempt0.in");
    outfile.open("C-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        long long n,l,r,a,b,c1,c2,m;
        infile>>n>>l>>r>>a>>b>>c1>>c2>>m;
        a %= m;
        b %= m;
        c1 %= m;
        c2 %= m;
        vector<pair<long long, long long> > intervals;
        intervals.push_back(make_pair(l,r));
        long long newl,newr;
        for(long long i=1;i<n;i++){
            newl = (((a*l)%m + (b*r)%m)%m +c1)%m;
            newr = (((a*r)%m + (b*l)%m)%m +c2)%m;
            intervals.push_back(make_pair(min(newl,newr),max(newl,newr)));
            l = newl;
            r = newr;
        }
        sort(intervals.begin(),intervals.end(),sortfunc);
        cout<<"reached here"<<endl;
        long long ans = 0;
        for(long long i=0;i<n;i++){
            vector<pair<long long, long long> > ansints;
            for(long long j=0;j<n;j++){
                if(i!=j){
                    if(j==0 || ((i==0) && (j==1)))
                        ansints.push_back(intervals[j]);
                    else {
                        pair<long long, long long> cur = intervals[j];
                        long long pos = ansints.size()-1;
                        if(ansints[pos].second < cur.first)
                            ansints.push_back(cur);
                        else {
                            ansints[pos].second = max(ansints[pos].second, cur.second);
                        }
                    }
                }
            }
            long long tempans = 0;
            for(long long j=0;j<ansints.size();j++){
                tempans += ansints[j].second - ansints[j].first + 1;
            }
            if(i==0 || ans > tempans)
                ans = tempans;
        }
        outfile<<"Case #"<<tk<<": "<<ans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
