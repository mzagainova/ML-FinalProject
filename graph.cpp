#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// Data structure to store Adjacency list nodes
struct Node {
	int val;
	Node* next;
};

// Data structure to store graph edges
struct Edge {
	int src, dest;
};

class Graph {

	// Function to allocate new node of Adjacency List
	Node* getAdjListNode(int dest, Node* head) {
		Node* newNode = new Node;
		newNode->val = dest;

		// point new node to current head
		newNode->next = head;

		return newNode;
	}

	int N;	// number of nodes in the graph

public:

	// An array of pointers to Node to represent
	// adjacency list
	Node **head;

	// Constructor
	Graph(Edge edges[], int n, int N) {
		// allocate memory
		head = new Node*[N]();
		this->N = N;

		// initialize head pointer for all vertices
		for (int i = 0; i < N; i++)
			head[i] = nullptr;

		// add edges to the directed graph
		for (unsigned i = 0; i < n; i++) {
			int src = edges[i].src;
			int dest = edges[i].dest;

			// insert in the beginning
			Node* newNode = getAdjListNode(dest, head[src]);

			// point head pointer to new node
			head[src] = newNode;
		}
	}

	void addEdge(Edge edge) {
		int src = edge.src;
		int dest = edge.dest;

		// insert in the beginning
		Node* newNode = getAdjListNode(dest, head[src]);

		// point head pointer to new node
		head[src] = newNode;
	}

	bool existsEdge(Graph graph, int src, int dest) {
		for (int i = 0; i < N; i++) {
			if(i == src) {
				Node *ptr = graph.head[i];
				while (ptr != nullptr) {
					if(ptr->val == dest) {
						return true;
					}
					ptr = ptr->next;
				}
				return false;
			}
		}
		return false;
	}

};

// print all neighboring vertices of given vertex
void printList(Node* ptr) {
	while (ptr != nullptr) {
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

// Graph Implementation in C++ without using STL
int main() {
	// array of graph edges as per above diagram.
	Edge edges[] = {
		// pair (x, y) represents edge from x to y
		{ 0, 1 }, { 0, 3 }, { 1, 2 }, { 3, 2 },
		{ 2, 3 }, { 2, 1 }, { 3, 4 }, { 1, 4 },
	};

	// Number of vertices in the graph
	int N = 5;

	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph
	Graph graph(edges, n, N);

	Edge edge = {4,3};
	graph.addEdge(edge);

	// print adjacency list representation of graph
	for (int i = 0; i < N; i++) {
		// print given vertex
		cout << i << " --";

		// print all its neighboring vertices
		printList(graph.head[i]);
	}

	int i = 0;
	if(graph.existsEdge(graph,2,1) && graph.existsEdge(graph,2,1)) {
		cout << "Exitsts double edge from 1 to 2.\n";
	}

	list<int> ex1({1,2,3,4});
	list<int> ex2({3,2,1,5});
	list<int> ex1_temp(ex1);
	list<int> ex2_temp(ex2);
	vector<pair<int,int>> orNodes;

	for(auto i = ex1_temp.begin(); i < ex1_temp.end(); ++i) {
		for(auto j = ex2_temp.begin(); j < ex2_temp.end(); ++j) {
			if(*i == *j) {
				ex1_temp.remove(*i);
				ex2_temp.remove(*j);
			}
		}
	}
	//cout << ex1_temp << endl;



	return 0;
}
