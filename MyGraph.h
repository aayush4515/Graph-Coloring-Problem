#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class MyGraph {
private:
    size_t verticesCount;
    size_t colorsCount;
    vector<vector<bool>> adjacencyMatrix;
    bool isValidGraph;

public:
    MyGraph(int vertices = 0, int colors = 0)
        : verticesCount(vertices),
        colorsCount(colors),
        adjacencyMatrix(vertices, vector<bool>(vertices, false)),
        isValidGraph(false) {}

    size_t getColorCount() const {
        return colorsCount;
    }

    size_t getVertexCount() const {
        return verticesCount;
    }

    bool isValidGraphCheck() const {
        return isValidGraph;
    }

    const vector<vector<bool>>& getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    void readGraph(ifstream& file) {
        string line;
        if (!getline(file, line)) {
            cerr << "Failed to read from the file" << endl;
            return;
        }

        istringstream iss(line);
        int m, n;

        cout << line << endl << endl;

        if (!(iss >> m >> n)) {
            cerr << "Error reading initial values" << endl;
            return;
        }

        verticesCount = n;
        colorsCount = m;
        adjacencyMatrix.resize(verticesCount, vector<bool>(verticesCount, false));

        char ch;
        int vi, vj;
        while (iss >> ch >> vi >> vj && vi != -1 && vj != -1) {
            if (ch != '(') {
                cerr << "Error reading an edge: Expected '(' but found '" << ch << "'" << endl;
                return;
            }

            if (!(iss >> ch) || ch != ')') {
                cerr << "Error reading an edge: Expected ')' but found '" << ch << "'" << endl;
                return;
            }

            if (vi < 0 || vi >= n || vj < 0 || vj >= n) {
                cerr << "Error reading an edge: Vertex index out of range" << endl;
                return;
            }

            adjacencyMatrix[vi][vj] = true;
            adjacencyMatrix[vj][vi] = true;
        }

        cout << "Terminating read on encountering (-1, -1)" << endl;
        isValidGraph = true;
    }

    void printGraph() const {
        if (!isValidGraph) {
            cerr << "Invalid graph data. Cannot print adjacency matrix." << endl;
            return;
        }

        cout << "Adjacency Matrix:" << endl;
        for (size_t i = 0; i < verticesCount; ++i) {
            for (size_t j = 0; j < verticesCount; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

