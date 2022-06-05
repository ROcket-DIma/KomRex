#include "Signature.h"

UnicodeString Signature::FSign(BYTE *dataBuffer){

	byte sys[4]={255, 255, 255, 255};
	byte log[8]={42, 42, 42, 32, 32, 73, 110, 115};
	byte reg[7]={82, 69, 71, 69, 68, 73, 84};
	byte dat[4]={114, 101, 103, 102};

	if(dataBuffer[0]==sys[0])
		{if(CheckS(0,sys,4,dataBuffer))
			return "SYS, DOS system driver";
		}
	if(dataBuffer[0]==log[0])
		{if(CheckS(0,log,8,dataBuffer))
			return "LOG file";
		}

	if(dataBuffer[0]==reg[0])
		{if(CheckS(0,reg,7,dataBuffer))
			return "REG, WinNT Registry";
		}

	if(dataBuffer[0]==dat[0])
		{if(CheckS(0,dat,4,dataBuffer))
			return "DAT, WinNT registry file";
		}

	return "NON";
}

bool Signature::CheckS(int pos,BYTE sign[],int length,BYTE *dataBuffer){

	for(int j=0; j<length;j++)
	{
	  if(sign[j]!=dataBuffer[pos+j])
		return false;
	}
    return true;
}





