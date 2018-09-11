/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 * C++ program from a Hackerrank problem.
*/

#include <bits/stdc++.h>

using namespace std;

vector< pair <int,int> > merge(vector< pair <int,int> > &v) {
    vector< pair <int,int> > merged;
    
    if(v.size() != 0) {
        sort(v.begin(), v.end());
    }
    stack< pair<int,int> > s;
    int n=v.size();
    s.push(v[0]);    
    for(int i=1;i<n;i++){
        pair <int,int> top;
        top=s.top();
        if(v[i].first > top.second)
            s.push(v[i]);
            top.second=v[i].second;
        else if(top.second < v[i].second){   
            s.pop();
            s.push(top);
        }
    }
    while(!s.empty()){
        merged.push_back(s.top());
        s.pop();
    }
    return merged;
}

int main() {
    map< int,vector< pair <int,int> > > track;
    int n, m, k; 
    cin >> n >> m >> k;
    
    
    for(long i = 0; i < k; ++i) {
        int r, c1, c2; cin >> r >> c1 >> c2;
        track[r].push_back(make_pair(c1, c2));
    }
    long totalcells = ((long)n) * ((long)m);    // gridland total cells
    
    for(auto &node : track){            
        node.second = merge(node.second);
        vector< pair <int,int> > tr=node.second;   
        for(int i=0;i<tr.size();i++){
               totalcells-=((long)tr[i].second)-((long)tr[i].first)+1;
        }
    }    
    cout<<totalcells<<endl;
    return 0;
}
