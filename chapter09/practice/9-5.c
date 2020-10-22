// 编写程序，使用 mmap 将一个任意大小的磁盘文件复制到 stdout，文件名需作为命令行参数来传递

# include <stdio.h>
# include <sys/mman.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("filename is required %s\n", argv[0]);
        return 0;
    }
    FILE *fp = fopen(argv[1], "r");
    int fd = fileno(fp);
    void* m =  mmap(NULL, 20, PROT_READ, MAP_SHARED, fd, 0);
    char *c = m;
    printf("%s\n", c);
    return 0;
}