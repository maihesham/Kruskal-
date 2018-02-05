// Kruskal Algorithm
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
struct vertice{int s;int d;int w;}; // 0-1
vector<vertice>graph; // represent graph
vector<vertice>min_spainning_tree;
int rank_subset[11]; // ranks of each node
int parent[11];  // parent of each node
int V = 4;  // Number of vertices in graph
int E = 5;  // Number of edges in graph
int newedges=V-1 , value_of_min_spanning_tree=0;
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
bool detect_cycle(int x, int y){

          int p1=find_parent(x);
          int p2=find_parent(y);
          if(p1==p2){
            return 1;
          }
          unoin_parent(p1,p2);
          return 0;


}
bool my_compare(const struct vertice &x, const struct vertice &y){
    return x.w<y.w;}
void  KruskalMST(){
    //sort
    sort(graph.begin(),graph.end(),my_compare);
    int e=0;
    for(int i=0;i<graph.size();i++){
          bool f=detect_cycle(graph[i].s,graph[i].d);
          if(f==0){
            min_spainning_tree.push_back(graph[i]);
            value_of_min_spanning_tree+=graph[i].w;
            e++;
          }
          if(e==newedges){break;}
    }
    cout<<"new min _ spanning tree "<<endl;
    cout<<"value of new tree is "<<value_of_min_spanning_tree<<endl;
     for(int i=0;i<min_spainning_tree.size();i++){
            cout<<"cost from "<<min_spainning_tree[i].s<<"to  "<<min_spainning_tree[i].d<<" => "<<min_spainning_tree[i].w<<endl;
      }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    inzaltion();
    /*
                10
            0--------1
            |  \     |
           6|   5\   |15
            |      \ |
            2--------3
                4       */

    vertice j;
    j.s=0;j.d=1; j.w=10;
    graph.push_back(j);
    vertice j1;
    j1.s=1;j1.d=3; j1.w=15;
    graph.push_back(j1);
    vertice j2;
    j2.s=0;j2.d=3; j2.w=5;
    graph.push_back(j2);
    vertice j3;
    j3.s=2;j3.d=3;j3.w=4;
    graph.push_back(j3);
    j3.s=2;j3.d=0;j3.w=6;
    graph.push_back(j3);
    KruskalMST();

    return 0;

}


