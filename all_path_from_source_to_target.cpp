#include <iostream>
#include <vector>
#include <stack>

using namespace std;


// 
class Solution {
	public:
		vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
		{
			vector<vector<int>> allpaths;
			int* visitIdx = (int*)calloc(sizeof(int), graph.size());

			// memory for visited node
			vector<int> indices_stack;		// we will save memory
							// by only storing indices on 
							// stack
			int destination = graph.size() - 1;


			indices_stack.push_back(0);
			while (!indices_stack.empty())
			{
				// we taking newly pushed value from the stack
				int peeked_value = indices_stack.back(), unvisitedVertex = -1;


				// get the unvisited vertex of vertex which is at the top of the
				// stack
				if (visitIdx[peeked_value] < graph[peeked_value].size())
				{
					unvisitedVertex = graph[peeked_value][visitIdx[peeked_value]];

					if (unvisitedVertex == destination)
					{
						vector<int> tempvec = indices_stack;
						tempvec.push_back(destination);
						allpaths.push_back(tempvec);
					}
					visitIdx[peeked_value]++;
				}

				if (unvisitedVertex == -1)
				{
					visitIdx[peeked_value] = 0;
					indices_stack.pop_back();
				}
				else
					indices_stack.push_back(unvisitedVertex);
			}

			free(visitIdx);
			return allpaths;
		}
};



int main(int argc, char* argv[])
{
	Solution s;
	vector<vector<int>> graph = {
		{ 4, 3, 1 },
		{ 3, 2, 4 },
		{ 3 },
		{ 4 },
		{ },
	};
	
	vector<vector<int>> allpaths;

	allpaths = s.allPathsSourceTarget(graph);
	for (auto& paths : allpaths)
	{
		cout << "[";
		if (paths.size() > 0)
		{
			for (int idx = 0; idx < (int)(paths.size()-1); idx++)
				cout << paths[idx] << ", ";
			cout << paths[paths.size()-1];
		}
		cout << "]" << endl;

	}
	return 0;
}
