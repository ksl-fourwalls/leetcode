// There are n cities connected by some number of flights. You are given an array flights where 
// flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with
// cost pricei.
//
// You are also given three integers src, dst, and k return the cheapest price from src to dest with
// at most k stops. If there is no such route return -1

#include <iostream>
#include <climits>
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
	else 
	{
		tp->next = nullptr;
		return tp;
	}
	return head;
}


typedef int64_t setCollection;
class BitSet {
	public:
		BitSet(int sets) 
		{
			size = (sets % MAX_BITS == 0) ? (sets / MAX_BITS) : (sets / MAX_BITS + 1);
			transition_cols = (setCollection*)calloc(MAX_BITS / CHAR_BIT, size);
		}
		~BitSet() 
		{
			free(transition_cols);
		}

		bool operator[](int which) 
		{
			size_t idx = which / MAX_BITS;
			return (transition_cols[idx] >> (which % MAX_BITS)) & 1;
		}

		void set(int which)
		{
			size_t idx = which / MAX_BITS;
			transition_cols[idx] |= (setCollection)1 << (which % MAX_BITS);
		}

	private:
		setCollection *transition_cols;
		const int MAX_BITS = sizeof(setCollection) * CHAR_BIT;
		size_t size;
};

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
			BitSet visited(n);
			int total_visited = 0, cheapestCost = -1;

			ListManager = &LinkedListManager;
			graph.resize(n);

			// form a graph
			for (auto& flight: flights)
				graph[flight[0]] = sorted_push(graph[flight[0]], flight[1], flight[2]);

			m_Stack.push_back({src, 0});
			visited.set(src);

			while (!m_Stack.empty())
			{
				int peekedNode = m_Stack.back().which;
				if (graph[peekedNode] && !visited[graph[peekedNode]->curEdge.which] && total_visited <= k)
				{
					if (graph[peekedNode]->curEdge.which != dst)
					{
						m_Stack.push_back(graph[peekedNode]->curEdge);
						visited.set(m_Stack.back().which);
					}
					else
					{
						++cheapestCost;
						for (auto curEdge: m_Stack)
							cheapestCost += curEdge.cost;
						cheapestCost += graph[peekedNode]->curEdge.cost;
						break;
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
		{ 0, 1, 100 },
		{ 1, 2, 100 },
		{ 2, 0, 100 },
		{ 1, 3, 600 },
		{ 2, 3, 200 },
	};
	/*
	vector<vector<int>> flights = {
		{ 0, 1, 100 },
		{ 1, 2, 100 },
		{ 0, 2, 500 },
	};
	*/

	// @params:
	// n, flights, src, dst, k
	cout << s.findCheapestPrice(3, flights, 0, 2, 0) << endl;
	return 0;
}
