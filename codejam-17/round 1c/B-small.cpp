#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
    if((1440+a.second - a.first)%1440 < (b.second-b.first)%1440)
        return true;
    else
        return false;
}
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long c,ja;
        infile>>c>>ja;
        vector<pair<long long, long long> > cam(c), jai(ja);
        for(long i=0;i<c;i++)
            infile>> cam[i].first>> cam[i].second;
        for(long i=0;i<ja;i++)
            infile>> jai[i].first>> jai[i].second;
        long long ans = 0;
        long totc = 720;
        long totj = 720;
        vector<pair<long long, long long> > tc, tj;
        vector<char> arr(1440,'.');
        for(int i=0;i<c;i++) {
            for(int j=cam[i].first;j<cam[i].second;j++){
                arr[j] = 'J';
                totj--;
            }
        }
        for(int i=0;i<ja;i++) {
            for(int j=jai[i].first;j<jai[i].second;j++){
                arr[j] = 'C';
                totc--;
            }
        }
        char prev = 'S';
        bool dots = false;
        int ind = 0;
        for(int i=0;i<1440;i++) {
            if(arr[i] == 'C') {
                if(dots) {
                    dots = false;
                    if(prev == 'C'){
                        tc.push_back(make_pair(ind+1,i));
                    }
                    prev = 'C';
                } else {
                    ind = i;
                    prev = 'C';
                }
            } else if(arr[i] == 'J') {
                if(dots) {
                    dots = false;
                    if(prev == 'J'){
                        tj.push_back(make_pair(ind+1,i));
                    }
                    prev = 'J';
                } else {
                    ind = i;
                    prev = 'J';
                }
            } else {
                dots = true;
            }
        }
        if(arr[0] == '.') dots = true;
        for(int i=0;(i<1440) && dots;i++) {
            if(arr[i] == 'C') {
                if(dots) {
                    dots = false;
                    if(prev == 'C'){
                        tc.push_back(make_pair(ind+1,i));
                    }
                    prev = 'C';
                } else {
                    ind = i;
                    prev = 'C';
                }
            } else if(arr[i] == 'J') {
                if(dots) {
                    dots = false;
                    if(prev == 'J'){
                        tj.push_back(make_pair(ind+1,i));
                    }
                    prev = 'J';
                } else {
                    ind = i;
                    prev = 'J';
                }
            }
        }
        sort(tc.begin(),tc.end(),comp);
        sort(tj.begin(),tj.end(),comp);
        for(int i=0;i<tc.size() && totc > 0;i++) {
            long val = (1440+tc[i].second-tc[i].first)%1440;
            if(val > totc)
                break;
            totc -= val;
            if(tc[i].second >= tc[i].first) {
                for(int j=tc[i].first;j < tc[i].second;j++){
                    arr[j] = 'C';
                }
            } else {
                for(int j=tc[i].second;j < 1440;j++){
                    arr[j] = 'C';
                }
                for(int j=0;j < tc[j].second;j++){
                    arr[j] = 'C';
                }
            }
        }
        for(int i=0;i<tj.size() && totj > 0;i++) {
            long val = (1440+tj[i].second-tj[i].first)%1440;
            if(val > totj)
                break;
            totj -= val;
            if(tj[i].second >= tj[i].first) {
                for(int j=tj[i].first;j < tj[i].second;j++){
                    arr[j] = 'J';
                }
            } else {
                for(int j=tj[i].second;j < 1440;j++){
                    arr[j] = 'J';
                }
                for(int j=0;j < tj[j].second;j++){
                    arr[j] = 'J';
                }
            }
        }
        dots = false;
        prev = 'S';
        for(int i=0;i<1440;i++) {
            if(arr[i] == 'C') {
                if(dots) {
                    dots = false;
                    if(prev == 'C'){
                        ans += 2;
                    } else if(prev == 'J'){
                        ans++;
                    }
                } else {
                    if(prev == 'J') ans++;
                }
                prev = 'C';
            } else if(arr[i] == 'J') {
                if(dots) {
                    dots = false;
                    if(prev == 'J'){
                        ans += 2;
                    } else if(prev == 'C'){
                        ans++;
                    }
                } else {
                    if(prev == 'C') ans++;
                }
                prev = 'J';
            } else {
                dots = true;
            }
        }
        // cout<<ans<<"endl;
        for(int i=0;i<1440;i++) {
            if(arr[i] == 'C') {
                if(dots) {
                    dots = false;
                    if(prev == 'C'){
                        ans += 2;
                        break;
                    } else if(prev == 'J'){
                        ans++;
                        break;
                    }
                } else {
                    if(prev == 'J'){ 
                        ans++;
                        break;
                    }
                }
                break;
            } else if(arr[i] == 'J') {
                if(dots) {
                    dots = false;
                    if(prev == 'J'){
                        ans += 2;
                        break;
                    } else if(prev == 'C'){
                        ans++;
                        break;
                    }
                } else {
                    if(prev == 'C') {
                        ans++;
                        break;
                    }
                }
                break;
            }
        }
        if(tk == 14) {
            for(int i=0;i<1440;i++) cout<<arr[i];
            cout<<endl;
        for(int i=0;i<ja;i++) {
            cout<<jai[i].first<<" "<<jai[i].second<<endl;
        }
        // cout<<tk<<endl;
        // for(int i=0;i<tc.size();i++){
        //     cout<<tc[i].first<<" "<<tc[i].second<<endl;
        // }
        // cout<<endl;
        // for(int i=0;i<tj.size();i++){
        //     cout<<tj[i].first<<" "<<tj[i].second<<endl;
        // }
        // cout<<endl;
        // cout<<endl;
    }
        outfile<<"Case #"<<tk<<": "<<ans;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
