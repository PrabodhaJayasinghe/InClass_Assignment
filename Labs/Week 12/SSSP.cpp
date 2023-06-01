#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstras(vector<vector<int>> &graph, int source, vector<int> &time)
{
    int numCities = graph.size();
    time.resize(numCities, INT_MAX); // Initialize time from source to all other cities as infinity
    time[source] = 0;                  // Time from source to itself is zero

    // Create a min-heap priority queue to store cities and their time
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQ;
    priorityQ.push(make_pair(0, source)); // Push source city into the priority queue

    while (!priorityQ.empty())
    {
        int currentCity = priorityQ.top().second; // Get the city with the minimum time from priority queue
        priorityQ.pop();  //remove the top element

        // Visit all unvisited neighboring cities of the current city
        for (int neighbor = 0; neighbor < numCities; neighbor++)
        {
            //check  if there is an edge between the current city and the neighbor city
            if (graph[currentCity][neighbor] > 0)
            {
                int weight = graph[currentCity][neighbor]; // Weight of the edge between current city and neighbor city

                // If the time taken to the neighbor through the current city is shorter, update the time
                if (time[currentCity] + weight < time[neighbor])
                {
                    time[neighbor] = time[currentCity] + weight;
                    priorityQ.push(make_pair(time[neighbor], neighbor)); // Push updated time and city into the priority queue
                }
            }
        }
    }
}

int main()
{
    // Define the adjacency matrix for the graph
    vector<vector<int>> adjacencyMatrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};

    int numCities = adjacencyMatrix.size(); // Number of vertices/cities

    int source; // Source vertex/city
    cout << "Source city: ";
    cin >> source;

    vector<int> time; // Vector to store the shortest time
    dijkstras(adjacencyMatrix, source, time);
    int i = 0;
    while (i < numCities)
    {
        if (i == source)
        {
            i++;
            continue;
        }
        else
        {
            cout << "Shortest time taken to travel from " << source << " to " << i << " is " << time[i] << endl;
        }
        i++;
    }

    return 0;
}