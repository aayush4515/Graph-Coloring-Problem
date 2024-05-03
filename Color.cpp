#include "Graph.h"

// receiving inputs from file redirection
// NOTE: whether the filename provided at command line exists is checked
// by the in-built zshell, so no such implementation is done here

int main() {

    // create a graph object
    Graph graph;

    // read the input
    graph.read();

    // terminate program if the graph is empty
    if (!graph.isGraphValid()) {
        return 1;
    }

    // color the graph
    graph.mColoring(0);

    return 0;
}