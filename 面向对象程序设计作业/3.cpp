#include <iostream>
#include <string.h>
#define max 100
using namespace std;

class stringoperation
{
	private:
		char string[max];
	public:
		stringoperation()
		{
			for (int i = 0; i < max; i++)
				string[i] = '\0';
		}
		void input()
		{
			cout << "请输入待处理字符串：\n";
			cin >> string;
		}
		void operator==(stringoperation &second);
		void exchange()
		{
			bool ascii[2][max];//第一行记录ascii最大值，第二行记录ascii最小值
			char maxchar = string[0], minchar = string[0];
			for (int i = 0; i < 2; i++)
				for (int j = 0; string[j] != '\0'&&j < max; j++)
					ascii[i][j] = false;
			ascii[0][0] = true, ascii[1][0] = true;
			for (int i = 1; string[i] != '\0'&&i < max; i++)
			{
				if (string[i] > maxchar)
				{
					maxchar = string[i];
					for (int j = 0; j < i; j++)
						ascii[0][j] = false;
					ascii[0][i] = true;
				}
				if (string[i] < minchar)
				{
					minchar = string[i];
					for (int j = 0; j < i; j++)
						ascii[1][j] = false;
					ascii[1][i] = true;
				}
				if (string[i] == maxchar)
					ascii[0][i] = true;
				if (string[i] == minchar)
					ascii[1][i] = true;
			}
			for (int i = 0; string[i] != '\0'&&i<max; i++)
			{
				if (ascii[0][i] == true)
					string[i] = minchar;
				if (ascii[1][i] == true)
					string[i] = maxchar;
			}
			cout << "字符串中ASCII码最大和最小的字符转换完成！\n";
		}
		void disp()
		{
			cout << "字符串输出如下：\n" << string<<"\n";
		}
};

void stringoperation::operator==(stringoperation &second)
{
	if (strcmp(string, second.string) > 0)
		cout << "两字符串中ASCII码值较大的是" << string<<"\n";
	else if (strcmp(string, second.string) < 0)
		cout << "两字符串中ASCII码值较大的是" << second.string<<"\n";
	else
		cout << "两字符串相同\n";
}

int main()
{
	stringoperation ss1,ss2;
	ss1.input();
	ss1.disp();
	ss2.input();
	ss2.disp();
	ss1 == ss2;
	cout << "下面对字符串1进行ASCII码值最大和最小的字符进行交换操作\n";
	ss1.exchange();
	ss1.disp();
	return 0;
}
