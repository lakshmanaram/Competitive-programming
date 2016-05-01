#include <bits/stdc++.h>
using namespace std;
int getc(char a){
    return ((int)a - (int)('A'));
}
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("A-large.in");
    outfile.open("A-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        string s;
        infile>>s;
        vector<int> hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[getc(s[i])]++;
        }
        vector<int> nos(10,0);
        nos[0] = hash[getc('Z')];
        int x;
        x = hash[getc('Z')];
        hash[getc('Z')] = 0;
        hash[getc('E')] -= x;
        hash[getc('R')] -= x;
        hash[getc('O')] -= x;
        x = hash[getc('W')];
        nos[2] = x;
        hash[getc('T')] -= x;
        hash[getc('W')] -= x;
        hash[getc('O')] -= x;
        x = hash[getc('U')];
        nos[4] = x;
        hash[getc('F')] -= x;
        hash[getc('O')] -= x;
        hash[getc('U')] -= x;
        hash[getc('R')] -= x;
        x = hash[getc('X')];
        nos[6] = x;
        hash[getc('S')] -= x;
        hash[getc('I')] -= x;
        hash[getc('X')] -= x;
        x = hash[getc('R')];
        nos[3] = x;
        hash[getc('T')] -= x;
        hash[getc('H')] -= x;
        hash[getc('R')] -= x;
        hash[getc('E')] -= x;
        hash[getc('E')] -= x;
        x = hash[getc('H')];
        nos[8] = x;
        hash[getc('E')] -= x;
        hash[getc('I')] -= x;
        hash[getc('G')] -= x;
        hash[getc('H')] -= x;
        hash[getc('T')] -= x;
        x = hash[getc('O')];
        nos[1] = x;
        hash[getc('O')] -= x;
        hash[getc('N')] -= x;
        hash[getc('E')] -= x;
        x = hash[getc('F')];
        nos[5] = x;
        hash[getc('F')] -= x;
        hash[getc('I')] -= x;
        hash[getc('V')] -= x;
        hash[getc('E')] -= x;
        x = hash[getc('V')];
        nos[7] = x;
        hash[getc('S')] -= x;
        hash[getc('E')] -= x;
        hash[getc('V')] -= x;
        hash[getc('E')] -= x;
        hash[getc('N')] -= x;
        x = hash[getc('I')];
        nos[9] = x;
        hash[getc('N')] -= x;
        hash[getc('I')] -= x;
        hash[getc('N')] -= x;
        hash[getc('E')] -= x;
        outfile<<"Case #"<<tk<<": ";
        for(int i=0;i<10;i++){
            for(int j=0;j<nos[i];j++)
                outfile<<i;
        }
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
