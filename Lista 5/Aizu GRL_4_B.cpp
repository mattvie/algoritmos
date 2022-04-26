#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LIMIT_V 10001
#define LIMIT_E 100001

int main() {
	int V, E;
	int i, s_x, t_x, q_out, q_in;
	
	vector<int> G[LIMIT_V]; // graph
	int counter[LIMIT_E];
	queue<int> q; // output
	
    scanf("%d %d", &V, &E);
    
    for (i=0; i<E; i++) {
        scanf("%d %d", &s_x, &t_x);
        G[s_x].push_back(t_x);
        counter[t_x]++;
    }
    
    for (i=0; i<V; i++) {
        if (!counter[i])
            q.push(i);
    }
    
    while (!q.empty()) {
        q_out = q.front();
        q.pop();
        
        printf("%d\n", q_out);
        
		for (i=0; i<G[q_out].size(); i++) {
            int q_in = G[q_out][i];
            counter[q_in] -= 1;
            if (counter[q_in] == 0)
				q.push(q_in);
			//printf("i=%d. to=%d\n", i, to);
        }
    }
}

