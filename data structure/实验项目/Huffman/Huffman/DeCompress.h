#pragma once

#include <iostream>

#include "Huffman.h"

extern int weight[256];

void DeCompress(string fileName);

string restoreCode();

void WriteToFile(string newFileName, string& reCode);