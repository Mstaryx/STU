#include "Tourism.h"
#include "Graph.h"
#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;
void ClearScreen() {
	cout << endl;
	cout << "输入任意键继续...";
	char ch;
	ch = getchar();
	ch = getchar();
	system("cls");
}
void Navigate(Graph& G) {
	int startNode = 0;
	cout << "= = = =旅游景点导航= = = =" << endl;
	ShowNode(G);
	cout << "请输入起始点编号：";
	cin >> startNode;
	if (!is_valid(startNode)) {
		return;
	}
	vector<int>visited(G.VexNum, 0);
	vector<int>pathList;
	pathList.push_back(startNode);
	visited[startNode] = 1;
	int count = 1;
	cout << "导游路线为：" << endl;
	DSP(G, startNode, pathList, visited, count);
	cout << "over!" << endl;
	ClearScreen();
}
void SearchClosest(Graph&G) {
	cout << "= = = =搜索最短路径= = = =" << endl;
	ShowNode(G);
	int from, to;
	int count = 0;
	cout << "请输入起点编号：";
	cin >> from;
	cout << "请输入终点编号：";
	cin >> to;
	if (!is_valid(from, to)) {
		return;
	}
	vector<bool>visited(G.VexNum, false);
	cout << "最短路径为：" << G.vexs[from].name;
	DIJ(G,from,to,visited,from,count);
	cout << endl;
	cout << "最短距离为：" << count << endl;
	cout << "over!";
	ClearScreen();
}
void DesignPath(Graph& G) {
	cout << "= = = =铺设电路规划= = = =" << endl;
	if (!is_valid()) {
		return;
	};
	vector<bool>visited(G.VexNum, false);
	vector<int>dist(G.VexNum,INT_MAX);
	visited[0] = true;
	cout << "在以下两个景点之间铺设电路:" << endl;
	MiniTree(G,visited,dist);
	cout << "over!";
	ClearScreen();
}