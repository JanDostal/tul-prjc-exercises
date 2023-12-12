#ifndef FORM_ELEMENT_H

#include "Data.h"
#include "IAutoCompleter.h"
#include "IDataValidator.h"

#define FORM_ELEMENT_H

#include <vector>

class FormElement
{
private:

	std::vector<IDataValidator*> dataValidators;
	std::vector<IAutoCompleter*> autoCompleters;
	Data* data;

protected:

	FormElement(Data& _data);

public:

	void AddNewDataValidator(IDataValidator& dataValidator);
	void AddNewAutoCompleter(IAutoCompleter& autoComplete);
	
};

#endif