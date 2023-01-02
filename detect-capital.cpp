// We define the usage of capitals in a word to be right when one of the following cases
// holds:
//
//

// All letters in this words are capitals, like "USA"
// All letters in this words are not capitals, like "leetcode"
// Only first letter in this word is capital like "Google"


#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		bool detectCapitalUse(string word)
		{
			size_t size = word.size(), idx = 0;
			bool flag = false;

			if (idx < size)
			{
				if (isupper(word[idx++]))
				{
					if (idx < size)
					{
						if (isupper(word[idx++]))
						{
							for (; idx < size; idx++)
							{
								if (!isupper(word[idx]))
									return false;
							}

						}
						else
							goto dome;
					}

				}
				else
				{
dome: 					for (; idx < size; idx++)
						if (isupper(word[idx]))
							return false;
				}
			}
			return true;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	string word = "FlAG";
	printf("%s\n", s.detectCapitalUse(word) ? "TRUE": "FALSE");
	return 0;
}
