#include "DeleteFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

DeleteFile::DeleteFile()
{
	if (remove("bids.txt") != 0)
		perror("Error deleting file");
	
	else
		puts("File successfully deleted");

	system("pause");
}