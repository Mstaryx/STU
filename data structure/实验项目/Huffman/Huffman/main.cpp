#include<iostream>
#include<string>

#include "Compress.h"
#include "DeCompress.h"

using namespace std;
int main() {
	cout << "= = = =Huffman文件解压缩= = = =" << endl;
	cout << "请输入您要选择的功能(1:压缩，2：解压缩):";
	int op = 0;
	cin >> op;
	string fileName;
	switch (op) {
		case 1:
			cout << "请输入压缩文件路径:";
			cin >> fileName;
			cout << "启动压缩程序！" << endl;
			Compress(fileName);
			break;
		case 2:
			cout << "请输入解压缩文件路径:";
			cin >> fileName;
			cout << "启动解压程序！" << endl;
			DeCompress(fileName);
			break;
		default:
			cout << "您的输入有误！" << endl;
	}
	return 0;
}