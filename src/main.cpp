#include <iostream>

#include "config.h"
#include "clocker.h"

const char *CONFIG_FILE_NAME = ".clocker";

int main()
{
	Config config(CONFIG_FILE_NAME);

	config.last_user = "Konnor";

	config.save(CONFIG_FILE_NAME);

	return 0;
}
