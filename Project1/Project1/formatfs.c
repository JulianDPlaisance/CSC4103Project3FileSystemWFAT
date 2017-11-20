
/*

You must provide a file system initialization program called formatfs.c which initializes
your file system. Part of this initialization will including initializing the software disk via
init_software_disk(), which destroys all existing data.

*/

/*
 *
 * Ask Golden if using this try/catch structure from http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html
 *  is appropriate, with appropriate crediting
 *
 *
 *
#include <stdio.h>
#include <setjmp.h>

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

int
main(int argc, char** argv)
{
   TRY
   {
      printf("In Try Statement\n");
      THROW;
      printf("I do not appear\n");
   }
   CATCH
   {
      printf("Got Exception!\n");
   }
   ETRY;

   return 0;
 *
 *
 */


#include "softwaredisk.h"

int init_software_disk(){

try: {
//destroy existing data

void * bufr[SOFTWARE_DISK_BLOCK_SIZE] = {0};

for (int softi = 1; softi <= SOFTWARE_DISK_BLOCK_SIZE; softi++){
write_sd_block(bufr, SOFTWARE_DISK_BLOCK_SIZE)
}

//create new instances of data

}
return 1;

catch:
return 0;
}

int main(){


//Do file system initialization
	//maybe try/catch to make the error checking?

init_software_disk();


if (there was an error){
	printf("Error initializing file system. \n")
	return 1;
}
else
	return 0;
}
