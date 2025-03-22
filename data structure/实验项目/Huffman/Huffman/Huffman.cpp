#include <string>
#include <iostream>

#include "Huffman.h"
#include "Compress.h"

using namespace std;

// [����]��������������
void MakeHuffmanTree(HNode huffmanTree[]) {
	for (int i = 0; i < 256; i++) {
		huffmanTree[i].weight = weight[i];
		huffmanTree[i].parent = -1;
	}

	for (int i = 256; i < 511; i++) {
		int id1 = -1, id2 = -1;
		id1 = FindMinNode(i, huffmanTree);
		huffmanTree[id1].parent = i;
		id2 = FindMinNode(i, huffmanTree);
		huffmanTree[id2].parent = i;


		//�ϲ�������Сֵ�������½ڵ�
		huffmanTree[i] = HNode(huffmanTree[id1].weight + huffmanTree[id2].weight, -1, id1, id2);
	}

}

// [����]������Ȩ����С�Ľڵ�
// n:��ǰ�ڵ���
int FindMinNode(int n, HNode huffmanTree[]) {
	int minValue = 1e8;
	int minPos = -1;
	for (int i = 0; i < n; i++) {
		if (huffmanTree[i].parent != -1) {
			continue;
		}
		if (huffmanTree[i].weight < minValue) {
			minValue = huffmanTree[i].weight;
			minPos = i;
		}
	}
	return minPos;
}

// [����]: ��ʼ����
void EncodeHuffman() {
	MakeHuffmanCode(root, "");
}

// [����]: ��������������
// u:��ǰ�ڵ�
// code:��ǰ����
void MakeHuffmanCode(int u, string code) {
	if (huffmanTree[u].lchild == -1 && huffmanTree[u].rchild == -1){
		huffmanCode[u] = HCode(huffmanTree[u].weight, code);
		return;
	}

	if (huffmanTree[u].lchild != -1) {
		MakeHuffmanCode(huffmanTree[u].lchild, code + "0");
	}

	if (huffmanTree[u].rchild != -1) {
		MakeHuffmanCode(huffmanTree[u].rchild, code + "1");
	}
}


