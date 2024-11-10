GetDLLExportRVA

	This command line tool outputs the RVA of a DLL Export. It loads the DLL specified in the first argument,
	and calls GetProcAddress on it with the Export specified in the second argument. If the output is
	empty, an error occured and the exit code is the last error code.
	
	
Usage: GetDLLExportRVA dll export