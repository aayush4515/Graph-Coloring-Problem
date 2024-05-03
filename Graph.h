#pragma once

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Graph {

public:

    Graph() {
        solutionFound = false;
    }

    void read(ifstream &infile) {
        int numColors = 0;
        int numV = 0;

        char ignore;
        int first = 0;
        int second = 0;

        infile >> numColors;
        infile >> numV;
        this->numVertices = numV;
        this->numColors = numColors;

        adjMatrix = vector<vector<bool>>(numVertices, vector<bool>(numVertices, false));
        vcolor = vector<int>(numVertices, -1);

        infile >> ignore >> first >> second >> ignore;
        while (first != -1)
        {
            adjMatrix[first][second] = true;
            adjMatrix[second][first] = true;
            infile >> ignore >> first >> second >> ignore;
        }
    }

    void print() {
        for (unsigned int i = 0; i < numVertices; i++) {
            cout << i << " : " << vcolor[i] << endl;
        }
    }

    void mColoring(int currVertex) {

        if (solutionFound) {
            return;
        }

        if (currVertex == numVertices) {
            solutionFound = true;
            print();
            return;
        }
        for (int color = 1; color <= numColors && !solutionFound; color++) {
            if(promising(currVertex, color)) {
                vcolor[currVertex] = color;
                mColoring(currVertex + 1);
                //vcolor[currVertex] = -1;
            }
        }
    }

    bool promising(int currVertex, int color) {
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currVertex][i] && vcolor[i] == color) {
                return false; // Adjacent vertex has the same color
            }
        }
        return true;
    }


private:
    int numVertices;
    int numColors;
    vector<vector<bool>> adjMatrix;
    vector<int> vcolor;
    bool solutionFound;
};