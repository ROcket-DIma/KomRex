#ifdef _WIN32
#include <tchar.h>
#include <windows.h>

#include "NewFS.h"

class FAT32 : public FileSystem
{
public:
	FAT32(wchar_t* path);
};

#pragma pack(push,1)

typedef struct
{

	byte Padding1[0x0B];
	byte ByteSec[2];
	byte SecClust;
	byte Rezerv[2];
	byte FAT;
	byte Padding2[15];
	byte TotalSector[4];
	byte FATSize[4];


} FAT32_BR;

#pragma pack(pop)

#endif