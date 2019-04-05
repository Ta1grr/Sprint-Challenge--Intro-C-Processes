#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *directory;
  struct dirent *ent;

  struct stat buf;

  stat("./lsls.c", &buf);

  printf("There are %d command line argument(s):\n", argc);

  // Open directory
    if (argc == 1) {
      directory = opendir(".");
    }
    else {
      directory = opendir(argv[1]);
    }
    if (directory == NULL) {
      perror("opendir");
      return -1;
    }
  // Repeatly read and print entries
    while((ent = readdir(directory))) {
      printf("%10lld   %s\n", buf.st_size, ent->d_name);
    }

    /* Tried using for loops*/
    // int length = sizeof(argv);

    // for (int i = 0; i < length - 1; i++) {
    //   ent = readdir(directory);
    //   printf("%10lld   %s\n", buf.st_size, ent->d_name);
    // }

  // Close directory
  closedir(directory);



  return 0;
}