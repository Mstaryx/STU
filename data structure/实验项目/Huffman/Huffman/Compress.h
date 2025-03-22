#pragma once

#include <string>
#include <vector>

#include "Huffman.h"

using namespace std;

extern int weight[256];
extern HNode huffmanTree[511];
extern HCode huffmanCode[256];
extern vector <string> vstr;
extern vector<unsigned char> vbyte;


void Compress(string fileName);
void SplitString(string s);
void TurnStringToByte();
string MergeHuffmanCode(string fileName);
void CommonTurnStringToByte(string fileName);
void SuperTurnStringToByte(string fileName);
size_t CalcFileSize(string fileName);

