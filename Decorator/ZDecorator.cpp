#include <iostream>
#include "ZDecorator.h"

Iterator Diterator;

	ZDecorator::ZDecorator(Iterator iterator){
		Diterator=iterator;
		File=iterator.File;
		end=File.CountClust;
		Zero();
		End();
	}


	bool ZDecorator::CurrPosition(byte *dataBuffer){
	if(Diterator.CurrPosition(dataBuffer))
		{
            for(int i=0;i<512;i++)
			{
			if(dataBuffer[i]!=0)
			   return true;
			}
			return false;

		}
	}






