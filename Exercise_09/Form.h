#ifndef FORM_H

#include "FormElement.h"

#define FORM_H

#include <vector>

class Form
{
private:

	std::vector<FormElement*> formElements;

public:

	void AddFormElement(FormElement& formElement);
};

#endif