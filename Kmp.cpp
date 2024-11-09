#include<iostream>
#include <vector>
using namespace std;
//注意！size_t类型不能与负数比较大小！
//求next数组
void getnextArray(string& a,int next[]){
next[0]=-1;
int i=0,j=-1;//i为遍历串a的指针，j指示前j-1与i-j到i间字符串匹配
while(i<a.length()){
    if(j==-1||a[i]==a[j])
    {
        next[++i]=++j;//若i,j相等，后一位next值赋值为j+1
    }
    else{
        j=next[j];//否则j指向next[j]继续判断前next[j]-1字串与i-1开始字串是否相等
    }
}
}
//Kmp算法
int index_Kmp(string& a,string& b,int next[]){
    //a为模式串，b为主串
    int j=0,i=0;
   // cout<<a.length()<<b.length();
    while(j<(int)a.length()&&i<b.length()){
        if(a[j]==b[i]||j==-1)
        {
            ++i;++j;
        }
        else{
            j=next[j];
        }
    }
    if(j>=a.length())
    return i-a.length();
    else return -1;
}
int main(){
int next[8];
string a="abaabcac";
getnextArray(a,next);
 for(int b:next){
   cout<<b<<endl;
}
string b="dabaabcacaa";
cout<<index_Kmp(a,b,next);
}