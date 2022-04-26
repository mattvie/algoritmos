#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 100
#define MAX_INT 2147483647

map <string, int> Rank;
vector <int> graph[3*MAX_N+1];

int _count;
char tm_1[21], tm_2[21], tm_3[21];
int rank_1, rank_2, rank_3;
string names[3*MAX_N+1];
int ans[3*MAX_N+1];

void clearAns(int j) {
	int u;
	for(u=1; u<3*j+1; u++)
		ans[u] = MAX_INT;
}

int getRank(string teammate) {
	int _ans = Rank[teammate];
	
	if(!_ans) {
		Rank[teammate] = _ans = ++_count;
		names[_count] = teammate;
	}
	
	return _ans;	
}

void updateRanks() {
	graph[rank_1].push_back(rank_2);
	graph[rank_1].push_back(rank_3);
	
	graph[rank_2].push_back(rank_1);
	graph[rank_2].push_back(rank_3);
	
	graph[rank_3].push_back(rank_1);
	graph[rank_3].push_back(rank_2);
}

bool logic(string x, string y) { return (ans[Rank[x]]!=ans[Rank[y]] ? ans[Rank[x]] < ans[Rank[y]] : x < y); }

void debug() {
	int k;
	
	// Print names
	for(k=1; k<=_count; k++)
		printf("names[%d] = %s\n", k, names[k].c_str());
		
	// Print Rank
	for(k=1; k<=_count; k++)
		printf("Rank[%d] = %d\n", k, Rank[names[k]]);
		
	// Print ans
	for(k=1; k<=_count; k++)
		printf("ans[%d] = %d\n", k, ans[Rank[names[k]]]);
	
}

int main() {
	unsigned int T, N;	// T=test cases 0<T<10	N=number of teams
	int i;
	
	scanf("%d", &T);
	
	while (T--) {
		
		scanf("%d", &N);
		
		// clear data structures here
		for(i=1; i<=3*N; i++)
			graph[i].clear();
		Rank.clear();
		clearAns(N);
		
		// Setting Ahmad Rank
		Rank["Ahmad"] = _count = 1;
		names[1] = "Ahmad";
		
		// Getting teammates
		for(i=1; i<=N; i++) {
			scanf("%s %s %s", &tm_1, &tm_2, &tm_3);
			rank_1 = getRank(tm_1);
			
			//scanf("%s", &tm_2);
			rank_2 = getRank(tm_2);
			
			//scanf("%s", &tm_3);
			rank_3 = getRank(tm_3);
			
			updateRanks();
		}
		
		ans[1] = 0;
		
		queue <int> q;
		q.push(1);
		
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			
			for(i=0; i<graph[front].size(); i++) {
				if(ans[graph[front][i]] == MAX_INT) {
					ans[graph[front][i]] = ans[front]+1;
					q.push(graph[front][i]);	
				}
			}
		}
		
		sort(names, (names+_count+1), logic);
		
		//debug();
		
		printf("%d\n", _count);
		for(i=1; i<=_count; i++) {
			printf("%s", names[i].c_str());
			
			if(ans[Rank[names[i]]]==MAX_INT)
				printf(" undefined\n");
			else
				printf(" %d\n", ans[Rank[names[i]]]);
		}
		
	}
	
	return 0;
}
