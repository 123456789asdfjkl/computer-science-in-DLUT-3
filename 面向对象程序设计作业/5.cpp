#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class cLink
{
    friend class cList;
    cLink *next;
    char name[20];//姓名
    int number;//学号
    char sex[5];//性别
    char birth[10];//出生日期
    int chinese;//语文成绩
    int math;//数学成绩
    int english;//英语成绩
    int sum;//总成绩
public:
    cLink(){

    }
    cLink(char a[],int b,char c[], char d[], int e,int f,int g)
    {
        strcpy(name,a);
        number=b;
        strcpy(sex,c);
        strcpy(birth,d);
        chinese=e;
        math=f;
        english=g;
        sum=e+f+g;
    }

    cLink *get_next(void)
    {
        return(next);
    }

    void print(void)
    {
        cout<<name<<"\t"<<number<<"\t"<<sex<<"\t"<<birth<<"\t "<<chinese<<"\t          "<<math<<"         \t"<<english<<"        \t"<<sum<<"   \n";
    }

};
class cList
{
protected:
    cLink *first;
    cLink *last;
public:
    cList(void)
    {
        first=last=new cLink;
    }
    ~cList()
    {
        Clear();
        delete first;
    }
    cList& Insert(const cLink &x);
    void Delete(char x[]);
    void Delete(int x);
    cList& Clear(void);
    void Find(char x[]);
    void Find(int x);
    void Max_and_Min(void);
    int Count(void);
    void Sort(void);
    void Disp(void);
};
cList& cList::Insert(const cLink &x) {
    cLink *ptr=first;
    first=new cLink;
    *first=x;
    first->next=ptr;
    return *this;
}
//  学号唯一因此不考虑重复
void cList::Delete(int x) {
    cLink *ptr=first;
    cLink *ptr1;
    if (first!=last) {
        if (ptr->number==x)
        {
            first=first->next;
            ptr1=ptr;
            delete(ptr1);
        } else {
            ptr = ptr->next;
            ptr1 = first;
            while (ptr != last) {
                if (ptr->number == x) {
                    ptr1->next = ptr->next;
                    delete(ptr);
                    break;
                }
                ptr1 = ptr1->next;
                ptr = ptr->next;
            }
        }
    }
    cout<<"删除后的列表:\n";
    cout<<"姓名\t"<<"学号\t"<<"性别\t"<<"出生年月日\t"<<"语文成绩\t"<<"数学成绩\t"<<"英语成绩\t"<<"总成绩\n";
    Disp();
}
//  姓名不唯一可能有重名，因此考虑多个
void cList::Delete(char x[]) {
    cLink *ptr=first;
    cLink *ptr1;
    if (first!=last) {
        if (!(strcmp(ptr->name,x)))
        {
            first=first->next;
            ptr1=ptr;
            delete(ptr1);
        } 
        ptr = ptr->next;
        ptr1 = first;
        while (ptr != last) {
            if (!(strcmp(ptr->name,x))) {
                ptr1->next = ptr->next;
                delete(ptr);
            }
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
    
    }
    cout<<"删除后的列表:\n";
    cout<<"姓名\t"<<"学号\t"<<"性别\t"<<"出生年月日\t"<<"语文成绩\t"<<"数学成绩\t"<<"英语成绩\t"<<"总成绩\n";
    Disp();
}
cList& cList::Clear() {
    cLink *ptr=first;
    while(ptr!=last){
        cLink *next=ptr->next;
        delete(ptr);
        ptr=next;
    }
    first=last;
    return *this;
}
//  学号唯一因此不考虑重复
void cList::Find(int x) {
    cLink *ptr=first;
    cout<<"姓名\t"<<"学号\t"<<"性别\t"<<"出生年月日\t"<<"语文成绩\t"<<"数学成绩\t"<<"英语成绩\t"<<"总成绩\n";
    while (ptr != last) {
        if (ptr->number == x) {
            ptr->print();
            break;
        }
        ptr = ptr->next;
    }
}
//  姓名不唯一可能有重名，因此考虑多个
void cList::Find(char x[]) {
    cLink *ptr=first;
    cout<<"姓名\t"<<"学号\t"<<"性别\t"<<"出生年月日\t"<<"语文成绩\t"<<"数学成绩\t"<<"英语成绩\t"<<"总成绩\n";
    while (ptr != last) {
        if (!(strcmp(ptr->name,x))) {
        	
            ptr->print();
        }
        ptr = ptr->next;
    }
}
void cList::Max_and_Min() {
    cLink *ptr=first;
    cLink *max,*min;
    if (ptr!=last){
        max=min=ptr;
        ptr=ptr->next;
        while (ptr!=last){
            if(ptr->sum>max->sum){
                max=ptr;
            }
            if (ptr->sum<min->sum){
                min=ptr;
            }
            ptr=ptr->next;
        }
        cout<<"最高学生成绩信息如下：\n";
        cout<<"姓名\t"<<"学号\t"<<"性别\t"<<"出生年月日\t"<<"语文成绩\t"<<"数学成绩\t"<<"英语成绩\t"<<"总成绩\n";
        max->print();
        cout<<"最低学生成绩信息如下：\n";
        cout<<"姓名\t"<<"学号\t"<<"性别\t"<<"出生年月日\t"<<"语文成绩\t"<<"数学成绩\t"<<"英语成绩\t"<<"总成绩\n";
        min->print();

    } else{
        cout<<"表为空，不存在最大最小值\n";
    }
}

int cList::Count() {
    int count=0;
    cLink *ptr=first;
    while(ptr!=last){
        count++;
        ptr=ptr->next;
    }
    return count;
}
void cList::Sort() {
    int count=Count();
    cLink *ptr1,*ptr2,*ptr3,*ptr;
    ptr1=first;
    ptr2=first->next;
    while(count) {
    	ptr1=first;
    	ptr2=first->next;
        if (ptr2 != last) {
            if (ptr1->sum < ptr2->sum) {
                ptr1->next = ptr2->next;
                ptr2->next = ptr1;
                first = ptr2;
            }
        }
        ptr3 = first;
        ptr1 = first->next;
        ptr2 = ptr1->next;
        while (ptr2 != last) {
            if (ptr1->sum < ptr2->sum) {
                ptr3->next = ptr1->next;
                ptr1->next = ptr2->next;
                ptr2->next = ptr1;
                ptr = ptr1;
                ptr1 = ptr2;
                ptr2 = ptr;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        count--;
    }
    ptr=first;
    cout<<"排序后的学生成绩信息:\n";
    Disp();
}
void cList::Disp() {
    cLink *ptr=first;
    cout<<"姓名\t"<<"学号\t"<<"性别\t"<<"出生年月日\t"<<"语文成绩\t"<<"数学成绩\t"<<"英语成绩\t"<<"总成绩\n";
    while (ptr!=last){
        ptr->print();
        ptr=ptr->next; 
    }
}
void biao(){
    cout<<" ----------------------------------------------------------------\n";
    cout<<"|\t0.输入学生信息                                            |\n";
    cout<<"|\t1.根据给定的学生姓名或学号删除该学生节点                  |\n";
    cout<<"|\t2.根据给定的学生姓名或学号查找学生信息，并显示出来        |\n";
    cout<<"|\t3.查找并显示总成绩最高和最低的学生信息                    |\n";
    cout<<"|\t4.统计链表中的学生人数                                    |\n";
    cout<<"|\t5.对链表节点按总成绩从高到低排序                          |\n";
    cout<<"|\t6.显示学生全部信息                                        |\n";
    cout<<"|\t7.退出                                                    |\n";
    cout<<" ----------------------------------------------------------------\n";
}
int main()
{
    cList list;
    int a;
    int b;
    int count;
    char name1[20];
    int number1;
    char name[20];//姓名
    int number;//学号
    char sex[5];//性别
    char birth[10];//出生日期
    int chinese;//语文成绩
    int math;//数学成绩
    int english;//英语成绩
    int sum;//总成绩
    int flag;
    while(1){
        biao();
        cout<<"请选择你想要的操作:";
        cin>>a;
        if(a>=0&&a<=7){
            switch (a){
                case 0:
                    cout<<"请输入名字:";
                    cin>>name;
                    cout<<"请输入学号:";
                    cin>>number;
                    cout<<"请输入性别:";
                    cin>>sex;
                    cout<<"请输入出生年月日：";
                    cin>>birth;
                    cout<<"请输入语文成绩:";
                    cin>>chinese;
                    cout<<"请输入数学成绩:";
                    cin>>math;
                    cout<<"请输入英语成绩:";
                    cin>>english;
                    list.Insert(cLink(name,number,sex,birth,chinese,math,english));
                    break;
                case 1:
                    cout<<"请选择（1.按姓名，2.按学号）：";
                    cin>>b;
                    switch (b){
                        case 1:
                            cout<<"请输入要删除的名字:";
                            cin>>name1;
                            list.Delete(name1);
                            break;
                        case 2:
                            cout<<"请输入要删除的学号:";
                            cin>>number1;
                            list.Delete(number1);
                            break;
                    }
                    break;
                case 2:
                    cout<<"请选择（1.按姓名，2.按学号）：";
                    cin>>b;
                    switch (b){
                        case 1:
                            cout<<"请输入要查看的名字:";
                            cin>>name1;
                            list.Find(name1);
                            break;
                        case 2:
                            cout<<"请输入要查看的学号:";
                            cin>>number1;
                            list.Find(number1);
                            break;
                    }
                    break;
                case 3:
                    list.Max_and_Min();
                    break;
                case 4:
                    count=list.Count();
                    cout<<"链表中的学生人数为"<<count<<"名\n";
                    break;
                case 5:
                    list.Sort();
                    break;
                case 6:
                    list.Disp();
                    break;
                case 7:
                    flag=1;
                    break;
            }
            if(flag){
                break;
            }
        } else{
            cout<<"输入错误";
        }

    }
    return 0;
}


