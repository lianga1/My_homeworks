//description:summon a minimum spanning tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 1000
#define INFINITY 999999

typedef struct {
    int u;//start point
    int v;//end point
    int w;//weight
} Edge;//define a edge

typedef struct {
    int n, e;//n is the number of vertexes,e is the number of edges
    Edge edges[MAX];//define a edge array
} Graph;//define a graph

int parent[MAX];//define a parent array

int Find(int x) //find the root of the tree
{
    if (parent[x] != x) {//if the parent of x is not x
        parent[x] = Find(parent[x]);    //path compression
    }
    return parent[x];   //return the root of the tree
}

void Union(int x, int y) {//union two trees
    int xRoot = Find(x);//find the root of the tree
    int yRoot = Find(y);//find the root of the tree
    if (xRoot != yRoot) {//if the root of the tree is not the same
        parent[xRoot] = yRoot;      //union two trees
    }
}

void Kruskal(Graph *g) {
    int i, j, e, n;//define some variables
    int u, v, w;//define some variables
    int sum = 0;//define a variable to store the sum of the weight
    Edge t;//define a edge
    n = g->n;//get the number of vertexes
    e = g->e;//get the number of edges
    for (i = 1; i <= n; i++) {//initialize the parent array
        parent[i] = i;//set the parent of each vertex to itself
    }//end for  
    for (i = 0; i < e; i++) {   //sort the edges by weight
        for (j = i + 1; j < e; j++) {   //sort the edges by weight
            if (g->edges[i].w > g->edges[j].w) {    //sort the edges by weight
                t = g->edges[i];    
                g->edges[i] = g->edges[j];
                g->edges[j] = t;
            }
        }
    }
    for (i = 0; i < e; i++) {   //get the minimum spanning tree
        u = g->edges[i].u;  //get the start point of the edge
        v = g->edges[i].v;  //get the end point of the edge
        w = g->edges[i].w;  //get the weight of the edge
        if (Find(u) != Find(v)) {   //if the start point and the end point are not in the same tree
            Union(u, v);    //union two trees
            sum += w;   //add the weight to the sum
        }
    }
    printf("%d", sum);  //print the sum of the weight
}

int main() {    
    int i, j, k, n, m;  //define some variables
    Graph *g;   //define a graph
    g = (Graph *) malloc(sizeof(Graph));    //allocate memory for the graph
    scanf("%d %d", &n, &m); //get the number of vertexes and the number of edges
    g->n = n;   //set the number of vertexes
    g->e = m;   //set the number of edges
    for (i = 0; i < m; i++) {   //get the edges
        scanf("%d %d %d", &g->edges[i].u, &g->edges[i].v, &g->edges[i].w);  //get the edges
    }   //end for
    Kruskal(g); //get the minimum spanning tree
    return 0;   
}
