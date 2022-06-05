#include <tchar.h>
#include <windows.h>

#include "NewFS.h"

class Iterator
{
protected:
	unsigned int Position;
	unsigned long long Done;
	unsigned long long end;
public:
	Iterator();
	Iterator(FileSystem file);

	FileSystem File;

	unsigned int GetPosition();
	void MyPosition(unsigned long position);
	void UPosition(unsigned long count);
	void Zero();
	void Next();
	void End();
	bool Never();
	virtual bool CurrPosition(byte *dataBuffer);
};


