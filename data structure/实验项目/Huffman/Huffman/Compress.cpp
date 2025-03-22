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

int weight[256];//���ַ���ռȨ��
HNode huffmanTree[511];//��������
HCode huffmanCode[256];//����������
vector <string> vstr;//ÿ��λ�������ַ���
vector<unsigned char> vbyte;//ÿ��λ�ַ�����Ӧ�ֽ�
int add = 0; // �������

// [����]��ִ��ѹ��
void Compress(string fileName) {
	ifstream fileIn;
	fileIn.open(fileName, ios::in | ios::binary);
	if (!fileIn.is_open()) {
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "ѹ����...." << endl;
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
		cout<< "�ļ�����ʧ��!" << endl;
		return;
	}

	//д���ļ�
	char header[4] = "HUF";
	fileOut.write(header, sizeof(char) * 4);
	fileOut.write((char*)weight, sizeof(int) * 256);  
	fileOut.write((char*)&add, sizeof(int));
	fileOut.write((char*)vbyte.data(), vbyte.size());
	fileOut.close();
//	PrintHeader(header, weight, add, vbyte);
	size_t preSize = CalcFileSize(fileName);
	size_t afterSize = CalcFileSize(newFileName);
	cout << "ѹ�����!" << endl;
    cout << "ѹ��ǰ��С��" << preSize << "�ֽ�" << endl;
    cout << "ѹ�����С��" << afterSize << "�ֽ�" << endl;
	cout << "ѹ�����ʣ�" << setprecision(6) << (double)afterSize / preSize * 100 << "%" << endl;

}

// [����]: ���ַ�����ֳ�ÿ��λһ��
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

// [����]: ���ַ���ת��Ϊ�ֽ�
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

// [����]: �����ļ���С
size_t CalcFileSize(string fileName) {
	ifstream fileIn;
	fileIn.open(fileName, ios::binary | ios::ate);
	if (!fileIn.is_open()) {
		cout << "�ļ���ʧ��!" << endl;
		exit(0);
	}
	size_t size = fileIn.tellg();
	fileIn.close();
	return size;
}



