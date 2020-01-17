#include <iostream>
#include <string.h>
#define max 100//每个字符串的最大字符数
using namespace std;

class stringoperation
{
private:
	char string[10][max];
public:
	stringoperation()//构造函数 字符串清零
	{
		cout<<"调用了构造函数清空字符串\n"; 
		for(int i=0;i<10;i++)
			for (int j = 0; j < max; j++)
				string[i][j] = '\0';
	}
	stringoperation(char x[])//变换构造函数
	{
		cout << "调用变换构造函数。"<<endl;
		for (int i = 0; i < 10; i++)
			strcpy(string[i],x);
	}
	stringoperation(const stringoperation &another)//复制构造函数
	{
		cout << "调用复制构造函数。"<<endl;
		for (int i = 0; i < 10; i++)
			strcpy(string[i], another.string[i]);
	}
	void input()//字符串输入
	{
		char s[80];
		cout << "调用字符串输入函数。"<<endl;
		int i = 0;
		while (1)
		{
			cout << "请输入待输入的字符串编号(1-10)：";
			cin >> i;
			if (i <= 10 && i >= 1)
				break;
			cout << "字符串编号错误！请重新输入。"<<endl;
			while(cin.get() != '\n') ;
		}
		cout << "请输入待处理字符串："<<endl;
		cin >> string[i-1];
	}
	char* asciimin(int minquantity[10])//查找ascii值最小值函数
	{
		cout << "调用查找ascii值最小值函数。" << endl;
		static char min[10];//记录每个字符串的最小值
		int count;//记录最小值的个数
		for (int i = 0; i < 10; i++)
		{
			count=1;
			char minchar = string[i][0];
			for (int j = 1; string[i][j] != '\0'&&j < max; j++)
			{
				if (string[i][j] == minchar)
					count++;
				if (string[i][j] < minchar)
				{
					minchar = string[i][j];
					count = 1;
				}
			}
			min[i] = minchar;
			minquantity[i] = count;
		}
		cout << "字符串ascii值最小值的字符查找完成！"<<endl;
		return min;
	}
	void stringcmp()//字符串从小到大排列函数
	{
		cout << "调用字符串从小到大排列函数。" << endl;
		for(int i=0;i<10;i++)
			for (int j = 0; j < i; j++)
			{
				if (strcmp(string[i], string[j]) < 0)
				{
					char temp[max];
					strcpy(temp,string[i]);
					strcpy(string[i],string[j]);
					strcpy(string[j],temp);
				}
			}
	}
	void disp()//字符串输出
	{
		cout << "调用字符串输出函数。" << endl;
		cout << "字符串输出如下：" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (string[i][0] == '\0')
				continue;
			cout << string[i] << endl;
		}
	}
};

int main()
{
	stringoperation ss1;
	ss1.disp();
	for(int i=0;i<10;i++)
		ss1.input();
	ss1.disp();
	cout<<"----------------\n";
	char x[max];
	cout<<"请输入一个字符串:\n";
	cin>>x;
	stringoperation ss2 = x;
	ss2.disp();
	cout<<"----------------\n";
	stringoperation ss3(ss1);
	ss3.disp();
	int minquantity[10];
	char ch[10];
	strcpy(ch,ss3.asciimin(minquantity));
	cout <<"每个字符串的ascii最小值分别是："<< ch << endl;
	cout << "每个字符串的ascii最小值个数分别为";
	for (int j = 0; j < 10; j++)
		cout << minquantity[j]<<" ";
	cout << endl;
	ss3.stringcmp();
	ss3.disp();
	return 0;
}
