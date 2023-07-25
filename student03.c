#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

int main() {
  String_graph graph;

  graph_init(&graph);

  assert(create_graph_edge(&graph, "v1", "v2", 3) == 1);
  assert(get_graph_edge_weight(&graph, "v1", "v2") == 3);
  assert(get_graph_edge_weight(&graph, "v2", "v1") == -1); /* doesn't exist */
  assert(get_graph_edge_weight(&graph, "v2", NULL) == -1); /* NULL param */
  assert(create_graph_edge(&graph, "v1", "v2", 5) == 1);
  assert(get_graph_edge_weight(&graph, "v1", "v2") == 5); /* Updated to 5 */
  
  printf("Pass\n");

  return 0;
}
