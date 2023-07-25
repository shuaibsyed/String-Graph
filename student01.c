#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

int main() {
  String_graph graph;

  graph_init(&graph);

  /* Test invalid verticies */
  assert(add_vertex_to_graph(NULL, "NULL") == 0);
  assert(add_vertex_to_graph(NULL, NULL) == 0);
  assert(add_vertex_to_graph(&graph, NULL) == 0);

  /* Check size */
  assert(vertex_count(&graph) == 0);
  assert(vertex_count(NULL) == 0);

  /* Add bad edges */
  assert(create_graph_edge(&graph, "one", "two", -1) == 0);
  assert(vertex_count(&graph) == 0);
  assert(create_graph_edge(&graph, NULL, "two", 6) == 0);
  assert(vertex_count(&graph) == 0);
  assert(create_graph_edge(&graph, "one", NULL, 9) == 0);
  assert(vertex_count(&graph) == 0);
  assert(create_graph_edge(&graph, NULL, NULL, 4) == 0);
  assert(vertex_count(&graph) == 0);

  /* Add a good edge, test count */
  assert(create_graph_edge(&graph, "one", "two", 1) == 1);
  assert(vertex_count(&graph) == 2); /* one, two */

  printf("Pass\n");

  return 0;
}