// There are n cities connected by some number of flights. You are given an array flights where 
// flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with
// cost pricei.
//
// You are also given three integers src, dst, and k return the cheapest price from src to dest with
// at most k stops. If there is no such route return -1

#include <iostream>
#include <vector>

using namespace std;

struct EdgeInfo {
	int which;
	int cost;
};

struct LinkedList 
{
	struct EdgeInfo curEdge;
	struct LinkedList* next;
};

struct LinkedListMem 
{
	struct LinkedList* ptr;
	int cursize;

	LinkedListMem(int size) 
	{
		ptr = (LinkedList *)malloc(sizeof(struct LinkedList) * (size+1));
		cursize = 0;
	}
	~LinkedListMem() 
	{
		free(ptr);
	}
	struct LinkedList* static_alloc() 
	{ 
		return &ptr[cursize++]; 
	}
} *ListManager;

struct LinkedList* sorted_push(struct LinkedList* head, int which, int cost)
{
	struct LinkedList *tp = ListManager->static_alloc(), *tmp = head;

	tp->curEdge.which = which;
	tp->curEdge.cost = cost;
	tp->next = nullptr;

	if (tmp)
	{
		if (tmp->curEdge.cost >= cost)
		{
			tp->next = tmp;
			return tp;
		}

		while (tmp->next)
		{
			if (tmp->curEdge.cost >= cost)
			{
				tp->next = tmp;
				break;
			}
			tmp = tmp->next;
		}
		tmp->next = tp;
	}
	else { return tp; }

	return head;
}


class Solution {
	public:
		// this algorithm works but it fails in case of 
		// wrong heuristics
		// bounded depth first search with heuristics
		int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
		{
			vector<LinkedList*> graph;
			vector<EdgeInfo> m_Stack;		// stack contains index of the 
			LinkedListMem LinkedListManager(flights.size());		// this 
			int total_visited = 0, cheapestCost = -1;

			ListManager = &LinkedListManager;
			graph.resize(n);

			// form a graph
			for (auto& flight: flights)
				graph[flight[0]] = sorted_push(graph[flight[0]], flight[1], flight[2]);

			m_Stack.push_back({src, 0});
			while (!m_Stack.empty())
			{
				int peekedNode = m_Stack.back().which;
				if (graph[peekedNode] && total_visited <= k)
				{
					if (graph[peekedNode]->curEdge.which != dst)
						m_Stack.push_back(graph[peekedNode]->curEdge);
					else
					{
						int temp = 0;
						for (auto curEdge: m_Stack)
							temp += curEdge.cost;
						temp += graph[peekedNode]->curEdge.cost;
						printf("%d\n", temp);
						if ((unsigned)temp < (unsigned)cheapestCost)
							cheapestCost = temp;
					}
					graph[peekedNode] = graph[peekedNode]->next;
					total_visited++;
				}
				else
				{
					m_Stack.pop_back();
					total_visited--;
				}
			}
			return cheapestCost;
		}
};


// wrong heuristics
int main(int argc, char* argv[])
{
	Solution s;
	vector<vector<int>> flights = {
	// from, to, price
		{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}

	};

	// @params:
	// n, flights, src, dst, k
	cout << s.findCheapestPrice(10, flights, 6, 0, 7) << endl;
	return 0;
}
