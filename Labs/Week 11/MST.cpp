#include <iostream>
#include <vector>


using namespace std;

void primMST(vector<vector<int>>& graph, int startVertex) {
    int V = graph.size();
    vector<int> parent(V, -1);      // Stores the parent of each vertex in the MST
    vector<int> key(V, INT_MAX);   // Stores the minimum weight edge
    vector<bool> mstSet(V, false);  // To know vertices included in the MST or not

    key[0] = startVertex; // Start vertex value is 3
    parent[0] = -1; // Parent of start vertex is -1

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        // Select the vertex with the minimum key value from the set of vertices not yet included in MST
        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        mstSet[u] = true;

        // Update key values and parent index of the adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << "Edge     Weight"<<endl;
    int MSTCost=0;
    // Print the edges and weights in the MST
    
    for (int i = 1; i < V; i++){
        int weight=graph[i][parent[i]];
        cout << parent[i] << " - " << i << "   :   "<< weight<< endl;
        MSTCost+=weight;
    }
    //Print total cost
    cout<<"The cost of the minimum spanning tree : "<<MSTCost;

}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    primMST(graph, startVertex);

    return 0;
} 