/*
//Disjoint  Union-Find  
author  : mai
*/

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
struct vertice{int s;int d;};
vector<vertice>graph;
int nodes[11]; // max 10 nodes
int parent[11];
void inzaltion(){
    for(int i=0;i<11;i++){
        nodes[i]=i;
        parent[i]=-1;
    }
}
int find_parent(int s){
    if(parent[s]==-1){
        return s;
    }
    find_parent(parent[s]);
}
void unoin_parent(int s,int d){
    parent[s]=find_parent(d);
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


