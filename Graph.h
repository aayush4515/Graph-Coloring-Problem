#pragma once

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Graph {

public:

    // default constructor
    Graph() {
        solutionFound = false;
    }

    // interface to read in the graph data into an adjacent matrix from an input file name
    /*
    void read(ifstream &infile) {
        char ignore;
        int first = 0;
        int second = 0;

        infile >> this->numColors;
        infile >> this->numVertices;

        // initialize the bool matrix and color array
        adjMatrix = vector<vector<bool>>(numVertices, vector<bool>(numVertices, false));
        vcolor = vector<int>(numVertices, -1);

        infile >> ignore >> first >> second >> ignore;      // priming read
        // if edge found between two vertice i and j, set adjMatrix[i][j] and adjMatrix[j][i] to true
        while (first != -1)
        {
            adjMatrix[first][second] = true;
            adjMatrix[second][first] = true;
            infile >> ignore >> first >> second >> ignore;
        }
    }
    */

    // reading from the standard input, through file redirection

    void read()
    {
        char ignore;
        int first = 0;
        int second = 0;

        cin >> this->numColors;
        cin >> this->numVertices;

        // initialize the bool matrix and color array
        adjMatrix = vector<vector <bool> >(numVertices, vector<bool>(numVertices, false));
        vcolor = vector<int>(numVertices, -1);

        cin >> ignore >> first >> second >> ignore; // priming read
        // if edge found between two vertice i and j, set adjMatrix[i][j] and adjMatrix[j][i] to true
        if (first == -1) {
            cout << "Not a graph" << endl;
            return;
        }

        while (first != -1) {
            adjMatrix[first][second] = true;
            adjMatrix[second][first] = true;
            cin >> ignore >> first >> second >> ignore;
        }
    }

    // prints the color assignment for one solution
    void print() {
        if (solutionFound) {
            for (unsigned int i = 0; i < numVertices; i++) {
                cout << i << " : " << vcolor[i] << endl;
            }
        }
    }

    void mColoring(int currVertex) {

        // if a solution is found, exit the function
        if (solutionFound) {
            return;
        }

        // base case: all vertices are checked
        if (currVertex == numVertices) {
            solutionFound = true;
            print();
            return;
        }
        // recursive case: checking intermediate vertices and assigning colors
        for (int color = 1; color <= numColors && !solutionFound; color++) {
            if(promising(currVertex, color)) {
                vcolor[currVertex] = color;
                mColoring(currVertex + 1);
                //vcolor[currVertex] = -1;
            }
        }
        // If back at the start and no solution found, print the failure message
        if (currVertex == 0 && !solutionFound) {
            cout << "No color assignment possible." << endl;
        }
    }

    bool promising(int currVertex, int color) {
        for (int i = 0; i < currVertex; i++) {
            if (adjMatrix[currVertex][i] && vcolor[i] == color) {
                return false; // Either no edge or the adjacent vertices have the same color
            }
        }
        return true;
    }

private:
    int numVertices;
    int numColors;
    vector< vector<bool> > adjMatrix;
    vector<int> vcolor;
    bool solutionFound;
};