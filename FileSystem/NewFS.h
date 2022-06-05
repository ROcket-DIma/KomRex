#pragma once
#include "Unit1.h"
#include <iostream>

class FileSystem {
protected:

	HANDLE fileHander;
	long Get16(byte vBootRecord[],int size);

public:
	unsigned long long size=512;
	unsigned long long CountClust=1;
	int ClustSize=512;
    String name;

	bool ReadBR(wchar_t* path,BYTE *dataBuffer);
	bool ReadFH(wchar_t* path);
	bool ReadCluster(unsigned long long number, BYTE *dataBuffer);
	void ViewInfo(TLabel *Label);
	void ClosedHandle();

};



