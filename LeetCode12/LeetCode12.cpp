#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		//存储罗马数字
		string str;
		if (num == 0)
			return "";
		
		//（1）首先处理最高位千位数字
		if (num >= 1000)
		{
			int count = num / 1000;
			for (int i = 0; i < count; i++)
				str += RomanLeter(1000);
		   //得到百位数
			num %= 1000;
		   //链接其余三位数字对应的罗马序列
			str += intToRoman(num);
		}//else if
		else if (num >= 100)
		{
			if (num >= 900)
			{
				str = str + RomanLeter(100) + RomanLeter(1000);
				num %= 100;
			}//if				
			else if (num >= 500)
			{
				str += RomanLeter(500);
				num -= 500;
				
			}//else if
			else if (num >= 400){
				str = str + RomanLeter(100) + RomanLeter(500);
				num -= 400;
			}
			else{
				while (num >= 100)
				{
					str += RomanLeter(100);
					num -= 100;
				}//while
			}
			str += intToRoman(num);
		}//else if
		else if (num >= 10)
		{
			if (num >= 90)
			{
				str = str + RomanLeter(10) + RomanLeter(100);
				num %= 10;
			}//if
			else if (num >= 50)
			{
				str += RomanLeter(50);
				num -= 50;				
			}
			else if (num >= 40){
				str = str + RomanLeter(10) + RomanLeter(50);
				num -= 40;
			}
			else{
				while (num >= 10)
				{
					str += RomanLeter(10);
					num -= 10;
				}
			}
			str += intToRoman(num);
		}
		else if (num >= 1)
		{
			if (num == 9)
			{
				str = str + RomanLeter(1) + RomanLeter(10);
				num /= 10;
			}
			else if (num >= 5)
			{
				str += RomanLeter(5);
				num -= 5;				
			}
			else if (num >= 4){
				str = str + RomanLeter(1) + RomanLeter(5);
				num -= 4;
			}
			else{
				while (num >= 1)
				{
					str += RomanLeter(1);
					num -= 1;
				}
			}
			str += intToRoman(num);
		}
		else
			str += "\0";
		return str;
	}

	string RomanLeter(int n)
	{
		switch (n)
		{
		case 1:
			return "I"; break;
		case 5:
			return "V"; break;
		case 10:
			return "X"; break;
		case 50:
			return "L"; break;
		case 100:
			return "C"; break;
		case 500:
			return "D"; break;
		case 1000:
			return "M"; break;
		default:
			return ""; break;
		}
	}
};

int main()
{
	Solution *s = new Solution();
	for (int i = 8; i < 199; i++)
		cout << i << ": " << s->intToRoman(i) << endl;

	system("pause");

	return 0;
}
