#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Public test 5 (public05.c)
 *
 * Tests calling get_graph_edge_weight() on some edges that have been added
 * to a graph.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertex_names[]= {"hedgehog", "koala", "panda", "kangaroo",
                         "parrot", "giraffe"};
  int i;

  graph_init(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertex_names); i++)
    add_vertex_to_graph(&graph, vertex_names[i]);

  /* add some edges between them */
  create_graph_edge(&graph, "hedgehog", "kangaroo", 8);
  create_graph_edge(&graph, "koala", "parrot", 2);
  create_graph_edge(&graph, "giraffe", "panda", 6);
  create_graph_edge(&graph, "koala", "giraffe", 10);
  create_graph_edge(&graph, "hedgehog", "parrot", 1);
  create_graph_edge(&graph, "panda", "koala", 7);
  create_graph_edge(&graph, "hedgehog", "hedgehog", 9);

  /* test some of the edge weights */
  assert(get_graph_edge_weight(&graph, "hedgehog", "kangaroo") == 8);
  assert(get_graph_edge_weight(&graph, "giraffe", "panda") == 6);
  assert(get_graph_edge_weight(&graph, "panda", "koala") == 7);
  assert(get_graph_edge_weight(&graph, "hedgehog", "hedgehog") == 9);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
