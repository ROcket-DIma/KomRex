#include <iostream>
#include "Factory.h"


Factory::Factory()
{
}

FileSystem Factory::CaseFS(wchar_t* path)
{
	FileSystem File;
	FS fs=ENON;
	byte *dataBuffer = new byte[512];

	if(File.ReadBR(path, dataBuffer))
	{
	fs=GetFS(dataBuffer);
	}
	delete[]  dataBuffer;

	switch (fs){

	case(Rntfs):
		File=NTFS(path);
		break;

	case(Rfat32):
		File=FAT32(path);
		break;

	case(ENON):
		File=NON();
		break;
	}
	return  File;
}

FS Factory::GetFS(byte *dataBuffer)
{
	  byte ntfs[7]={235, 82, 144, 78, 84, 70, 83};
	  byte fat32[9]={235, 88, 144, 77, 83, 68, 79, 83, 53};

	   for(int i=0;i<sizeof(ntfs);i++)
	   {
		if(ntfs[i]!=dataBuffer[i])
		break;

		if(i==sizeof(ntfs)-1)
		return Rntfs;
	   }
		   for(int i=0;i<sizeof(fat32);i++)
	   {
		if(fat32[i]!=dataBuffer[i])
		break;

		if(i==sizeof(fat32)-1)
		return Rntfs;
	   }
		return ENON;

}
