#include<iostream>
#include<string>

#include "Compress.h"
#include "DeCompress.h"

using namespace std;
int main() {
	cout << "= = = =Huffman�ļ���ѹ��= = = =" << endl;
	cout << "��������Ҫѡ��Ĺ���(1:ѹ����2����ѹ��):";
	int op = 0;
	cin >> op;
	string fileName;
	switch (op) {
		case 1:
			cout << "������ѹ���ļ�·��:";
			cin >> fileName;
			cout << "����ѹ������" << endl;
			Compress(fileName);
			break;
		case 2:
			cout << "�������ѹ���ļ�·��:";
			cin >> fileName;
			cout << "������ѹ����" << endl;
			DeCompress(fileName);
			break;
		default:
			cout << "������������" << endl;
	}
	return 0;
}