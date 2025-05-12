#include <iostream>
#include <list>
#include <map>
#include <queue>

using namespace std;
template <typename T>

class Graph {
  map<T, list<T>> adjList;

public:
  Graph() {}
  void addEdge(T u, T v, bool bidirectional = true) {
    adjList[u].push_back(v);
    if (bidirectional) {
      adjList[v].push_back(u);
    }
  }
  void printAdjList() {
    for (auto key : adjList) {
      cout << key.first << "->";
      for (auto neighbours : key.second) {
        cout << neighbours << ",";
        cout << endl;
      }
    }
  }
  void bfs(T src) {
    queue<T> q;
    map<T, bool> visited;

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
      T node = q.front();
      cout << node << " ,";
      q.pop();

      for (auto neighbours : adjList[node]) {
        if (!visited[neighbours]) {
          q.push(neighbours);
          visited[neighbours] = true;
        }
      }
    }
  }
};

int main() {
  Graph<int> graph;
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(0, 4);
  graph.addEdge(2, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 5);
  graph.addEdge(3, 4);

  cout << "Graph: " << endl;
  graph.printAdjList();

  cout << "BFS from Node 0: " << endl;

  graph.bfs(0);
}
