#include "NTFS.h"

NTFS::NTFS(wchar_t* path)
	{
	byte *dataBuffer = new byte[512];

	if(ReadBR(path,dataBuffer))
	{
		NTFS_BR* pNTFS_BR = (NTFS_BR*)dataBuffer;

		int ByteSec=Get16(pNTFS_BR->ByteSec,sizeof(pNTFS_BR->ByteSec));

		int SecClust=Get16(&pNTFS_BR->SecClust,sizeof(pNTFS_BR->SecClust));

		unsigned long long TotalSector=Get16(pNTFS_BR->TotalSector,sizeof(pNTFS_BR->TotalSector));

        name="NTFS";
		ClustSize=SecClust*ByteSec;
		CountClust=TotalSector/SecClust;
		size=ClustSize*CountClust/(1024*1024*1024);

	}

	delete[] dataBuffer;
	}

	/*
    	byte Padding1[0x0B];
	byte ByteSec[2];
	byte SecClust;
	byte Padding2[26];
	byte TotalSector[8];*/

