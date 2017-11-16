
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



int main() {








}
