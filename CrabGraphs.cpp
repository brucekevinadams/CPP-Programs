#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;
using Matrix=vector<vector<int>>;

int residual_capacity(const Matrix &cap, const Matrix &flow, int from, int to){
  if(cap[from][to]) return cap[from][to]-flow[from][to];
  else if(cap[to][from]) return flow[to][from]; 
  else return 0;
}

vector<int> residual_path(const Matrix &cap, const Matrix &flow){
  const int no_parent=-2, unvisited=-1;
  const int source=cap.size()-2,sink=source+1;
  vector<int> parent(sink+1,unvisited);
  parent[source]=no_parent;
  deque<int> bfs;
  vector<int> path;
  bfs.push_back(source);
  while(!bfs.empty()){
    int i=bfs.front(); bfs.pop_front();
    for(int j=0;j<cap.size();++j){
      if(parent[j]==unvisited){
	if(residual_capacity(cap,flow,i,j)){
	  if(j==sink){
	    path.push_back(sink);
	    int par=i;
	    while(par!=no_parent){
	      path.push_back(par);
	      par=parent[par];
	    }
	    return path;
	  }else{
	    parent[j]=i;
	    bfs.push_back(j);
	  }
	}
      }	
    }
  }
  return path;
}

Matrix max_flow(const Matrix &cap){
  const int source=cap.size()-2,sink=source+1;
  Matrix flow(sink+1,vector<int>(sink+1,0));
  auto path=residual_path(cap,flow);
  while(!path.empty()){
    int min_cap=cap.size();
    for(int j=0;j<path.size()-1;++j){
      int res_cap=residual_capacity(cap,flow,path[j+1],path[j]);
      if(res_cap<min_cap) min_cap=res_cap;
    }
    for(int j=0;j<path.size()-1;++j){
      if(cap[path[j+1]][path[j]]) flow[path[j+1]][path[j]] += min_cap;
      else flow[path[j]][path[j+1]] -= min_cap;
    }
    path=residual_path(cap,flow);
  }
  return flow;
}

int solve(Matrix &cap){
  const int source=cap.size()-2,nnode=source/2;
  auto flow=max_flow(cap);
  int total=0;
  for(int i=0;i<nnode;++i){
    if(flow[source][2*i]!=0){
      total+=flow[source][2*i];
    }
  }
  return total;
}

void input_case(){
  int nnode=0, nfeet=0, nedge=0;
  std::cin >> nnode >> nfeet >> nedge;
  const int source=2*nnode, sink=source+1;
  Matrix cap(sink+1,vector<int>(sink+1,0));
  while(nedge--){
    int i=0, j=0;
    std::cin >> i >> j; --i; --j;
    cap[2*i][2*j+1]=1;
    cap[2*j][2*i+1]=1;
    ++cap[source][2*i];
    ++cap[source][2*j];
  }
  for(int i=0;i<nnode;++i){
    cap[2*i+1][sink]=1;
    if(cap[source][2*i]>nfeet){
      cap[source][2*i]=nfeet;
    }
  }
  std::cout << solve(cap) << '\n';
}

int main(){
  int ncase=0;
  std::cin >> ncase;
  while(ncase--) input_case();
}