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

//int nodes, edges, queries, x, y, cost;
//vector<vector<int>> graph(nodes+1, vector<int>(nodes+1));

/*void print(){
	//Print out the graph to make sure it is entered correctly
	for (int i = 1; i < nodes; i++) {
		for (int j = 1; j < nodes; j++) {
			cout << graph[i][j] << "\t";
		}
		cout << endl;
	}
} */

int main(int argc, const char * argv[]) {
	int nodes, edges, queries, x, y, cost, start, end;
	cout << "How many nodes would you like to create?" << endl;
	cin >> nodes;
	nodes++;
	vector<vector<int>> graph(nodes + 1, vector<int>(nodes + 1));
	cout << "How many edges would you like to create?" << endl;
	cin >> edges;
	cout << "How many queries would you like to create?" << endl;
	cin >> queries;
	int count = 0;
	//Set the costs at the right position
	while (count < edges) {
		cin >> x >> y >> cost;
		graph[x][y] = cost;
		count++;
	}
	for (int i = 1; i < nodes; i++)	{
		for (int j = 1; j < nodes; j++) {
			if (graph[i][j] == 0 && i != j) {
				graph[i][j] = NULL;
			}
		}
	}
	cout << "\n\n\nThe array after being initialized is:\n";
							 
	//print();
	//Print out the graph to make sure it is entered correctly
	for (int i = 1; i < nodes; i++) {
		for (int j = 1; j < nodes; j++) {
			cout << graph[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n\n";

	int num_queries = 0;
	for (int k = 0; k < 7; k++){
		for (int i = 0; i < 7; i++){
			for (int j = 0; j < 7; j++){
				if ((graph[i][k] * graph[k][j] != 0) && (i != j)){
					if ((graph[i][k] + graph[k][j] < graph[i][j]) || (graph[i][j] == 0)){
						graph[i][j] = graph[i][k] + graph[k][j];
						cout << "\ni is: " << i << endl;
						cout << "j is: " << j << endl;
						cout << "k is: " << k << endl;
						cout << "The value at graph[" << i << "][" << j << "] is: "<< graph[i][j] << endl;
					}
				}
			}
		}
	}
	for (int i = 1; i < nodes; i++) {
		graph[i][i] = 0;
	}
	cout << "\n\n\n";
	//print();
	//Print out the graph to make sure it is entered correctly
	for (int i = 1; i < nodes; i++) {
		for (int j = 1; j < nodes; j++) {
			cout << graph[i][j] << "\t";
		}
		cout << endl;
	}
	//Now we can start to check out what queries the user has
	while (num_queries < queries) {
		cin >> start >> end;
		if (graph[start][end] == NULL) {
			cout << "NO PATH" << endl;
		}
		else {
			cout << "cost = " << graph[start][end] << endl;
		}
		num_queries++;
	}
    return 0;
}
