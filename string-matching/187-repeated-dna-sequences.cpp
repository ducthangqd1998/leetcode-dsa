#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
	std::map<char, int> dna;

	Solution()
	{
		dna['A'] = 1;
		dna['C'] = 2;
		dna['G'] = 3;
		dna['T'] = 4;
	}

	vector<string> findRepeatedDnaSequences(string s)
	{
		int n = s.length();
		vector<string> arr;
		if (n < 10)
			return {};

		unordered_map<long, int> m;
		int hash = 0;

		for (int i = 0; i < 10; i++)
		{
			hash += this->dna[s[i]] * pow(4, 9 - i);
		}

		m[hash] = 1;

		for (int i = 1; i < n - 9; i++)
		{
			hash = 4 * (hash - this->dna[s[i - 1]] * pow(4, 9)) +
				   this->dna[s[i + 9]];
			m[hash] += 1;
			if (m[hash] == 2)
				arr.push_back(s.substr(i, 10));
		}
		return arr;
	}
};

int main()
{
	Solution solution;
	solution.findRepeatedDnaSequences("ACCCTCCCACTTGGATGCCGCACGTGTCGACTAACCTTACATTGTCCCCCCACCTCCAGACGGTTAACTCTTGAAATGGGGGAATAGCTGCTTGCGCGTG");
	return 0;
}