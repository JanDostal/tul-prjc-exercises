#ifndef I_AUTO_COMPLETER_H

#include "Data.h"

#define I_AUTO_COMPLETER_H

class IAutoCompleter
{
public:

	virtual Data* AutoCompleteData(Data& inputData) = 0;
};

#endif