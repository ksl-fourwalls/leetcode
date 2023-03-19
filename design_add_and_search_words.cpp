// Design a data strucrture that supports adding new words and finding if a 
// string matching any previously added string

#include <iostream>
#include <vector>

using namespace std;

bool custom_strcmp(string& s1, string& s2)
{
	if (s1.size() != s2.size())
		return false;

	for (int idx = 0; idx < s1.size(); idx++)
		if (s1[idx] != s2[idx] && s1[idx] != '.')
			return false;
	return true;
}

vector<string> string_map;

class WordDictionary {
	public:
		WordDictionary() {
			string_map.resize(0);
		}

		void addWord(string word) 
		{
			string_map.push_back(word);
		}

		bool search(string word) 
		{
			for (auto& str: string_map)
			{
				if (str.size() != word.size())
					repeat:continue;

				for (int idy = 0; idy < word.size(); idy++)
					if (str[idy] != word[idy] && word[idy] != '.')
						goto repeat;
				return true;
			}
			return false;
		}
	private:
};

int main(int argc, char* argv[])
{
	WordDictionary *wordDic;
	vector<string> words = {
		"bad", "dad", "mad"
	};
	vector<string> searchword = {
		"pad", "bad", ".ad", "b.."
	};

	wordDic = new WordDictionary();
	for (auto& word : words)
		wordDic->addWord(word);

	for (auto& word: searchword)
		printf("%s\n", wordDic->search(word) ? "TRUE" : "FALSE");
	return 0;
}
