#include "NewFS.h"

/*
	bool ReadBR(wchar_t* path,BYTE *dataBuffer);
	bool ReadFH(wchar_t* path);
	bool ReadCluster(unsigned long long number, BYTE *dataBuffer);
	void ViewInfo(TLabel *Label);
	void ClosedHandle(); */

long FileSystem::Get16(byte vBootRecord[],int size){

	long sum=0;

	for (int i = 0; i < size; i++)
	{
		sum+=vBootRecord[i]*std::pow(16,i*2);
	}
	return sum;
}

bool FileSystem::ReadBR(wchar_t* path,BYTE *dataBuffer){

	 if(fileHander!=NULL)
        ClosedHandle();

	 if(ReadFH(path))
		if(ReadCluster(0,dataBuffer))
			return true;

     return false;
}

bool FileSystem::ReadFH(wchar_t* path){

    fileHander=CreateFileW(path,
	GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
		ClosedHandle();
		return false;
	}
	 return true;
	}

bool FileSystem::ReadCluster(unsigned long long number, BYTE *dataBuffer){

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=ClustSize*number;

	unsigned long long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
	 ShowMessage(L"Ошибка установки курсора. Try again :)");
	 return false;
	 }

	 DWORD bytesToRead=ClustSize;
	 DWORD bytesRead;

	 bool readResult = ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		 ShowMessage(L"Ошибка чтения кластера. Try again :)");
		 return false;
	 }
     return true;
	}

void FileSystem::ViewInfo(TLabel *Label){

		Label->Caption="Определена следующая информация о данном диске.";

		Label->Caption+="\nФайловая система: ";
		Label->Caption+=name;

		Label->Caption+="\nРазмер кластера в байтах: ";
		Label->Caption+=ClustSize;

		Label->Caption+="\nКоличество кластеров: ";
		Label->Caption+=CountClust;

		Label->Caption+="\nРазмер логического диска в Гб: ";
		Label->Caption+=size;
	}
void FileSystem::ClosedHandle(){
    CloseHandle(fileHander);
}

