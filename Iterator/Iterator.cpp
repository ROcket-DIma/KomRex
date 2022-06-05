#include <iostream>
#include "Iterator.h"

/*
	unsigned int GetPosition();
	void MyPosition(unsigned long position);
	void UPosition(unsigned long count);
	void Zero();
	void Next();
	void End();
	bool Never();
	virtual bool CurrPosition(byte *dataBuffer);*/

     Iterator::Iterator(){}


	Iterator::Iterator(FileSystem file){
	 File=file;
	 end=File.CountClust;
	 Zero();
	 End();

	}

	unsigned int Iterator::GetPosition(){
	  return Position;
	}

	void Iterator::MyPosition(unsigned long position){
		if (position<end)
		Position=position;
	}


	void Iterator::UPosition(unsigned long count){
		if(Position+count<=end && count>0)
		Done=Position+count-1;
	}

	void Iterator::Zero(){
       Position=0;
	}

    void Iterator::Next(){
	  Position++;
	}

	void Iterator::End(){
      Done=end;
	}

	bool Iterator::Never(){
	return(Position>Done);
	}

	bool Iterator::CurrPosition(byte *dataBuffer){
	return File.ReadCluster(Position,dataBuffer);
	}





