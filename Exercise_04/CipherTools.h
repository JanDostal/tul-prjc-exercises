#ifndef CIPHER_TOOLS_H

#include "CipherToolsAbbreviations.h"

#define CIPHER_TOOLS_H

#define ARRAY_NOT_ALLOCATED_ERROR_CODE 1
#define ARRAYS_LENGTH_NOT_SAME_ERROR_CODE 2
#define ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE 3
#define ARRAY_NOT_FILLED_ERROR_CODE 4

P_CHAR createCharArray(int arrayLength);
int fillCharArray(P_CHAR existingCharArray);
int encodeCharArray(P_CHAR originalCharArray, P_PCHAR encodedCharArray);
int printEncodedCharArray(P_PCHAR encodedCharArray);

void displayCreateCharArrayMethodErrorMessage(P_CHAR createdCharArray);
void displayFillCharArrayMethodErrorMessage(int errorCode);
void displayEncodeCharArrayMethodErrorMessage(int errorCode);
void displayPrintEncodedCharArrayMethodErrorMessage(int errorCode);

#endif
