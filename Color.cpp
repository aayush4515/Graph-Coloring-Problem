#include "Graph.h"

int main() {

    // create the graph object
    Graph graph;

    // read the .txt file to insert to the Graph object
    string filename = "";
    cout << "Enter filename: ";
    cin >> filename;
    ifstream file(filename);

    // check if the file can't be opened
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return 1;     // return an error code
    }

    // reads the file content once open
    graph.read(file);
    file.close();

    // color the graph
    graph.mColoring(0);

    return 0;
}