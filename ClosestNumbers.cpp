/*
* Author: Bruce Adams
* www.austingamestudios.com
* C++ program
* Hackerrank problem
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i=0;i<n;i++) cin >> a[i];

  sort(a,a+n);
  int diff[n];
  adjacent_difference(a,a+n,diff);
  int min=*min_element(diff+1,diff+n);

  for (int i=1;i<n;i++) {
      if (diff[i]==min) cout << a[i-1] << " " << a[i] << " ";
  }
}
