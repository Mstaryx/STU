#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>

#include "DeCompress.h"
#include "Huffman.h"
#include "Test.h"

using namespace std;

int newWeight[256];
HNode newHuffmanTree[511];
int newAdd = 0;


vector<unsigned char> newByte;

// [����]: ��ѹ�ļ�
void DeCompress(string fileName) {
    //�жϽ�ѹ�ļ���ʽ
    string tmp = fileName.substr(fileName.length() - 4, 4);
    if (tmp != ".huf") {
        cout << "�ļ���ʽ����!" << endl;
        return;
    }

	ifstream fileIn;
	fileIn.open(fileName, ios::in | ios::binary);
	if (!fileIn.is_open()) {
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "��ѹ��...." << endl;

    //��ȡ�ļ�
	char newHeader[4] = {};
	fileIn.read(reinterpret_cast<char*>(newHeader), sizeof(char) * 4);
    fileIn.read(reinterpret_cast<char*>(newWeight), sizeof(int) * 256);
    fileIn.read(reinterpret_cast<char*>(&newAdd), sizeof(int));
    char byte;
    while (fileIn.get(byte)) {
        newByte.push_back(static_cast<unsigned char>(byte));
    }
	fileIn.close();

    
//	PrintHeader(newHeader, newWeight, newAdd, newByte);
	memcpy(weight, newWeight, sizeof(int) * 256);
	MakeHuffmanTree(newHuffmanTree);          

    string reCode = restoreCode();

	string newFileName = fileName.substr(0, fileName.size() - 4);

    WriteToFile(newFileName, reCode);
   
    cout << "��ѹ�ɹ�!"<<endl;

}

// [����]: ����ѹ����ֽ���д���ļ�
void WriteToFile(string newFileName, string &reCode) {
    ofstream fileOut;
    fileOut.open(newFileName, ios::out | ios::binary);
    if (!fileOut.is_open()) {
        cout << "��������ļ����� " << endl;
        return;
    }
    int current = root;
    for (char b : reCode) {
        if (b == '0')  current = newHuffmanTree[current].lchild;
        else if (b == '1') current = newHuffmanTree[current].rchild;
        if (newHuffmanTree[current].lchild == -1 &&
            newHuffmanTree[current].rchild == -1) {
            char data = static_cast<char>(current);
            fileOut.put(data);
            current = root; // ���õ����ڵ�   
        }
    }

    fileOut.close();
}

// [����]: ���ֽ�����ԭΪ�ַ���
string restoreCode() {
	string reCode = "";
	for (unsigned char b : newByte) {
		bitset<8> bits(b);
		reCode += bits.to_string();
	}

	if (newAdd > 0 && reCode.size() >= newAdd) {
		reCode.resize(reCode.size() - newAdd);
	}

    return reCode;
}