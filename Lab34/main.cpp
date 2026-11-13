// ANthony Huey - 11/12/1996 , my birthday :), COMSC 210 - Lab 34: Graphs
//
#include <iostream>
#include <vector>
#include <queue> // for the BFS
#include <stack> // For the DFS
#include <string>
using namespace std;

const int SIZE = 9, BIG = 1000000;

// names for the nodes/"intersections"
const string NAMES[SIZE] = 
{
    "Central Station",      // 0
    "City Hall",            // 1
    "Market Square",        // 2
    "Harbor Gate",          // 3
    "University Ave",       // 4
    "Stadium Junction",     // 5
    "Highway Interchange",  // 6
    "Airport Terminal",     // 7
    "Industrial Park",      // 8
};

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges) {
        // resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);

        // add edges to the directed graph
        for (auto &edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            // for an undirected graph, add an edge from dest to src also
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Print the graph's adjacency list
    void printGraph() {
        cout << "City Traffic Network Topology:" << endl;
        cout << "==============================" << endl;
        for (int i = 0; i < adjList.size(); i++) 
        {
            cout << "Intersection " << i << " (" << NAMES[i] 
                                                 << ") connects to:" << endl;
            for (Pair v : adjList[i])
                cout << "-> Intersection " << v.first << " (" << NAMES[v.first] 
                     << ") - Travel time: " << v.second << " min" << endl;
            cout << endl;
        }
    }

    // BFS & DFS
    void DFS(int start) // Depth First Search
        {
            vector<bool> visited(SIZE, false); // flags each node as false
            stack<int> s; // hold value to be explored.
            s.push(start); // start at this node

            cout << "Route Trace (DFS) from Intersection " << start 
                 << " (" << NAMES[start] << "):" << endl;
            cout << "Purpose: Following one route as far as it goes to plan detours"
                 << endl;
            cout << "=============================================================="
                 << endl;

            while(!s.empty()) // go until nothing left
            {
                int node = s.top(); // gets the top of the stack
                s.pop(); // delete its

                if(visited[node]) continue; // skip if we've already visited
                visited[node] = true; // mark this node as visited

                cout << "Inspecting Intersection " << node << " (" 
                     << NAMES[node] << ")" << endl; 


                for (Pair neighbor : adjList[node]) // cehck all the neighbors
                    if (!visited[neighbor.first]) // push unvisited neighbors
                    {
                        cout << " -> Possible route to Intersection " << neighbor.first 
                             << " (" << NAMES[neighbor.first] << ") - Travel time: " 
                             << neighbor.second << "min" << endl;
                        s.push(neighbor.first);
                    }
            }
            cout << endl;    
        }

    void BFS(int start) // Breadth First Search
    {
        vector<bool> visited(SIZE, false); // flags each node as false 
        queue<int> q; // holds value to be explored

        visited[start] = true; // input & mark the starting node
        q.push(start);

        cout << "Layer-by-Layer Dispatch Review (BFS) from Intersection " 
             << start << " (" << NAMES[start] << "):" << endl;
        cout << "Purpose: Finding which intersection emergency crews reach first"
             << endl;
        cout << "==============================================================="
             << endl;
        while (!q.empty()) // go until empty
        {
            int node = q.front(); // read the front of the queue
            q.pop(); // delete it

            cout << "Checking intersection " << node << " (" << NAMES[node] << ")" 
                 << endl; 

            for (Pair neighbor : adjList[node]) // cehck neighbors
                if (!visited[neighbor.first]) // if we haven't visited them
                {
                    visited[neighbor.first] = true; // mark them and push.
                    q.push(neighbor.first);
                    cout << " -> Next respose zone: Intersection " << neighbor.first
                         <<" (" << NAMES[neighbor.first] << ") - Travel time: "
                         << neighbor.second << " min" << endl;
                }
        }
        cout << endl;
    }
    // they're both basically identical, just one uses a stack and the other a 
    // queue, and when they mark that they've "visited" a node.

    void shortestPath(int start) // Dijkstra' algo,
    {
        vector<int> dist(SIZE, BIG); // stores the best travel time, starts big  
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        // P_Q give s back the "best" item, greater<pair> flips the order so 
        // we get the smallest
        dist[start] = 0;
        pq.push(make_pair(0, start)); // starting here,

        while (!pq.empty()) // until empty, check nodes, pop them, compare.
        {
            int d = pq.top().first;        
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node]) continue;  

            for (Pair neighbor : adjList[node]) 
            {
                int next = neighbor.first;
                int w = neighbor.second;
                if (dist[node] + w < dist[next]) // is this faster than what we know?
                {
                    dist[next] = dist[node] + w;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }

        cout << "Shortest travel time from Intersection " << start
             << " (" << NAMES[start] << "):" << endl;
        for (int i = 0; i < SIZE; i++)
            cout << start << " -> " << i << " : " << dist[i]
                 << " min  (" << NAMES[i] << ")" << endl;
        cout << endl;
    }
};

int main() {
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,3},{0,2,7},{0,3,25},{1,2,4},{1,4,6},{2,3,9},{2,4,1},{4,5,5},
        {5,6,50},{6,7,3},{6,8,2}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

    graph.DFS(0);
    graph.BFS(0);
    cout << endl;
    graph.shortestPath(0);

    return 0;
}
