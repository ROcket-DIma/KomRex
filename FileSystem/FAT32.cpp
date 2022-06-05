#include "FAT32.h"

FAT32::FAT32(wchar_t* path)
{
	byte *dataBuffer = new byte[512];

	if(ReadBR(path,dataBuffer))
	{
		FAT32_BR* pFAT32_BR = (FAT32_BR*)dataBuffer;

		int ByteSec=Get16(pFAT32_BR->ByteSec,sizeof(pFAT32_BR->ByteSec));

		int SecClust=Get16(&pFAT32_BR->SecClust,sizeof(pFAT32_BR->SecClust));

		int Rezerv=Get16(pFAT32_BR->Rezerv,sizeof(pFAT32_BR->Rezerv));

		int FAT=Get16(&pFAT32_BR->FAT,sizeof(pFAT32_BR->FAT));

		unsigned long long TotalSector=Get16(pFAT32_BR->TotalSector,sizeof(pFAT32_BR->TotalSector));

		unsigned long long FATSize=Get16(pFAT32_BR->FATSize,sizeof(pFAT32_BR->FATSize));


        name="FAT32";
		ClustSize=ByteSec*SecClust;
		CountClust=(TotalSector-FAT*FATSize-Rezerv)/SecClust;
		size=ClustSize*CountClust/(1024*1024*1024);
	}
	delete[] dataBuffer;
}

 /*
 	byte Padding1[0x0B];
	byte ByteSec[2];
	byte SecClust;
	byte Rezerv[2];
	byte FAT;
	byte Padding2[15];
	byte TotalSector[4];
	byte FATSize[4]; */


