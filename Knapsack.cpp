#include <bits/stdc++.h>
using namespace std;

int a[2001];

int sumfn(int sum,int n)
{
	if(n==0 ||sum==0)
	return 0;
	
	if(a[n-1]>sum)
	return sumfn(sum,n-1);
	
	
	return max(a[n-1]+sumfn(sum-a[n-1],n),sumfn(sum,n-1));
}


int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout<<sumfn(sum,n)<<endl;
        
    }
    
    return 0;
}