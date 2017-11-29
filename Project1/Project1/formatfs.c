
/*

You must provide a file system initialization program called formatfs.c which initializes
your file system. Part of this initialization will including initializing the software disk via
init_software_disk(), which destroys all existing data.

*/



#include "softwaredisk.c"
#include <time.h>
#include <stdlib.h>


int init_software_disk() {
	const int size = software_disk_size();

	sderror = SD_NONE;

	srand(time(NULL));                          //sets random seed
	int rand = rand() % size;  //keeps number within disk bounds

//creates a buffer the size of software disk
//and populates with 0

	void * bufr[size] = { 0 };

	//writes 0's over every block in the software disk

	for (int softi = 1; softi <= size; softi++) {
		write_sd_block(bufr, size);
	}


	//reading from a random block to determine if it was properly zeroed

	if (read_sd_block(bufr, rand) == 0) {
		sd_print_error();
		return 1;
	}
	else {   //Returns errors due to failure to initialize
		sderror = SD_NOT_INIT;
		sd_print_error();
		printf(" - formatfs.c error");
	}
	return 0;
}


int main() {


	//Do file system initialization

	init_software_disk();


	//Return 0 if the sderror is not SD_NONE, indicating a failure

	if (sderror == SD_NONE) {
		return 1;
	}
	else
		return 0;
}
