#include <iostream>
#include <vector>
#include <queue>

#define INF 100001

#define ii pair<int, int>

using namespace std;

vector<vector<ii> > G;
int latency[20002];
int i, j, N, n, m, S, T, a, b, w;

void Dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push( ii(latency[S], S));
    ii p;
    int u, fst, snd, k;
    
    while(!pq.empty()) {
        p = pq.top();
        pq.pop();
        u = p.second;

		for(k=0; k<G[u].size(); k++) {
			fst = G[u][k].first;
        	snd = G[u][k].second;
			
            if(latency[fst] > latency[u]+snd) {
                latency[fst] = latency[u]+snd;
                pq.push( ii(latency[fst], fst));
            }
        }
    }
}

int main() {	
	// test cases = N
	scanf("%d", &N);
	
	for(i=1; i<=N; i++) {
		scanf("%d %d %d %d", &n, &m, &S, &T);
		
		G.assign(n, vector<ii>(0));
		for(j=0; j<n; j++)
			latency[j] = INF;
		latency[S] = 0;
		
		for(j=0; j<m; j++) {
			scanf("%d %d %d", &a, &b, &w);
			
			G[a].push_back( ii (b, w));
			G[b].push_back( ii (a, w));
		}
		
		Dijkstra();
		
		//for(j=0; j<m; j++)
		//	printf("%d: %d\n", j, latency[j]);
		
        printf("Case #%d: ", i);
        if(latency[T] == INF)
        	printf("unreachable\n");
		else
			printf("%d\n", latency[T]);
	}
	
	return 0;
}
