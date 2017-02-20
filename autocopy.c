/*
The 
sendfile
call can be used in many places to make copies more efficient. One
good example is in a Web server or other network daemon, that serves the contents of
a file over the network to a client program.Typically, a request is received from a
socket connected to the client computer.The server program opens a local disk file to
etrieve the data to serve and writes the file’s contents to the network socket. Using
sendfile can speed up this operation considerably. Other steps need to be taken to
make the network transfer as efficient as possible, such as setting the socket parameters
correctly. However, these are outside the scope of this book.
*/
#include <fcntl.h>
//#include <stdlib.h>
//#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
char * progname=argv[0];

write(1, "creado por d4sh&r\n", 18);
int read_fd;
int write_fd;
struct stat stat_buf;
off_t offset = 0;
/* Open the input file.  */
read_fd = open (progname, O_RDONLY);
/* Stat the input file to obtain its size.  */
fstat (read_fd, &stat_buf);
/* Open the output file for writing, with the same permissions as the
source file.  */
write_fd = open ("r2", O_WRONLY 
|
O_CREAT, stat_buf.st_mode);
/* Blast the bytes from one file to the other.  */
sendfile (write_fd, read_fd, &offset, stat_buf.st_size);
/* Close up.  */
close (read_fd);
close (write_fd);
return 0;
}
