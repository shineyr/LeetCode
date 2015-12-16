#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		if (words.empty())
			return vector<string>();
		vector<string> ret;

		int sz = words.size();

		/*sumLen记录当前字符串长度，count记录包含的单词个数*/
		vector<string> tmp;
		int sumLen = 0, count = 0;
		for (int i = 0; i < sz; ++i)
		{
			/*判断是否可以添加一个字符串*/
			if ((sumLen + words[i].length() + count) <= maxWidth)
			{
				/*满足要求，单词个数增一，保存*/
				++count;
				sumLen = sumLen + words[i].length();
				tmp.push_back(words[i]);
				continue;
			}//if
			else{
				/*只有一个单词，左对齐*/
				if (1 == count)
				{
					string str = tmp[0];
					while (str.length() < maxWidth)
						str += " ";
					ret.push_back(str);
				}//if
				else{
					string str = "";
					/*计算多余的空格总数，每个间隔至少一个空格*/
					int extraSpace = maxWidth - sumLen - count + 1;
					/*每个间隔需再增加的间隔*/
					int everySpace = extraSpace / (count - 1);
					/*前间隔需要额外放置一个空格的间隔数*/
					int frontSpace = extraSpace % (count - 1);					
					
					for (int k = 0; k < count - 1; ++k)
					{
						int j = 0;
						while (j < everySpace + 1)
						{
							tmp[k] += " ";
							++j;
						}//while
					}//for
					/*前frontSpace个间隔需要再放一个空格*/
					for (int k = 0; k < frontSpace; ++k)
					{
						tmp[k] += " ";
					}
					/*连接这些字符串*/
					for (int k = 0; k < count; ++k)
					{
						str += tmp[k];
					}//for
					ret.push_back(str);				
				}//else
			}//else
			tmp.clear();
			count = 0;
			sumLen = 0;
			--i;
		}//for
		/*处理最后一组,也就是尾行*/
		/*只有一个单词，左对齐*/
		if (1 == count)
		{
			string str = tmp[0];
			while (str.length() < maxWidth)
				str += " ";
			ret.push_back(str);
		}//if

		if(count > 1){
			string str = "";				
			/*末行的每个单词间放一个空格，其余空格放在尾部*/
			for (int k = 0; k < count - 1; ++k)
			{
				str = str + tmp[k] + " ";
			}//for
			str += tmp[count - 1];
			while (str.length() < maxWidth)
				str += " ";
			ret.push_back(str);
		}//else		
		return ret;
	}
};

int main()
{
	Solution s;
	vector<string> words = { "Don't", "go", "around", "saying", "the", "world", "owes", "you", "a", "living;", "the", "world", "owes", "you", "nothing;", "it", "was", "here", "first."};
	vector<string> ret = s.fullJustify(words , 30);

	for (unsigned i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}//for
	system("pause");
	return 0;
}