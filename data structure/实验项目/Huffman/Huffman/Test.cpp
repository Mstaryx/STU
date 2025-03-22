#include <iostream>
#include <string>

#include "Huffman.h"
#include "Compress.h"
#include "Test.h"

using namespace std;

// [功能]：打印权重
void PrintWeight() {
	cout << "源文件每个字符的权值为:" << endl;
	cout << "Byte " << "Weight" << endl;
	for (int i = 0; i < 256; i++) {
		printf("0x%02X %d\n", i, weight[i]);
	}
}

// [功能]：打印Huffman树
void PrintHuffmanTree() {
	cout << "Huffman树每个节点信息为:" << endl;
	printf("%14s\t%s\t%s\t%s\t%s\n",
		"Byte",
		"Weight",
		"Parent",
		"Lchild",
		"Rchild");

	for (int i = 0; i < 511; i++)
	{
		printf("HuffmanTree[%d] %d\t%d\t%d\t%d\n", i, huffmanTree[i].weight, huffmanTree[i].parent,
			huffmanTree[i].lchild, huffmanTree[i].rchild);
	}
}

// [功能]：先序遍历Huffman树
void PrintHuffmanTree(int u){
	if (u == root) {
		cout << "Huffman树先序遍历节点信息为:" << endl;
		printf("%14s\t%s\t%s\t%s\t%s\n",
			"Byte",
			"Weight",
			"Parent",
			"Lchild",
			"Rchild");
	}
	printf("HuffmanTree[%d] %d\t%d\t%d\t%d\n", u, huffmanTree[u].weight, huffmanTree[u].parent,
		huffmanTree[u].lchild, huffmanTree[u].rchild);
	if (huffmanTree[u].lchild != -1) {
		PrintHuffmanTree(huffmanTree[u].lchild);
	}
	if (huffmanTree[u].rchild != -1) {
		PrintHuffmanTree(huffmanTree[u].rchild);
	}
}

// [功能]: 打印每个字符的Huffman编码
void PrintHuffmanCode(int u) {
	cout << "Huffman编码为:" << endl;
	cout << "Byte " << "Weight " << "Code" << endl;
	for (int i = 0; i < 256; i++) {
		printf("0x%02X %d ", i,huffmanCode[i].weight,huffmanCode[i].code);
		cout<<huffmanCode[i].code<<endl;
	}
}

// [功能]: 打印分割出的二进制字符串
void Printvstr() {
	cout << "分割出的二进制字符串为:" << endl;
	for (auto s : vstr) {
		cout << s << endl;
	}
}

// [功能]: 打印分割出的字节
void Printvbyte() {
	cout<<"分割出的字节为:"<<endl;
	for (auto x : vbyte) {
		cout << (int)x << endl;
	}
}

// [功能]: 打印文件头
void PrintHeader(char* header, int weight[], int& add, vector<unsigned char>& vbyte) {
	cout << header << endl;
	for (int i = 0; i < 256; i++) {
		cout << weight[i] << " ";
	}
	cout << endl;
	cout << add << endl;
	/*for (auto v : vbyte) {
		cout << (int)v << " ";
	}*/
	cout << endl;
}
