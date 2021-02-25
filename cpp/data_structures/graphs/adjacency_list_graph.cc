#include "adjacency_list_graph.h"

int main() {
  std::cout << "TEST ADJACENCY LIST GRAPH\n" << std::endl;
  data_structures::graphs::AdjacencyListGraph<int> graph;
  std::cout << "Empty: " << graph.IsEmpty() << std::endl;
  std::cout << "Size: " << graph.Size() << std::endl;
  std::cout << "Insert edge 2 -> 0" << std::endl;
  graph.InsertEdge(2, 0);
  std::cout << "Insert edge 0 -> 2" << std::endl;
  graph.InsertEdge(0, 2);
  std::cout << "Insert edge 2 -> 3" << std::endl;
  graph.InsertEdge(2, 3);
  std::cout << "Insert edge 0 -> 1" << std::endl;
  graph.InsertEdge(0, 1);
  std::cout << "Insert edge 1 -> 2" << std::endl;
  graph.InsertEdge(1, 2);
  std::cout << "Insert edge 3 -> 3" << std::endl;
  graph.InsertEdge(3, 3);
  std::cout << graph << std::endl;
  std::cout << "Empty: " << graph.IsEmpty() << std::endl;
  std::cout << "Size: " << graph.Size() << std::endl;
  std::cout << "Remove edge 0 -> 2: " << graph.RemoveEdge(0, 2) << std::endl;
  std::cout << "Remove edge 2 -> 0: " << graph.RemoveEdge(2, 0) << std::endl;
  std::cout << "Remove edge 0 -> 1: " << graph.RemoveEdge(0, 1) << std::endl;
  std::cout << "Size: " << graph.Size() << std::endl;
  std::cout << graph << std::endl;

  return 0;
}
