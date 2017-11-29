
/*
Your goal is to wrap a higher level filesystem interface around my software disk.
It is your responsibility to allocate blocks for file allocation, the directory structure, and file data.
You may use any sensible technique for tracking free disk blocks.

Further requirements:
• You must provide a file system initialization program called formatfs.c which initializes
your file system. Part of this initialization will including initializing the software disk via
init_software_disk(), which destroys all existing data.
• Your filesystem must handle out of space errors (e.g., operations which overflow the
capacity of the software disk) and set appropriate error conditions.
• Your filesystem must allow filenames of at least 255 characters in length, composed of
printable ASCII characters.
• Your filesystem must provide the filesystem.h interface.
*/

#include <stdio.h>
#include "filesystem.h"
#include "formatfs.c"



// read at most 'numbytes' of data from 'file' into 'buf', starting at the
// current file position.  Returns the number of bytes read. If end of file is reached,
// then a return value less than 'numbytes' signals this condition. Always sets
// 'fserror' global.

unsigned long read_file(File file, void *buf, unsigned long numbytes) {


if (/*itexists*/)
	return 1;
else
	return 0;
}

// write 'numbytes' of data from 'buf' into 'file' at the current file position.
// Returns the number of bytes written. On an out of space error, the return value may be
// less than 'numbytes'.  Always sets 'fserror' global.

unsigned long write_file(File file, void *buf, unsigned long numbytes) {


	//We should have an additional block for every 512 bytes plus 1(maybe 2) for remaining data
	int numberOfBlocks = (numbytes / SOFTWARE_DISK_BLOCK_SIZE) + 1;

//The return value of write_file ****must**** be used to check for out of space errors!
if (/*itexists*/)
	return 1;
else
	return 0;
}

// sets current position in file to 'bytepos', always relative to the beginning of file.
// Seeks past the current end of file should extend the file. Always sets 'fserror'
// global.
void seek_file(File file, unsigned long bytepos) {

	bytepos = /*currentpos*/;

	if(bytepos > /*eof*/)
		//extend (concatenate) it

if (/*itexists*/)
	fserror = FS_NONE;
else
	fserror = FS_FILE_NOT_FOUND;
}

// deletes the file named 'name', if it exists and if the file is closed.
// Fails if the file is currently open. Returns 1 on success, 0 on failure.
// Always sets 'fserror' global.
int delete_file(char *name) {

int success = 0;

  if (file_exists(*name) == 1) {
	  if (checkMode(*name) != 0 | 1){

		  //Remove pointers to name and data from FAT


		  success = 1;
	  }
  }

 if (file_exists(*name) == 0)
	 fserror = FS_FILE_NOT_FOUND;
 if (checkMode(*name) == 0 | 1)
	 fserror = FS_FILE_OPEN;

if (success == 1)
	{return 1; fserror = FS_NONE}
else
	{return 0;}
}

// determines if a file with 'name' exists and returns 1 if it exists, otherwise 0.
// Always sets 'fserror' global.
int file_exists(char *name) {

int exists = 0;
void *bufrr;

//search FAT (block 0) for name; check every 2nd block's pointer data
for (int srch = 0; srch <= 512; (srch+1)++ ){

	// reads a block of data into 'bufrr' from FAT.
	read_sd_block(*bufrr, 0);

	//Reads a pointer to name data from FAT
    bufrr[srch] = //pointer here

    //If this pointer's data is the same as *name, it exists
    if (/*pointer*/ == *name)
    	exists = 1;
    }

if (exists = 1)
	return 1;
else
	return 0;
}




int main() {


printf("Welcome to our 4101 Filesystem. Our format is FAT. \n")


//Keeping track of the number of files to know which block to write to
int numFiles = 0;

char input[99];

printf("To create a file, type 1. \n");
printf("To open an existing file, type 2. \n");
printf("To delete a file, type 3. \n");
printf("To exit, type 4. \n");
printf("Hit Enter after your selection. \n\n");

scanf(input);

switch (input)

case 1: {
	char fname[256];
	printf("Please enter the name of the file to create:");

	//Place input into a file buffer
	void *fbuf = scanf(fname);

	//Creating the file with its name and in READ_WRITE state to edit immediately
	create_file(fname, READ_WRITE);

	//Writing the file contents to the new file's block location, based on current number of files
	write_file(fname, *fbuf, ++numFiles);

	//When done writing, needs to allocate new space in FAT and write contents in that block
	void *fatBuf[512] = numFiles;
	write_sd_block(fatBuf, 0);   //consider concatenating, if possible?

	//Perhaps use the contents of "fbuf" above and copy that into the block?


	close_file(fname);
}
	break;
case 2: {
	char fname[256];
	printf("Please enter the name of the file to open: ");
	scanf(fname);

	//Checking whether file exists

	if (file_exists(fname) == 0) {
		printf("File does not exist.");
		break;
	}

	open_file(fname, READ_WRITE);

	//When done writing, needs to find the allocated space and overwrite all contents in that block
	void fbuf;
	write_file(fname, fbuf, 0); //Replace 0 with block location mentioned in fat!

	//Perhaps use the contents of "fbuf" above and copy that into the block?
	//The return value of write_file ****must**** be used to check for out of space errors!

	close_file(fname);
}
	break;
case 3: {
	char fname[256];
	printf("Please enter the name of the file to delete: ");
	scanf(fname);

	//Deletion user confirmation
	printf("Deleting file '");
	printf(fname);
	printf("'. Are you sure? y/n \n");
	char choice;
	scanf(choice);

	if (choice == 'y') {

		//Deletes file and mentions error upon success or failure
		delete_file(fname);
		if (fserror == 0)
			printf("Error deleting file. \n");
		else
           printf("File deleted.");
	}
	else if (choice == "n")
		printf("Ok, no action was taken. \n");
	else
		printf("Invalid input, no action was taken. \n");

main();
}
	break;
case 4:
	break;
default: { printf("Invalid choice. Please try again.");

	main();
}

printf("Closing filesystem...")

return 0;
}
