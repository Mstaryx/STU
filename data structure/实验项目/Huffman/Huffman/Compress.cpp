#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Compress.h"
#include "Huffman.h"
#include "Test.h"

using namespace std;

string _s2;

int weight[256];//各字符所占权重
HNode huffmanTree[511];//哈夫曼树
HCode huffmanCode[256];//哈夫曼编码
vector <string> vstr;//每八位二进制字符串
vector<unsigned char> vbyte;//每八位字符串对应字节
int add = 0; // 补零个数

// [功能]：执行压缩
void Compress(string fileName) {
	ifstream fileIn;
	fileIn.open(fileName, ios::in | ios::binary);
	if (!fileIn.is_open()) {
		cout << "文件打开失败!" << endl;
		return;
	}
	cout << "压缩中...." << endl;
	memset(weight, 0, sizeof (weight));
	int ch = -1;
	while ((ch = fileIn.get()) != EOF) {
		weight[ch]++;
	}
	fileIn.close();
	//PrintWeight();
	MakeHuffmanTree(huffmanTree);
//	PrintHuffmanTree(root);
	EncodeHuffman();
//  PrintHuffmanCode(root);
	SuperTurnStringToByte(fileName);

	string newFileName = fileName + ".huf";
	ofstream fileOut;
	fileOut.open(newFileName, ios::out | ios::binary);
	if (!fileOut.is_open()) {
		cout<< "文件创建失败!" << endl;
		return;
	}

	//写入文件
	char header[4] = "HUF";
	fileOut.write(header, sizeof(char) * 4);
	fileOut.write((char*)weight, sizeof(int) * 256);  
	fileOut.write((char*)&add, sizeof(int));
	fileOut.write((char*)vbyte.data(), vbyte.size());
	fileOut.close();
//	PrintHeader(header, weight, add, vbyte);
	size_t preSize = CalcFileSize(fileName);
	size_t afterSize = CalcFileSize(newFileName);
	cout << "压缩完成!" << endl;
    cout << "压缩前大小：" << preSize << "字节" << endl;
    cout << "压缩后大小：" << afterSize << "字节" << endl;
	cout << "压缩比率：" << setprecision(6) << (double)afterSize / preSize * 100 << "%" << endl;

}

// [功能]: 将字符串拆分成每八位一组
void SplitString(string s){
	int n = s.length();
	if (n % 8 == 0) add = 0;
	else add = 8 - n % 8;
	for (int i = 0; i < add; i++){
		s += "0";
	}
	int m = s.length() / 8;
	for (int i = 0; i < m; i++){
		vstr.push_back(s.substr(i * 8, 8));
	}
}

// [功能]: 将字符串转换为字节
void SuperTurnStringToByte(string fileName) {
	ifstream fileIn;
	fileIn.open(fileName, ios::in | ios::binary);
	int ch = -1;
	string res = "";
	while ((ch = fileIn.get()) != EOF) {
		res += huffmanCode[ch].code;
		while ((int)res.length() > 8) {
			string tmp = res.substr(0, 8);
			int num = 0;
			for (int i = 0; i < 8; i++) {
				num <<= 1;
				if (tmp[i] == '1') num++;
			}
			vbyte.push_back(num);
			res = res.substr(8, (int)res.length() - 8);
		}
	}
	fileIn.close();
	int n = res.length();
	if (n % 8 == 0) add = 0;
	else add = 8 - n % 8;
	for (int i = 0; i < add; i++) {
		res += "0";
	}
	if ((int)res.length() == 8) {
		int num = 0;
		for (int i = 0; i < 8; i++) {
			num <<= 1;
			if (res[i] == '1') num++;
		}
		vbyte.push_back(num);
	}
}

// [功能]: 计算文件大小
size_t CalcFileSize(string fileName) {
	ifstream fileIn;
	fileIn.open(fileName, ios::binary | ios::ate);
	if (!fileIn.is_open()) {
		cout << "文件打开失败!" << endl;
		exit(0);
	}
	size_t size = fileIn.tellg();
	fileIn.close();
	return size;
}



