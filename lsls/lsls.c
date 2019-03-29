#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    int i;

    // to print out from the struct
    struct dirent *ent;

    // Open directory
    DIR *d;
    d = opendir(argv);
    if (d == NULL){
      fprintf(stderr, "ERROR MESSAGE");
      exit();
    }

    // Repeatly read and print entries
    ent = readdir(d);

    printf("There are %d command line argument(s):\n", argc);
    if (d != NULL){
      for (i = 0; i < argc; i++) {
        printf("   %s\n", argv->d_name);
    }
        // Close directory
          
          closedir(d);

    }


  return 0;
}