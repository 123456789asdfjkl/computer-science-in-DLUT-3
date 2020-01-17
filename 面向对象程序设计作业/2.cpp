#include <iostream>

using namespace std;

class array_group
{
	private:
		int name[10];
	public:
		array_group();
		int Max(int &count_max);
		int find();
		void input();
		void disp();
};

array_group::array_group()
{
	for(int i=0;i<10;i++)
		name[i]=0;
}

void array_group::input()
{
	cout<<"请输入10元整型数组\n";
	for(int i=0;i<10;i++)
		cin>>name[i];
}

void array_group::disp()
{
	for(int i=0;i<10;i++)
		cout<<name[i]<<" ";
	cout<<"\n";
}

array_group::Max(int &count_max)
{
	int max;
	max=name[0];
	count_max++;
	for(int i=1;i<10;i++)
	{
		if(name[i]>max)
		{
			max=name[i];
			count_max=1;
		}
		else if(name[i]==max)
			count_max++;
	}
	return max;
}

array_group::find()
{
	int count[10];//存储各元素重复次数
	int repeat[10];//存储重复次数最多的数组 
	int length1=0;//存储重复最多次数的数组的长度 
	int flag=1;//判断重复的标志 
	int i;
	int j;
	for(i=0;i<10;i++)
		count[i]=1;
	int max=1;//记录重复次数的最大值
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(name[i]==name[j])
			{
				count[i]++;
				count[j]++;
				if(count[i]>max)
					max=count[i];
				if(count[j]>max)
					max=count[j];
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(count[i]==max)
		{
			if(length1==0)
			{
				repeat[length1]=name[i];
				length1+=1;	
			} 
			else
			{
				for(j=0;j<length1;j++)
				{
					if(name[i]==repeat[j])
					{
						flag=0; 
						break;
					}
				}
				if(flag)
				{
					repeat[length1]=name[i];
					length1+=1;
				}
			}
		}
		flag=1; 
	}
	cout<<"重复次数最多的元素是";
	for(i=0;i<length1;i++)
	{
		cout<<repeat[i]<<" ";
	}
	cout<<"\n重复了"<<max<<"次";
	return 0; 
}

int main()
{
	array_group a;
	int count_max=0;
	cout<<"初始化后的数组元素分别为\n";
	a.disp();
	a.input();
	cout<<"输入的数组元素分别为\n";
	a.disp();
	cout<<"该数组的最大值为"<<a.Max(count_max)<<"\n";
	cout<<"最大值的个数为"<<count_max<<endl;
	a.find();
	return 0;
}
