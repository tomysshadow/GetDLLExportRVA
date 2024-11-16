#define _WIN32_WINNT 0x0500
#include <iostream>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char** argv) {
	const int MIN_ARGC = 3;

	if (argc < MIN_ARGC) {
		std::cerr << "Usage: GetDLLExportRVA dll export" << std::endl;
		return GetLastError();
	}

	const char* libFileName = argv[1];

	HMODULE moduleHandle = LoadLibraryA(libFileName);

	if (!moduleHandle) {
		std::cerr << "There was a problem starting " << libFileName << "." << std::endl;
		return GetLastError();
	}

	const char* procName = argv[2];

	if (*procName == '#') {
		unsigned long ordinal = strtoul(procName + 1, 0, 10);

		procName = MAKEINTRESOURCEA(ordinal);
	}

	std::cout << std::showbase << std::hex << ((size_t)GetProcAddress(moduleHandle, procName) - (size_t)moduleHandle) << std::endl;
	return GetLastError();
}