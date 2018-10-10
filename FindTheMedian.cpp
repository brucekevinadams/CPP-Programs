#include <bits/stdc++.h>

using namespace std;

int main() {
    int size, entry, sum = 0;
    cin >> size;
    vector<int> arr_v(20001);
    
    for (int i = 0; i < size; i++) {
        cin >> entry;
        arr_v[entry+10000]++;
    }
    
    for (int i = 0 ; i < arr_v.size(); i++) {
        sum += arr_v[i];
        if (sum > size/2) {
            cout << i - 10000 << endl;
            break;
        }
    }   
    return 0;
}