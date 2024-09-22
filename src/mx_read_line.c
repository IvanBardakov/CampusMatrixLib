#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (!lineptr || fd < 0 || buf_size <= 0) return -2;

    static char buffer[4096];
    static int buffer_size = 0;
    static int buffer_index = 0;

    int total_bytes = 0;
    *lineptr = mx_strnew(0);
    if (!*lineptr) return -2;

    while (1) {
        if (buffer_index >= buffer_size) {
            buffer_size = read(fd, buffer, buf_size);
            buffer_index = 0;
            if (buffer_size <= 0) {
                if (total_bytes > 0) return total_bytes;
                return buffer_size == 0 ? -1 : -2;
            }
        }

        while (buffer_index < buffer_size) {
            if (buffer[buffer_index] == delim) {
                buffer_index++;
                return total_bytes;
            }

            *lineptr = mx_realloc(*lineptr, total_bytes + 2);
            if (!*lineptr) return -2;

            (*lineptr)[total_bytes] = buffer[buffer_index];
            total_bytes++;
            buffer_index++;
        }
    }
}
