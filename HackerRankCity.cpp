/*
* Author: Bruce Adams
* www.austingamestudios.com
* C++ program
* Hackerrank problem
*/

#include <iostream>
#include <ios>

const int mod=1000000007;

int add(int a, int b){
  return static_cast<int>((0L+a+b)%mod);
}

int mul(int a, int b){
  return static_cast<int>((1L*a*b)%mod);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int n=0;
  std::cin >> n;
  int a=0,b=0,c=0,d=0,m=1;
  for(int i=0;i<n;++i){
    int bp=b, cp=c, dp=d, mp=m;
    std::cin >> a;
    m=add(2,mul(4,mp));
    d=add(3*a,mul(2,dp));
    b=mul(mp,add(8*a,mul(3,dp)));
    int bterm[]={mul(4,bp), 3*a, mul(2,dp)};
    for(int term: bterm) b=add(b,term);
    c=mul(mul(12,mp),add(a,bp));
    int cterm[]={a,mul(4,cp),mul(8,bp),mul(16*a,mul(mp,mp))};
    for(int term: cterm) c=add(c,term);
  }
  std::cout << c;
}
