#include "filesystem.h"
#include "softwaredisk.c"
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

/*
checkMode is a helper function to take the enum of FileMode and convert it into an integer for simplifing if/switch statements
0 being READ_ONLY,
1 being READ_WRITE
-1 reserved for errors
*/
int checkMode(FileMode mode) {
	if (mode == READ_ONLY) {
		return 0;
	}
	else if(mode == READ_WRITE) {
		return 1;
	}
	else {
		return -1;
	}
}

/*
checkError is a helper function to take the enum of FSError and convert it into an integer for simplifing if/switch statements
0 being FS_NONE,
1 being FS_OUT_OF_SPACE
2 being FS_FILE_NOT_OPEN
3 being FS_FILE_OPEN
4 being FS_FILE_NOT_FOUND
5 being FS_FILE_READ_ONLY
6 being FS_FILE_ALREADY_EXISTS
-1 is reserved for errors... that aren't FSErrors
*/
int checkError(FSError error) {
	switch (error) {

	case FS_NONE:
		return 0;
		break;

	case FS_OUT_OF_SPACE:
		return 1;
		break;

	case FS_FILE_NOT_OPEN:
		return 2;
		break;

	case FS_FILE_OPEN:
		return 3;
		break;

	case FS_FILE_NOT_FOUND:
		return 4;
		break;

	case FS_FILE_READ_ONLY:
		return 5;
		break;

	case FS_FILE_ALREADY_EXISTS:
		return 6;
		break;

	default:
		return -1;
		break;
	}
}

/*
findFileExist is a helper function for both open_file & create_file functions to reduce redundant code
FileInternals *file is a pointer to an empty or null file object
int which tells this function which function is calling it, open_file is represented by 0 and create_file is represented by 1
char *name is a pointer to a character (array) representing the file name that the system has to search for, to create or open

The system searches for a file where file_name == *name and tries to set *tmp to this file if possible
If the system has found a file with filename == *name and open_file is calling it then sets *file to point to what *tmp points to
If the system has found a file with filename == *name and create_file is calling it then sets *file->err to FS_FILE_ALREADY_EXISTS
If the system fails to find a file where filename == *name and open_file is calling it then it sets *file->err to FS_FILE_NOT_FOUND
If the system fails to find a file where filename == *name and create_file is calling it then it sets *file to point to what *tmp points to
*/
void findFileExist(FileInternals *file, int which, char *name) {
	int found = 1;
	FileInternals *tmp;
	//stuff();
	
	if (found) {
		if (!which) {
			
		}
		else {
			file->err = FS_FILE_ALREADY_EXISTS;
		}
	}
	else {
		if (!which) {
			file->err = FS_FILE_NOT_FOUND;
		}
		else {
		}
	}
}

/*
This function searches the existing files for a filename == *name
and opens the file under FileMode, in either READ_ONLY or READ_WRITE
A FileInternals null pointer is created , then it calls findFileExist
if the FSError of the *file is FS_NONE then it continues to set the mode
for the file 
*/
File open_file(char *name, FileMode mode) {
	FileInternals *file;
	findFileExist(file, 0, name);

	if (checkMode(mode)) {
		
	}
	else {

	}
	return 0;
}

File create_file(char *name, FileMode mode) {
	FileInternals *file;
	findFileExist(file, 1, name);
	return 0;
}

void close_file(File file) {
	//not sure how this exactly works, set everything to 0 or free(file);  Going with free(file) for now
	//file->file = 0;
	//file->err = 0;
	//file->mode = 0;
	//*(file->name) = 0;
	//file->sizeInBytes = 0;
	free(file);
}

unsigned long read_file(File file, void *buf, unsigned long numbytes) {
	return 0;
}

unsigned long write_file(File file, void *buf, unsigned long numbytes) {
	//We should have an additional block for every 512 bytes plus 1(maybe 2) for remaining data
	int numberOfBlocks = (numbytes / SOFTWARE_DISK_BLOCK_SIZE) + 1; 

	return 0;
}

void seek_file(File file, unsigned long bytepos) {

}

unsigned long file_length(File file) {
	return file->sizeInBytes;
}

int delete_file(char *name) {
	return 0;
}

int file_exists(char *name) {
	return 0;
}

void fs_print_error(void) {

}