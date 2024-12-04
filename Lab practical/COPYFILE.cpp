#include <fcntl.h>   // For open()
#include <unistd.h>  // For read(), write(), close()
#include <stdio.h>   // For perror()

#define BUFFER_SIZE 1024

int main() {
    char src[100], dest[100], buffer[BUFFER_SIZE];
    printf("Enter source file: ");
    scanf("%s", src);
    printf("Enter destination file: ");
    scanf("%s", dest);

    int src_fd = open(src, O_RDONLY);
    if (src_fd < 0) { perror("Error opening source file"); return 1; }

    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) { perror("Error opening destination file"); close(src_fd); return 1; }

    ssize_t bytes;
    while ((bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0)
        if (write(dest_fd, buffer, bytes) != bytes) { perror("Write error"); break; }

    if (bytes < 0) perror("Read error");
    close(src_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
    return 0;
}
