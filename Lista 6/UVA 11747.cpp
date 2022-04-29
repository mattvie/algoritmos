#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Edge {
	int u;
	int v;
	int weight;
} Edge;

Edge EDGES[25002];
vector <int> GRAPH;
int NODES[1002],
	NUM_NODES[1002];

int Root(int k) {
	if(k==NODES[k])
		return k;
		
	NODES[k] = Root(NODES[k]);
	return NODES[k];
}

void Union(int i) {
	int x = Root(EDGES[i].u),
		y = Root(EDGES[i].v);
		
	if(x==y)
		GRAPH.push_back(EDGES[i].weight);
	else
		NODES[x] = y;
}

bool weight_function(Edge A, Edge B) {
	if(A.weight < B.weight)
		return true;
	return false;
}

int main() {
	// number of nodes, number of edges
	int n, m, i, u, v, w, order;
	scanf("%d %d", &n, &m);
	
	while(n || m) {
		
		for(i=0; i<n; i++) {
			NODES[i] = i;
			NUM_NODES[i] = 0;
		}

		order = 1;
		for(i=0; i<m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			EDGES[i].weight = w;
			
			if(NUM_NODES[u]==0)
				NUM_NODES[u] = order++;
			if(NUM_NODES[v]==0)
				NUM_NODES[v] = order++;
			
			EDGES[i].u = NUM_NODES[u];
			EDGES[i].v = NUM_NODES[v];
		}
		
		sort(EDGES, EDGES+m, weight_function);
		
		GRAPH.clear();
		
		for(i=0; i<m; i++)
			Union(i);
			
		if(GRAPH.empty())
			printf("forest\n");
		else {
			printf("%d", GRAPH[0]);
			
			for(i=1; i<GRAPH.size(); i++)
				printf(" %d", GRAPH[i]);
			printf("\n");
		}
		
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}
