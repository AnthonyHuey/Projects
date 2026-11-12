// ANthony Huey - 11/12/1996 , my birthday :), COMSC 210 - Lab 34: Graphs
//
#include <iostream>
#include <vector>
#include <queue> // for the BFS
#include <stack> // For the DFS
using namespace std;

const int SIZE = 9;

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
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }

    // BFS & DFS
    void DFS(int start) // Depth First Search
        {
            vector<bool> visited(SIZE, false); // flags each node as false
            stack<int> s; // hold value to be explored.
            s.push(start); // start at this node

            cout << "DFS starting from vertex " << start << ":" << endl;
            while(!s.empty()) // go until nothing left
            {
                int node = s.top(); // gets the top of the stack
                s.pop(); // delete its

                if(visited[node]) continue; // skip if we've already visited
                visited[node] = true; // mark this node as visited
                cout << node << " "; // print it

                for (Pair neighbor : adjList[node]) // cehck all the neighbors
                    if (!visited[neighbor.first]) // push unvisited neighbors
                        s.push(neighbor.first);
            }
            cout << endl;    
        }

    void BFS(int start) // Breadth First Search
    {
        vector<bool> visited(SIZE, false); // flags each node as false 
        queue<int> q; // holds value to be explored

        visited[start] = true; // input & mark the starting node
        q.push(start);

        cout << "BFS starting from vertex " << start << ":" << endl;
        while (!q.empty()) // go until empty
        {
            int node = q.front(); // read the front of the queue
            q.pop(); // delete it
            cout << node << " "; // print it

            for (Pair neighbor : adjList[node]) // cehck neighbors
                if (!visited[neighbor.first]) // if we haven't visited them
                {
                    visited[neighbor.first] = true; // mark them and push.
                    q.push(neighbor.first);
                }
        }
        cout << endl;
    }
    // they're both basically identical, just one uses a stack and the other a 
    // queue, and when they mark that they've "visited" a node.
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

    return 0;
}
