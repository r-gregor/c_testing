/*
 * from How To Implement a Graph in C. (adjacency matrix version)
 * Jacob Sorber: Data Structures
 * https://www.youtube.com/watch?v=nvRkFi8rbOM
 */

#include <stdio.h>
#include <string.h>
#include "graph_adj_mat.h"


int main(int argc, char **argv) {

	graph *g1 = create_graph(5);

	add_edge(g1, 0 ,1);
	add_edge(g1, 0 ,2);
	add_edge(g1, 0 ,0);
	add_edge(g1, 1 ,2);
	add_edge(g1, 1 ,3);
	add_edge(g1, 3 ,4);
	add_edge(g1, 4 ,1);
	add_edge(g1, 4 ,0);

	print_graph(g1);
	destroy_graph(g1);

	return 0;
}

