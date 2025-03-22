#include "Graph.h"
#include"Tourism.h"
#include <iostream>
using namespace std;
int total = 0;
int No = 0;

void initGraph(Graph& G) {
    G.vexs.resize(G.VexNum);
    //G.edges.resize(G.VexNum);
    G.adjMatrix.resize(G.VexNum, vector<int>(G.VexNum, 0));
}
//创建图
void CreateGraph(Graph&G) {
    cout << "start..." << endl;
    ifstream fileIn;
    fileIn.open("D:\\Vex.txt",ios::in);
    if (!fileIn.is_open()) {
        cout << "open failed";
        exit(0);
    }
    string str_to;
    getline(fileIn, str_to);
    total = stoi(str_to);
    G.VexNum = total;
    initGraph(G);
    for (int i = 0; i < G.VexNum; i++) {
        getline(fileIn, str_to);
        No= stoi(str_to);
        getline(fileIn, G.vexs[i].name);
        getline(fileIn, G.vexs[i].desc);
    }
    fileIn.close();
    
    fileIn.open("D:\\Edge.txt", ios::in);
    if (!fileIn.is_open()) {
        cout << "open failed";
        exit(0);
    }
    int from, to, dis;
    while (fileIn >> from >> to >> dis) {
        G.adjMatrix[from][to] = dis;
        G.adjMatrix[to][from] = dis;
    }
    fileIn.close();
    ShowNode(G);
    cout << "over!";
    ClearScreen();
}
void QueryInfo(Graph& G) {
    cout << "= = = = 查询景点信息 = = = = " << endl;
    ShowNode(G);
    cout << "请输入想要查询的景点编号:";
    int op; cin >> op;
    cout << "景点编号为 " << op << " 的景点信息如下：" << endl;
    if (!is_valid(op)) {
        return;
    };
    cout << G.vexs[op].name << endl;
    cout << G.vexs[op].desc << endl;
    cout << "- - - - 周边景区 - - - -" << endl;
    for (int j = 0; j < total; j++) {
        if (j != op && G.adjMatrix[op][j]) {
            cout << G.vexs[op].name << "-->" << G.vexs[j].name << "距离为：" << G.adjMatrix[op][j] << endl;
        }
    }
    cout << "over!";
    ClearScreen();
}
//导览
void DSP(Graph& G, int startNode, vector<int>pathList,vector<int>visited,int &count) {
    for (int j = 0; j < G.VexNum; j++) {
        if (G.adjMatrix[startNode][j] && !visited[j]) {
            visited[j] = 1;
            pathList.push_back(j);
            DSP(G, j, pathList, visited,count);
            visited[j] = 0;
            pathList.pop_back();
        }
    }
    if (pathList.size()==G.VexNum){
        cout << "路线" << count << ":" << G.vexs[pathList[0]].name;
        for (int i = 1; i < pathList.size(); i++)
        {
            cout << " -> " << G.vexs[pathList[i]].name;
        }
        count++;
        cout << endl;
    }
}
//最短路径
void DIJ(Graph& G, int from, int to, vector<bool>visited,int& minipos,int&count ) {
    vector<int>miniPath(G.VexNum, INT_MAX);
    for (int i = 0; i < G.VexNum; i++) {
        if (G.adjMatrix[from][i] && !visited[i]) {
            miniPath[i] = min(miniPath[i], count+G.adjMatrix[from][i]);
            if (miniPath[i] < miniPath[minipos])
                minipos = i;
        }
    }
    visited[minipos] = true;
    count += G.adjMatrix[from][minipos];
    cout << "->" << G.vexs[minipos].name;
    if (visited[to])
        return;
    else
    {
        DIJ(G, minipos, to, visited, minipos, count);
    }

}
//最小生成树
void MiniTree(Graph& G, vector<bool>&visited, vector<int>&dist) {
    dist[0] = 0;
    vector<int>from_pos(G.VexNum, 0);
    int res = 0;
    //用0开始初始化dist
    for (int i = 1; i < G.VexNum; i++){
        dist[i] = min(dist[i], G.adjMatrix[0][i]);
    }
    for (int i = 1; i < G.VexNum; i++) {
        int mini = INT_MAX;
        int to = -1;
        for (int j = 0; j < G.VexNum; j++) {
            if (!visited[j] && mini > dist[j]&&dist[j]) {
                mini = dist[j];
                to = j;
            }
        }
        if (to != -1) {
            visited[to] = true;
            cout << G.vexs[from_pos[to]].name << " - " << G.vexs[to].name << "  " << mini << endl;
            res += mini;
        }
        for (int i = 0; i < G.VexNum; i++) {
            if (!visited[i] && G.adjMatrix[to][i] && (dist[i] > G.adjMatrix[to][i]||!dist[i]))
            {
                dist[i] = G.adjMatrix[to][i];
                from_pos[i] = to;
            }
        }
    }
    cout << "铺设电路的总长度为：" << res << endl;
}
void ShowNode(Graph& G) {
    for (int i = 0; i < G.VexNum; i++) {
        cout << i << "-" << G.vexs[i].name << endl;
    }
}
bool is_valid(int from,int to) {
    if (from < 0 || from >= total|| to < 0 || to >= total) {
        cout << "输入的景点编号不存在，请重新输入！" << endl;
        system("pause");
        system("cls");
        return false;
    }
    return true;
}