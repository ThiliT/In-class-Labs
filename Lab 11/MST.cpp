#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

// Number of vertices
const int V = 6;

//Find vertex, has minimum key
int minKey(int key[], bool mstSet[]){
    // Initialize minimum value
    int min = INT_MAX;
    int minIndex;

    for (int i= 0; i<V; i++){
        if ((mstSet[i]==false) && (key[i]<min)){
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

//Print the MST
int printMST(int source[], int n, int graph[V][V]){

    for (int i=1; i<V; i++){
        cout<< "Edge: " << source[i] << " - " << i<<"   "<<"Weight: "<< graph[i][source[i]]<<endl;
    }
    
    return 1;

}

//Construct MST for the given graph
void primMST(int graph[V][V]){
    int source[V];

    int key[V];

    bool mstSet[V];

    // Initialize all keys as infinite except source vertex
    for (int i=0; i<V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;

    source[0] = -1;

    for (int count=0; count<V-1; count++){
        int u = minKey(key, mstSet);

        // Add min key vertex to MST set
        mstSet[u] = true;

        for (int i=0; i<V; i++){
            if (graph[u][i] && mstSet[i]==false && graph[u][i] < key[i] ) {
                source[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    printMST(source, V, graph);
}


int main(){
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                       {3, 0, 2, 1, 10, 0},
                       {0, 2, 0, 3, 0, 5},
                       {0, 1, 3, 0, 5, 0},
                       {0, 10, 0, 5, 0, 4},
                       {1, 0, 5, 0, 4, 0}};


    primMST(graph);

    return 0;
}