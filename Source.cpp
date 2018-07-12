#include<iostream>
#include<unordered_map>


using namespace std;
bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;
	unordered_map<char, int> mymap;
	for (int i = 0, j = 0; j<t.size(), i<s.size(); i++, j++)
	{
			mymap[s[i]]++;
			mymap[s[j]]--;

	}

	for (auto & x : mymap)
	{
		if (x.second != 0)
			return false;

	}
	return true;
}

int main()
{
	string s = "rat";
	string t = "tar";
	cout << isAnagram(s, t) << endl;
	return 0;

}