#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    vector<long> children;
    // vector<char> edge_val;
    map<long,char> edge_v;
};
long answer;
long parent;
vector<bool> myfuncvis;
bool myfunction(long a, long b);
// vector<bool> vis(20001);
class graph{
    public:
    node vertex[20001];
    void add(long a, long b,char c){                                //have to arrange them in descending order here
        vertex[a].children.push_back(b);
        vertex[b].children.push_back(a);
        vertex[a].edge_v[b] = c;
        vertex[b].edge_v[a] = c;
        // vertex[a].edge_val.push_back(c);
        // vertex[b].edge_val.push_back(c);
    }
    bool isleaf(long a,vector<bool> vis){
        vector<long> check = vertex[a].children;
        vector<long>::iterator it;
        for(it = check.begin();it<check.end();it++){
            if(vis[*it] == false)
                return false;
        }
        return true;
    }
    vector<char> find_end(long a,vector<bool> vis,vector<char> path){
        // length_count++;
        parent = a;
        myfuncvis = vis;
        vis[a] = true;
        long ans;
        if(isleaf(a,vis)){
            answer = a;
            return path;
        }
        else{
            vector<long> nchildren = vertex[a].children;
            map<long, char> m = vertex[a].edge_v;
            // vector<char> nedge_val = vertex[a].edge_val;
            sort(nchildren.begin(),nchildren.end(),myfunction);
            vector<long> vertices;
            vector<char> values;
            vector<long>::iterator it;
            vector<long> ans_values;
            vector<long> ans_edge;
            char high_val = 'a' -1;
            ans_values.push_back(nchildren[0]);
            high_val = m[nchildren[0]];
            ans_edge.push_back(high_val);

            for(it = nchildren.begin()+1;it!= nchildren.end();it++){
                if(vis[*it]!=true){
                    // vertices.push_back(*it);
                    // char val = *(it - nchildren.begin() + nedge_val.begin());
                    char val = m[*it];
                    // values.push_back(val);
                    // if(val>high_val){
                    //     ans_values.clear();                                                     //dunno whether it will work
                    //     ans_values.push_back(*it);
                    //     ans_edge.clear();
                    //     ans_edge.push_back(val);
                    //     high_val = val;
                    // }
                    // else 
                    if(val == high_val){
                        ans_values.push_back(*it);
                        ans_edge.push_back(val);
                    }
                    else{
                        break;
                    }
                }
            }
            if(ans_values.size()>1){
                vector<char> compare_path,temp_path;
                long temp;
                path.push_back(ans_edge[0]);
                compare_path = find_end(ans_values[0],vis,path);
                path.pop_back();
                ans = answer;
                for(long j=1;j<ans_values.size();j++){
                    path.push_back(ans_edge[j]);
                    temp_path = find_end(ans_values[j],vis,path);
                    if(compare_path == temp_path){
                        if(answer>ans)
                            ans = answer;
                    }
                    else if(lexicographical_compare(compare_path.begin(),compare_path.end(),temp_path.begin(),temp_path.end())){
                        compare_path = temp_path;
                        ans = answer;
                    }
                    path.pop_back();
                }
                path = compare_path;
                answer = ans;


                // long temp_length = length_count;
                // long temp;
                // temp = find_end(ans_values[0],vis);
                // ans = temp;
                // long compare_length = length_count;
                // length_count = temp_length;
                // for(long j=1;j<ans_values.size();j++){
                //     temp = find_end(ans_values[j],vis);
                //     if(length_count>compare_length){
                //         compare_length = length_count;
                //         ans = temp;
                //     }
                //     else if(length_count == compare_length){
                //         if(temp>ans)
                //             ans = temp;
                //     }
                //     length_count = temp_length;
                // }
            }
            else{
                long pos = ans_values[0];
                path.push_back(ans_edge[0]);
                path = find_end(pos,vis,path);
            }
        }
        vis[a] = false;
        return path;
    }
    long get_answer(long a){
        vector<bool> vis(20001);
        vector<char> path;
        fill(vis.begin(),vis.end(),false);
        // length_count = 0;
        path = find_end(a,vis,path);
        return answer;
    }
}g;

    bool myfunction(long a, long b){
        vector<bool> vis = myfuncvis;
        if(vis[a]==false&&vis[b]==true)
            return true;
        else if(vis[a]==true&&vis[b]==false)
            return false;
        else if(vis[a]==true && vis[b]== true)
            return true;
        map<long, char> m = g.vertex[parent].edge_v;
        if(m[a]>m[b])
            return true;
        else
            return false;

    }

int main() {
    long n;
    cin>>n;
    long a,b;
    char ch;
    long i;
    for(i=1;i<n;i++){
        cin>>a>>b>>ch;
        g.add(a,b,ch);
    }
    for(i=1;i<=n;i++){
        cout<<g.get_answer(i)<<" ";
    }
    return 0;
}