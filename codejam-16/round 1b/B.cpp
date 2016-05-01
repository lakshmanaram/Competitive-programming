#include <bits/stdc++.h>
using namespace std;
int getc(char a){
    return ((int)a - (int)('0'));
}
int getnum(string a){
    int ans = 0;
    for(int i=0;i<a.size();i++){
        ans *= 10;
        ans += getc(a[i]);
    }
    return ans;
}
bool ispossi(int a, string s){
    stack<char> t;
    int k = s.size();
    while(k--){
        t.push('0'+a%10);
        a/=10;
    }
    string b;
    while(!t.empty()){
        b += t.top();
        t.pop();
    }
    for(int i=0;i<b.size();i++){
        if(s[i]!='?' && s[i]!=b[i])
            return false;
    }
    return true;
}
string getv(int a, string s){
    stack<char> t;
    int k = s.size();
    while(k--){
        t.push('0'+a%10);
        a/=10;
    }
    string b;
    while(!t.empty()){
        b += t.top();
        t.pop();
    }
    return b;
}
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("B-small-attempt0.in");
    outfile.open("B-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        string c,j;
        string a1,a2;
        infile>>c>>j;
        if(c.size()==1){
            if(c == "?" && j == "?"){
                a1=a2="0";
            }else if(c == "?"){
                a1 = a2 = j;
            }else if(j == "?"){
                a1 = a2 = c;
            }else{
                a1 = c;
                a2 = j;
            }
        }else{
            int val = -1,cval,jval;
            for(int i=0;i<pow(10,c.size());i++){
                if(ispossi(i,c)){
                    for(int k=0;k<pow(10,j.size());k++){
                        if(ispossi(k,j)){
                            if(val == -1 || val > abs(k-i)){
                                cval = i;
                                jval = k;
                                val = abs(k-i);
                            }
                            else if(val==abs(k-i)){
                                if(i < cval){
                                    cval = i;
                                    jval = k;
                                    val = abs(k-i);
                                }else if(i==cval){
                                    if(k<jval){
                                        cval = i;
                                        jval = k;
                                        val = abs(k-i);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            a1 = getv(cval,c);
            a2 = getv(jval,j);
        }
        outfile<<"Case #"<<tk<<": ";
        outfile<<a1<<" "<<a2;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
