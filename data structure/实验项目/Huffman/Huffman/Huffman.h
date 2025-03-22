#pragma once

#include <string>
using namespace std;

const int root = 510;

// HuffmanÊ÷½Úµã
typedef struct HNode {
	int weight;
	int parent;
	int lchild;
	int rchild;
	HNode(int w = 0, int p = -1, int l = -1, int r = -1) {
		this->weight = w;
		this->parent = p;
		this->lchild = l;
        this->rchild = r;
	}
};

// Huffman±àÂë
typedef struct HCode{
	int weight;
	string code;
	HCode(int w = 0,string s = ""){
		this->weight = w;
		this->code = s;
	}
};


void MakeHuffmanTree(HNode huffmanTree[]);
int FindMinNode(int n, HNode huffmanTree[]);
void EncodeHuffman();
void MakeHuffmanCode(int u, string code);

