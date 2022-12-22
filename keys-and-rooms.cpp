#include <iostream>
#include <vector>
using namespace std;


class Solution {
	public:
		bool find(vector<int> vecArray, int num)
		{
			for (int idx = 0; idx < vecArray.size(); idx++)
			{
				if (num == vecArray[idx])
					return true;
			}
			return false;
		}
		bool canVisitAllRooms(vector<vector<int>>& rooms) {
			unsigned total_rooms = rooms.size();
			bool *roomskey;
			vector<unsigned> indices;

			roomskey = alloca(sizeof(bool) * total_rooms);

			// clean up memory
			memset(roomskey, 0, sizeof(bool) * total_rooms);
			roomskey[0] = true;

			for (int idy = 0; idy < rooms.size(); idy++)
			{
				if (!find(rooms[idy], idy)) {
					for (int idx = 0; idx < rooms[idy].size(); idx++)
						roomskey[rooms[idy][idx]] = true;
				}
				else 
					indices.push_back(idy);

			}

			for (int idx = 0; idx < total_rooms; idx++)
				if (roomskey[idx] == false) 
					return false;
			return true;
		}
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<int>> thisintga = {
		{ },
		{ 1 },
		{ 2 },
	};

	printf("%s\n", s.canVisitAllRooms(thisintga) ? "true" : "false");
	return 0;
}
