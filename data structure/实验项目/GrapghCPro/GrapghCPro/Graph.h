#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<fstream>
#include<climits>
#include<cmath>
using namespace std;
//struct Edge {
//    int from;
//    int to;
//    int dis;
//};
struct Vex {
    int num;
    string name;//√˚≥∆
    string desc;//æ∞µ„ΩÈ…‹
};
struct Graph {
    vector<Vex> vexs;
    //vector<Edge> edges;
    int VexNum;
    vector<vector<int>>adjMatrix;
};
void initGraph(Graph& G);
void CreateGraph(Graph& G);
void QueryInfo(Graph& G);
void DSP(Graph& G, int startNode, vector<int>pathList, vector<int>visited, int& count);
void DIJ(Graph& G, int from, int to, vector<bool>visited, int& minipos, int& count);
void ShowNode(Graph& G);
bool is_valid(int from=0, int to = 0);
void MiniTree(Graph& G, vector<bool>&visited, vector<int>&dist);