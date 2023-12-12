#ifndef I_DATA_VALIDATOR_H

#include "Data.h"

#define I_DATA_VALIDATOR_H

class IDataValidator
{
public:

	virtual bool ValidateData(Data& inputData) = 0;
};

#endif