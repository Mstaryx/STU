#include "Tourism.h"
#include "Graph.h"
#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;
void ClearScreen() {
	cout << endl;
	cout << "�������������...";
	char ch;
	ch = getchar();
	ch = getchar();
	system("cls");
}
void Navigate(Graph& G) {
	int startNode = 0;
	cout << "= = = =���ξ��㵼��= = = =" << endl;
	ShowNode(G);
	cout << "��������ʼ���ţ�";
	cin >> startNode;
	if (!is_valid(startNode)) {
		return;
	}
	vector<int>visited(G.VexNum, 0);
	vector<int>pathList;
	pathList.push_back(startNode);
	visited[startNode] = 1;
	int count = 1;
	cout << "����·��Ϊ��" << endl;
	DSP(G, startNode, pathList, visited, count);
	cout << "over!" << endl;
	ClearScreen();
}
void SearchClosest(Graph&G) {
	cout << "= = = =�������·��= = = =" << endl;
	ShowNode(G);
	int from, to;
	int count = 0;
	cout << "����������ţ�";
	cin >> from;
	cout << "�������յ��ţ�";
	cin >> to;
	if (!is_valid(from, to)) {
		return;
	}
	vector<bool>visited(G.VexNum, false);
	cout << "���·��Ϊ��" << G.vexs[from].name;
	DIJ(G,from,to,visited,from,count);
	cout << endl;
	cout << "��̾���Ϊ��" << count << endl;
	cout << "over!";
	ClearScreen();
}
void DesignPath(Graph& G) {
	cout << "= = = =�����·�滮= = = =" << endl;
	if (!is_valid()) {
		return;
	};
	vector<bool>visited(G.VexNum, false);
	vector<int>dist(G.VexNum,INT_MAX);
	visited[0] = true;
	cout << "��������������֮�������·:" << endl;
	MiniTree(G,visited,dist);
	cout << "over!";
	ClearScreen();
}