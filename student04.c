#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "string-graph.h"

int main() {
  String_graph graph;
  char **verticies;
  char *current = NULL;
  int index = 0;
  char *ordered[] = {"A", "B", "C", "D", "E", "F", "G", NULL};

  graph_init(&graph);

  /* Empty graph */
  verticies = get_vertex_list(&graph);
  assert(verticies[0] == NULL);

  /* Add verticies */
  assert(add_vertex_to_graph(&graph, "B") == 1);
  assert(add_vertex_to_graph(&graph, "G") == 1);
  assert(add_vertex_to_graph(&graph, "F") == 1);
  assert(add_vertex_to_graph(&graph, "C") == 1);
  assert(add_vertex_to_graph(&graph, "D") == 1);
  assert(add_vertex_to_graph(&graph, "A") == 1);
  assert(add_vertex_to_graph(&graph, "E") == 1);

  /* Full graph */
  verticies = get_vertex_list(&graph);
  current = verticies[0];
  while (current != NULL) {
    assert(strcmp(current, ordered[index]) == 0);
    current = verticies[++index];
  }

  printf("Pass\n");

  return 0;
}