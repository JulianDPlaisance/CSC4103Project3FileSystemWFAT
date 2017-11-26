
/*

Your filesystem will provide:
a flat namespace (e.g., there is only a single root directory and no subdirectories) and
a set of file operations.

You may implement either a FAT or inode-based block allocation strategy for files, but
you must document which strategy is used.
       >>>>>>>>> We must choose which one to use! <<<<<<<<<<<<<

I will provide the implementation of a persistent "raw"
software disk (available via softwaredisk.h / softwaredisk.c), which supports reads/writes
of fixed-sized blocks (numbered 0..software_disk_size() - 1).

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


int main() {

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
	scanf(fname);
	create_file(fname, READ_WRITE);

	//When done writing, needs to allocate new space in FAT and write contents in that block
	void fbuf;
	write_file(fname, fbuf, 512);
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
	write_file(fname, fbuf, 512);
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
