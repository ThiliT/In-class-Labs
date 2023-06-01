#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Function to get path
void printPath(const vector<int>& prevVertex, int source, int destination){
    if (destination == source) {
        cout << source;
        return;
    }

    printPath(prevVertex, source, prevVertex[destination]);
    cout << " -> " << destination;
}

int dijkstra(const vector<vector<int>>& graph, int numCities, int source, int destination) {

    vector<int> timeTaken(numCities, INT_MAX);     // Stores the current shortest time from the source
    vector<bool> visited(numCities, false); //Visited vertices
    vector<int> prevVertex(numCities, -1);

    // Initialized time taken from source to itself is 0
    timeTaken[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < numCities - 1; ++count) {
        int u = -1;

        // Find the vertex with the minimum time 
        for (int v = 0; v < numCities; ++v) {
            if (!visited[v] && (u == -1 || timeTaken[v] < timeTaken[u]))
                u = v;
        }

        // Mark the vertex with min time as visited
        visited[u] = true;

        // Update the min time 
        for (int v = 0; v < numCities; ++v) {
            if (!visited[v] && graph[u][v] != 0 && 
                timeTaken[u] != INT_MAX &&
                timeTaken[u] + graph[u][v] < timeTaken[v]) {

                timeTaken[v] = timeTaken[u] + graph[u][v];
                prevVertex[v] = u;
            }
        }
    }   

    // Print the shortest path
    cout << "Path = " ;
    printPath(prevVertex, source, destination);
    cout << endl;     

    return timeTaken[destination];
}

int main() {
    int numCities = 6;

    vector<vector<int>> graph = {{0, 10, 0, 0, 15, 5},
                                {10, 0, 10, 30, 0, 0},
                                {0, 10, 0, 12, 5, 0},
                                {0, 30, 12, 0, 0, 20},
                                {15, 0, 5, 0, 0, 0},
                                {5, 0, 0, 20, 0, 0}
    }; 

    int source = 5;
    //Print shortest time taken to each city from source
    cout << "From City " << source << ":" << endl;

    for (int destination = 0; destination < numCities; destination++) {
            if(source == destination) continue;

            int shortestTime = dijkstra(graph, numCities, source, destination);

            cout << "Shortest time to City" << destination << " = " << shortestTime << endl;
    }      

    return 0;
}