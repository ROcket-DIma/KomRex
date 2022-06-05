#include <tchar.h>
#include <windows.h>
#include "NTFS.h"
#include "FAT32.h"
#include "NON.h"

enum FS {Rntfs , Rfat32, ENON};

class Factory
{
public:
	Factory();
	FileSystem CaseFS(wchar_t* path);
private:
	FS GetFS(byte *dataBuffer);
};


