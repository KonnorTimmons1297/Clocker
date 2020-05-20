#include <iostream>

#include "config.h"
#include "clocker.h"

const char* CONFIG_FILE_NAME = ".clocker";

int main() {
	Config config;

	if ( !config.read(CONFIG_FILE_NAME) ) {
		config.create(CONFIG_FILE_NAME);
	}

	

	return 0;
}
