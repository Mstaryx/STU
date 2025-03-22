#include <iostream>
#include <string>

#include "Huffman.h"
#include "Compress.h"
#include "Test.h"

using namespace std;

// [����]����ӡȨ��
void PrintWeight() {
	cout << "Դ�ļ�ÿ���ַ���ȨֵΪ:" << endl;
	cout << "Byte " << "Weight" << endl;
	for (int i = 0; i < 256; i++) {
		printf("0x%02X %d\n", i, weight[i]);
	}
}

// [����]����ӡHuffman��
void PrintHuffmanTree() {
	cout << "Huffman��ÿ���ڵ���ϢΪ:" << endl;
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

// [����]���������Huffman��
void PrintHuffmanTree(int u){
	if (u == root) {
		cout << "Huffman����������ڵ���ϢΪ:" << endl;
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

// [����]: ��ӡÿ���ַ���Huffman����
void PrintHuffmanCode(int u) {
	cout << "Huffman����Ϊ:" << endl;
	cout << "Byte " << "Weight " << "Code" << endl;
	for (int i = 0; i < 256; i++) {
		printf("0x%02X %d ", i,huffmanCode[i].weight,huffmanCode[i].code);
		cout<<huffmanCode[i].code<<endl;
	}
}

// [����]: ��ӡ�ָ���Ķ������ַ���
void Printvstr() {
	cout << "�ָ���Ķ������ַ���Ϊ:" << endl;
	for (auto s : vstr) {
		cout << s << endl;
	}
}

// [����]: ��ӡ�ָ�����ֽ�
void Printvbyte() {
	cout<<"�ָ�����ֽ�Ϊ:"<<endl;
	for (auto x : vbyte) {
		cout << (int)x << endl;
	}
}

// [����]: ��ӡ�ļ�ͷ
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
