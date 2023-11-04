#ifndef INTEGRATION_TESTS_H

#include "CipherToolsAbbreviations.h"

#include <stdbool.h>

#define INTEGRATION_TESTS_H

#define TEST_SUCCESS true
#define TEST_FAILURE false
#define TESTS_COUNT 4

bool testCreateCharArray(int arrayLength);
bool testFillCharArray(P_CHAR existingCharArray);
bool testEncodeCharArray(P_CHAR originalCharArray, P_PCHAR encodedCharArray);
bool testPrintEncodedCharArray(P_PCHAR encodedCharArray);

#endif
