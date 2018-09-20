#include <bits/stdc++.h>
#include <iterator>

using namespace std;

typedef long long ll;

int main() {
    int iTest; cin >> iTest;
    while(iTest--){
        ll iNum; cin >> iNum; 
        ll iArr[iNum], iLow[iNum]={}, iHigh[iNum]={};
        copy_n(istream_iterator<ll>(cin), iNum, iArr);
        transform(iArr,iArr+iNum,iArr,[](ll i){return --i;});
        for(ll i = 1; i < iNum; i++){
            iLow[i]=max(iLow[i-1],iHigh[i-1]+iArr[i-1]);
            iHigh[i]=max(iLow[i-1]+iArr[i],
            iHigh[i-1]+abs(iArr[i-1]-iArr[i]));
        }
        cout << max(iLow[iNum-1],iHigh[iNum-1]) << endl;
    }
    return 0;
}