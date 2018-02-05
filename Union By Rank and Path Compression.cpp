//Union By Rank and Path Compression
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include<cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <limits>
using namespace std;
#define siz(v)	((int)((v).size())) //get size of vector
#define inz(v, d) memset(v, d, sizeof(v)) // inizalize vector by d
#define repvector(i, v) for(int i=0;i<siz(v);++i)  //loop on vevtor from i to v.size
#define repincr(i, j, n) for(int i=(j);i<(int)(n);++i)
#define repdec(i, n)	for(int i=n-1;i>=0;--i)
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
double  EPS=numeric_limits<double>::epsilon();
struct vertice{int s;int d;}; // 0-1
vector<vertice>graph; // represent graph
int rank_subset[11]; // ranks of each node
int parent[11];  // parent of each node
void inzaltion(){
    for(int i=0;i<11;i++){
        rank_subset[i]=0; // => each node rank = 0
        parent[i]=i; // => each node is parent to itself
    }
}
//uses path compression
int find_parent(int s){
    if(parent[s]!=s){
        parent[s]=find_parent(parent[s]);
    }
    return parent[s];
}
//uses union by rank
void unoin_parent(int s,int d){
    int p1=find_parent(s);
    int p2=find_parent(d);
    if(rank_subset[p1]>rank_subset[p2]){
        parent[p2]=p1;
    }else if(rank_subset[p1]<rank_subset[p2]){
        parent[p1]=p2;
    }else{
        parent[p1]=p2;
        rank_subset[p2]=rank_subset[p2]+1;
    }
}
bool detect_cycle(){
    for(int i=0;i<graph.size();i++){
          int p1=find_parent(graph[i].s);
          int p2=find_parent(graph[i].d);
          if(p1==p2){
            return 1;
          }
          unoin_parent(p1,p2);
    }

}
int main(){
    std::ios_base::sync_with_stdio(0);
    inzaltion();
     /* graph
        0-----3
        |     |
        |     |
        1-----2
    */
    vertice j;
    j.s=0;j.d=1;
    graph.push_back(j);
    vertice j1;
    j1.s=1;j1.d=2;
    graph.push_back(j1);
    vertice j3;
    j3.s=2;j3.d=3;
    graph.push_back(j3);
    j3.s=3;j3.d=0;
    graph.push_back(j3);
    bool f=detect_cycle();
    if(f){cout<<"yes";}
    else{cout<<"no";}
    return 0;

}


