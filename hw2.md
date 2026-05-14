# Homework

## Task 1

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

static void write_all(int fd, const char *buf, ssize_t n) {
    ssize_t done = 0;
    while (done < n) {
        ssize_t w = write(fd, buf + done, n - done);
        if (w <= 0) return;
        done += w;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        char msg[] = "Usage: ./task1 <file> <I> <N>\n";
        write(2, msg, sizeof(msg) - 1);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) return 1;

    int start = atoi(argv[2]);
    int cnt = atoi(argv[3]);

    if (start <= 0 || cnt <= 0) {
        close(fd);
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        close(fd);
        return 1;
    }

    ssize_t buf_size = 4096;
    if (st.st_size > 0 && st.st_size < buf_size) {
        buf_size = st.st_size;
    }

    char *buf = malloc(buf_size);
    if (buf == NULL) {
        close(fd);
        return 1;
    }

    int line = 1;
    int finish = start + cnt;
    ssize_t r;

    while ((r = read(fd, buf, buf_size)) > 0) {
        ssize_t pos = -1;

        for (ssize_t i = 0; i < r; ++i) {
            if (line >= start && line < finish && pos == -1) {
                pos = i;
            }

            if (buf[i] == '\n') {
                if (line >= start && line < finish && line + 1 >= finish) {
                    write_all(1, buf + pos, i + 1 - pos);
                    free(buf);
                    close(fd);
                    return 0;
                }

                line++;

                if (!(line >= start && line < finish) && pos != -1) {
                    write_all(1, buf + pos, i + 1 - pos);
                    pos = -1;
                }
            }
        }

        if (pos != -1) {
            write_all(1, buf + pos, r - pos);
        }

        if (line >= finish) break;
    }

    free(buf);
    close(fd);
    return 0;
}



## Task 2

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

static void write_all(int fd, const char *buf, ssize_t n) {
    ssize_t done = 0;
    while (done < n) {
        ssize_t w = write(fd, buf + done, n - done);
        if (w <= 0) return;
        done += w;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        char msg[] = "Usage: ./task2 <file>\n";
        write(2, msg, sizeof(msg) - 1);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) return 1;

    struct stat st;
    if (fstat(fd, &st) < 0) {
        close(fd);
        return 1;
    }

    if (st.st_size == 0) {
        close(fd);
        return 0;
    }

    off_t mid = st.st_size / 2;

    if (lseek(fd, mid, SEEK_SET) < 0) {
        close(fd);
        return 1;
    }

    ssize_t buf_size = 4096;
    if (st.st_size - mid < buf_size) {
        buf_size = st.st_size - mid;
    }

    char *buf = malloc(buf_size);
    if (buf == NULL) {
        close(fd);
        return 1;
    }

    ssize_t r;

    while ((r = read(fd, buf, buf_size)) > 0) {
        for (ssize_t i = 0; i < r; ++i) {
            if (buf[i] == '\n') {
                write_all(1, buf, i + 1);
                free(buf);
                close(fd);
                return 0;
            }
        }

        write_all(1, buf, r);
    }

    free(buf);
    close(fd);
    return 0;
}
