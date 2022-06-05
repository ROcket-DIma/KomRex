#include <tchar.h>
#include <windows.h>

#include "Decorator.h"

class ZDecorator : public Decorator
{
public:
	ZDecorator(Iterator iterator);
	bool CurrPosition(byte *dataBuffer) override;

};



