#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int id[MAX],size[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];
void initialize()
{
for(int i=0;i<MAX;i++)
{
    id[i]=i;
    size[i]=1;
}
}

 int root(int i)
    {
        int j=i;
        while(id[j]!=j)
            j=id[id[j]];
        while(i!=j)
        {
            int newp=id[i];
            id[i]=j;
            i=newp;
        }
        return j;
    }
 void union1(int p,int q)
    {
        int i=root(p);
         int j=root(q);
         if(size[i]>size[j])
         {
             id[j]=i;
             size[i]+=size[j];
         }
         else
         {
            id[i]=j;
             size[j]+=size[i];
         }
    }
long long rapturing()
{
      int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
       if(root(x)!=root(y))
           union1(x,y);
        if(root(0)==root(nodes-1))
        {
            minimumCost=cost;
            break;
        }
    }
    if(root(0)!=root(nodes-1))
        return -1;
        return minimumCost;
}
int main()
{
int x, y;
    long long weight, cost, minimumCost;
     initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair((x-1), (y-1)));
    }
    sort(p, p + edges);
    long long ans=rapturing();
    if(ans==-1)
        cout<<"NO PATH EXISTS";
    else
    cout<<ans;
}