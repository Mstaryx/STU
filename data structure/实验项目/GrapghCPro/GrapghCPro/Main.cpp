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
		
		cout<<"= = = =��������ϵͳ= = = =\n";
		cout<<"1.������������ͼ\n";
		cout<<"2.��ѯ������Ϣ\n";
		cout<<"3.���ξ��䵼��\n";
		cout<<"4.�������·��\n";
		cout<<"5.�����·�滮\n";
		cout<<"0.�˳�ϵͳ\n";
		cout<<"������ѡ�";
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