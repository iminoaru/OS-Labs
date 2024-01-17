#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd = open("./file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0); // makes sure that the file is opened, else breaks
    char buffer[20];
    sprintf(buffer, "hello world\n");
    int rc = write(fd, buffer, strlen(buffer)); // overwrites the file with buffer
    assert(rc == (strlen(buffer))); // makes sure the buffer got written on 'file'
    fsync(fd); // makes sure the data is stored at a stable storage layer
    close(fd); // closes file
    return 0;
}
