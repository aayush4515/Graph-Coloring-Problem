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
        this->numColors = numColors;

        adjMatrix = vector<vector<bool>>(numVertices, vector<bool>(numVertices, false));
        vcolor = vector<int>(numVertices, 0);
        vcolor[0] = 1;

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


    void mColoring(int i) {
        if (promising(i)) {
            if (i + 1 == numVertices) {
                print();
            }
            else {
                for (int color = 1; color <= numColors; color++) {
                    vcolor[i + 1] = color;
                    mColoring(i + 1);
                }
            }
        }
    }

    bool promising(int i) {
        int j = 1;
        bool check;
        check = true;

        while(j < i && check) {
            if (adjMatrix[i][j] && vcolor[i] == vcolor[j]) {
                check = false;
            }
            j++;
        }
        return check;
    }


private:
    int numVertices;
    int numColors;
    vector<vector<bool>> adjMatrix;
    vector<int> vcolor;
};