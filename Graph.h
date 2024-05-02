#pragma once

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Graph {

public:

    void read(ifstream &infile) {
        int numColors = 0;
        int numV = 0;

        char ignore;
        int first = 0;
        int second = 0;

        infile >> numColors;
        infile >> numV;
        this->numVertices = numV;

        adjMatrix = vector<vector<bool>>(numVertices, vector<bool>(numVertices, false));

        infile >> ignore >> first >> second >> ignore;
        while (first != -1)
        {
            adjMatrix[first][second] = true;
            adjMatrix[second][first] = true;
            infile >> ignore >> first >> second >> ignore;
        }
    }

    void print() {
        for (unsigned int i = 0; i < adjMatrix.size(); i++)
        {
            for (unsigned int j = 0; j < adjMatrix.size(); j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }


private:

    int numVertices;
    vector<vector<bool>> adjMatrix;
};