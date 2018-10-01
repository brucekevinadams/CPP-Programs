/*
* Author: Bruce Adams
* www.austingamestudios.com
* C++ program
* Hackerrank problem
*/


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

const int invalid=-1;

int move(const char dir, const int i, const int n, const int m){
  switch(dir){
  case 'U': return i/m ? i-m : invalid;
  case 'D': return (i+m)/(n*m) ? invalid : i+m;
  case 'L': return i%m ? i-1 : invalid;
  case 'R': return (i+1)%m? i+1 : invalid;
  }
  return invalid;
}

int solve(const int n, const int m, const int k, const string &grid){
  const char win='*';
  if(grid[0]==win) return 0;
  const int upper=n*m, not_found=-1;
  vector<int> ops(n*m,upper);
  vector<bool> just_seen(n*m,false);
  just_seen[0]=true;
  ops[0]=0;
  int best=not_found;
  const char dirs[]={'U','D','L','R'};
  for(int l=0;l<k;++l){
    vector<bool> seen(n*m,false);
    for(int i=0;i<n*m;++i){
      if(just_seen[i]){
	for(const char dir: dirs){
	  int j=move(dir,i,n,m);
	  if(j!=invalid){
	    int val=ops[i]+(grid[i]!=dir);
	    if(grid[j]==win){
	      if(best==not_found || val<best) best=val;
	    }else if(val<ops[j]){
	      seen[j]=true;
	      ops[j]=val;
	    }
	  }
	}
      }
    }
    seen.swap(just_seen);
  }
  return best;
}

int main(){
  int n=0,m=0,k=0;
  std::cin >> n >> m >> k;
  string grid;
  for(int i=0;i<n;++i){
    string row;
    std::cin >> row;
    grid.append(row);
  }
  std::cout << solve(n,m,k,grid) << '\n';
}
