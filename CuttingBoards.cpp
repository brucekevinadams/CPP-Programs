#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<long long int,char> a, pair<long long int ,char> b)
    {
    return a.first>b.first;
}

int main() {
   long long int i,j,k,v,t,n,m;
    cin>>t;
    for(v=0;v<t;v++)
        {
        cin>>m>>n;
        vector<pair<long long int,char>>vect;
        for(i=0;i<m-1;i++)
            {
            cin>>j;
            vect.push_back(make_pair(j,'h'));
        }
         for(i=0;i<n-1;i++)
            {
            cin>>j;
            vect.push_back(make_pair(j,'v'));
        }
        sort(vect.begin(),vect.end(),cmp);
        long long int ht_segments=0,vt_segments=0,ans=0;
        vector<pair<long long int,char>>::iterator ii; 
        for(ii=vect.begin();ii!=vect.end();ii++)
            {
            if(ii->second=='h')
                {
                if(ht_segments==0)
                    ht_segments+=2;
                else
                    ht_segments++;
                if(vt_segments>0)
                    ans+=(ii->first*vt_segments);
                else
                    ans+=ii->first;
                    
            }
            else{
                 if(vt_segments==0)
                    vt_segments+=2;
                else
                    vt_segments++;
                if(ht_segments>0)
                    ans+=(ii->first*ht_segments);
                else
                    ans+=ii->first;
                
            }
        }
        cout<<ans%(1000000007)<<"\n";
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}