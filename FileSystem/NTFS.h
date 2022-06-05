#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include "NewFS.h"

class NTFS : public FileSystem
{
public:
	NTFS(wchar_t* path);
};

#pragma pack(push,1)

typedef struct
{
	byte Padding1[0x0B];
	byte ByteSec[2];
	byte SecClust;
	byte Padding2[26];
	byte TotalSector[8];
} NTFS_BR;

#pragma pack(pop)

#endif