/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 * C++ program from a Hackerrank problem.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int pivot, value;
    cin >> pivot;

    int freq[200 + 1] = { 0 };
    freq[100] = 1;
    
    for (int i = 1; i < n; ++i) {
        cin >> value;
        freq[100 + (value - pivot)]++;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> value;
        freq[100 + (value - pivot)]--;
    }

    for (int i = -100; i <= 100; ++i) {
        if (freq[100 + i] != 0)
            cout << (pivot + i) << " ";
    }

    return 0;
}
