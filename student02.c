#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

int main() {
  String_graph graph;

  graph_init(&graph);

  /* Add a good edge, test count */
  assert(create_graph_edge(&graph, "one", "two", 1) == 1);
  assert(vertex_count(&graph) == 2); /* one, two */
  assert(create_graph_edge(&graph, "one", "two", 1) == 1);
  assert(vertex_count(&graph) == 2); /* same as before */
  assert(create_graph_edge(&graph, "two", "one", 1) == 1);
  assert(vertex_count(&graph) == 2); /* same as before */
  assert(create_graph_edge(&graph, "one", "one", 1) == 1);
  assert(create_graph_edge(&graph, "two", "two", 1) == 1);

  printf("Pass\n");

  return 0;
}