#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include "Unit1.h"

class Signature {
public:
	UnicodeString FSign(BYTE *dataBuffer);
private:
	bool CheckS(int pos,BYTE sign[],int length,BYTE *dataBuffer);
};

#endif
