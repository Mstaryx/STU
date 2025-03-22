#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
#include"Tourism.h"
#include <iostream>
using namespace std;
int main()
{
	int status =  1;
	Graph G;
	while (status!= 0)
	{
		//initGraph(G);
		
		cout<<"= = = =景区管理系统= = = =\n";
		cout<<"1.创建景区景点图\n";
		cout<<"2.查询景点信息\n";
		cout<<"3.旅游经典导航\n";
		cout<<"4.搜索最短路径\n";
		cout<<"5.铺设电路规划\n";
		cout<<"0.退出系统\n";
		cout<<"请输入选项：";
		cin>>status;
		switch (status)
		{
			case 1:
			{
				CreateGraph(G);
				break;
			}
			case 2: {
				QueryInfo(G);
				break;
			}
			case 3: {
				Navigate(G);
				break;
			}
			case 4: {
				SearchClosest(G);
				break;
			}
			case 5: {
				DesignPath(G);
				break;
			}
			case 0: {
				cout << "exit!" << endl;
				return 0;
			}
			default: {
				cout << "input error!" << endl;
				system("pause");
				system("cls");
			}

		}
	}
}