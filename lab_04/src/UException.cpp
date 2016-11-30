#include "UException.h"
#include <cstdio>
#include <string.h>

UException::UException(char* message)
{
    msg = new char[strlen(message) + 1];
	strcpy(msg, message);
}

UException::~UException()
{
    delete[] msg;
	msg = NULL;
}


void UException::show(void) {
	printf("%s\n", msg);
}
