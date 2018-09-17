/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 * C++ program from a Hackerrank problem.
*/

#include <iostream>
#include <vector>
#include <deque>

unsigned move(const unsigned state, const unsigned rod, const unsigned disc){
  return (state & ~(3<<2*(disc-1))) | rod<<2*(disc-1);
}

unsigned get_disc(const unsigned ndisc, const unsigned state, const unsigned rod){
  unsigned disc=ndisc+1;
  for(unsigned h=ndisc;h!=0;--h){
    unsigned r=3&state>>2*(h-1);
    if(r==rod) disc=h;
  }
  return disc;
}

unsigned long solve(const unsigned ndisc,unsigned start){
  const unsigned win=0;
  if(start==win) return 0;
  std::deque<unsigned> bfs;
  bfs.push_back(start);
  std::vector<unsigned> depth(1<<2*ndisc,0);
  depth[start]=0;
  while(true){
    unsigned par=bfs.front();
    bfs.pop_front();
    unsigned d[4];
    for(unsigned rod=0;rod<4;++rod){
      d[rod]=get_disc(ndisc,par,rod);
    }
    for(unsigned from=0;from<4;++from){
      if(d[from]==ndisc+1) continue;
      for(unsigned to=0;to<4;++to){
	if(d[to]>d[from]){
	  unsigned ch=move(par,to,d[from]);
	  if(ch==win) return 1+depth[par];
	  if(!depth[ch] && ch!=start){
	    depth[ch]=1+depth[par];
	    bfs.push_back(ch);
	  }
	}
      }
    }
  }
  return -1;
}

int main(){
  unsigned ndisc=0, start=0;
  std::cin >> ndisc;
  for(unsigned h=1;h<=ndisc;++h){
    unsigned rod=0;
    std::cin >> rod;
    --rod;
    start=move(start,rod,h);
  }
  std::cout << solve(ndisc,start);
}
