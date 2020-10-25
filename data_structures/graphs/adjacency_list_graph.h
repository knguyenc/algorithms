#ifndef ALGORITHMS_DATA_STRUCTURES_ADJACENCY_LIST_GRAPH_H_
#define ALGORITHMS_DATA_STRUCTURES_ADJACENCY_LIST_GRAPH_H_

#include <algorithm>
#include <iostream>
#include <vector>

namespace data_structures {
namespace graphs {

template <class T>
class AdjacencyListGraph {
 public:
  class Vertex {
   protected:
    std::vector<Vertex *> adjacent_vertices_;

   public:
    T data_;
    friend class AdjacencyListGraph;
    explicit Vertex(const T &data) : data_(data) {}

   protected:
    void InsertAdjacentVertex(Vertex *dst) {
      for (Vertex *v : adjacent_vertices_)
        if (v->data_ == dst->data_) throw std::runtime_error("The edge is already exist");
      adjacent_vertices_.push_back(dst);
    }

    T RemoveAdjacentVertex(T dst_data) {
      for (unsigned long i = 0; i < adjacent_vertices_.size(); i++) {
        if (adjacent_vertices_[i]->data_ == dst_data) {
          adjacent_vertices_.erase(adjacent_vertices_.begin() + i);
          return dst_data;
        }
      }
      throw std::runtime_error("The edge is not exist");
    }
  };

 public:
  AdjacencyListGraph();
  ~AdjacencyListGraph();
  int Size() const;
  bool IsEmpty() const;
  void InsertEdge(const T &src, const T &dst);
  T RemoveEdge(const T &src, const T &dst);

  friend std::ostream &operator<<(std::ostream &out, const AdjacencyListGraph &graph) {
    if (graph.IsEmpty())
      out << "Empty graph";
    else {
      out << "Breadth first traversal: ";
      graph.BreadthFirst(out);
      out << std::endl;

      out << "Depth first traversal: ";
      graph.DepthFirst(out);
    }
    return out;
  }

 protected:
  void BreadthFirst(std::ostream &out) const;
  void DepthFirst(std::ostream &out) const;
  void DepthFirstRecursive(std::ostream &out, Vertex *v, std::vector<T> &visited) const;

 private:
  std::vector<Vertex *> vertices_;
};

template <class T>
AdjacencyListGraph<T>::AdjacencyListGraph() {}

template <class T>
AdjacencyListGraph<T>::~AdjacencyListGraph() {
  for (unsigned long i = 0; i < vertices_.size(); i++)
    delete vertices_[i];
}

template <class T>
int AdjacencyListGraph<T>::Size() const {
  return vertices_.size();
}

template <class T>
bool AdjacencyListGraph<T>::IsEmpty() const {
  return Size() == 0;
}

template <class T>
void AdjacencyListGraph<T>::InsertEdge(const T &src, const T &dst) {
  Vertex *src_vertex = NULL, *dst_vertex = NULL;
  for (unsigned long i = 0; i < vertices_.size(); i++) {
    if (vertices_[i]->data_ == src)
      src_vertex = vertices_[i];
    if (vertices_[i]->data_ == dst)
      dst_vertex = vertices_[i];
    if (src_vertex != NULL && dst_vertex != NULL) break;
  }

  if (src_vertex == NULL) {
    src_vertex = new Vertex(src);
    vertices_.push_back(src_vertex);
  }
  if (dst_vertex == NULL) {
    dst_vertex = new Vertex(dst);
    vertices_.push_back(dst_vertex);
  }
  src_vertex->InsertAdjacentVertex(dst_vertex);
}

template <class T>
T AdjacencyListGraph<T>::RemoveEdge(const T &src, const T &dst) {
  for (unsigned long i = 0; i < vertices_.size(); i++)
    if (vertices_[i]->data_ == src) return vertices_[i]->RemoveAdjacentVertex(dst);
  throw std::runtime_error("The edge is not exist");
}

template <class T>
void AdjacencyListGraph<T>::BreadthFirst(std::ostream &out) const {
  std::vector<T> visited;
  for (Vertex *v : vertices_) {
    if (!(std::find(visited.begin(), visited.end(), v->data_) != visited.end())) {
      visited.push_back(v->data_);
      out << "Vertex(" << v->data_ << ") ";
    }
    for (Vertex *av : v->adjacent_vertices_) {
      if (!(std::find(visited.begin(), visited.end(), av->data_) != visited.end())) {
        visited.push_back(av->data_);
        out << "Vertex(" << av->data_ << ") ";
      }
    }
  }
}

template <class T>
void AdjacencyListGraph<T>::DepthFirstRecursive(std::ostream &out, Vertex *v, std::vector<T> &visited) const {
  if (!(std::find(visited.begin(), visited.end(), v->data_) != visited.end())) {
    visited.push_back(v->data_);
    out << "Vertex(" << v->data_ << ") ";
  }
  for (Vertex *av : v->adjacent_vertices_)
    if (!(std::find(visited.begin(), visited.end(), av->data_) != visited.end()))
      DepthFirstRecursive(out, av, visited);
}

template <class T>
void AdjacencyListGraph<T>::DepthFirst(std::ostream &out) const {
  if (IsEmpty()) return;
  std::vector<T> visited;
  for (unsigned long i = 0; i < vertices_.size(); i++)
    DepthFirstRecursive(out, vertices_[i], visited);
}

}  // namespace graphs
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_ADJACENCY_LIST_GRAPH_H_

