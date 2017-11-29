
/*

You must provide a file system initialization program called formatfs.c which initializes
your file system. Part of this initialization will including initializing the software disk via
init_software_disk(), which destroys all existing data.

*/

#include "softwaredisk.h"
#include <time.h>
#include <stdlib.h>


int main(){


//Do file system initialization

init_software_disk();


//Return 0 if the sderror is not SD_NONE, indicating a failure

if (sderror==SD_NONE)
	return 1;
else
	return 0;
}
