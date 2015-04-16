//
//  main.cpp
//  FloydWarshall
//
//  Created by Michelle Emamdie on 4/15/15.
//  Copyright (c) 2015 Michelle Emamdie. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int nodes, edges, queries, x, y, cost;
    cout << "How many nodes would you like to create?" << endl;
    cin >> nodes;
    vector<vector<int>> graph(nodes, vector<int>(nodes));
    cout << "How many edges would you like to create?" << endl;
    cin >> edges;
    cout << "How many queries would you like to create?" << endl;
    cin >> queries;
    //Set values on the diagonal equal to zero because it does not cost you anything to travel to yourself
    for(int i = 0; i < nodes; i++) {
        graph[i][i] = 0;
    }
    int count = 0;
    //Set the costs at the right position
    while(count < edges) {
        cin >> x >> y >> cost;
        graph[x][y] = cost;
        count++;
    }
    //Print out the graph to make sure it is entered correctly
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    //Now we can start to check out what queries the user has
    for(int i = 0; i < queries; i++) {
        
    }
    return 0;
}
