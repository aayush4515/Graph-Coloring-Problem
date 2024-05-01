#include <iostream>
#include <fstream>
#include <string>
#include "MyGraph.h"
#include "MyGraphColoring.h"

using namespace std;

int main() {
    string inputFilename;
    cout << "Enter the filename containing graph data: ";
    cin >> inputFilename;
    cout << "\n";

    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Error opening file: " << inputFilename << endl;
        return 1;
    }

    MyGraph myGraph;
    cout << "Contents of " << inputFilename << ": ";
    myGraph.readGraph(inputFile);
    inputFile.close();

    if (!myGraph.isValidGraphCheck()) {
        cerr << "Invalid graph data. Cannot proceed." << endl;
        return 1;
    }

    cout << "Number of Colors: " << myGraph.getColorCount() << endl;
    cout << "Number of Vertices: " << myGraph.getVertexCount() << endl << endl;
    myGraph.printGraph();

    MyGraphColoring myGraphColoring(myGraph);

    if (!myGraphColoring.performGraphColoring(myGraph.getColorCount())) {
        cerr << "Failed to perform graph coloring." << endl;
        return 1;
    }

    return 0;
}
