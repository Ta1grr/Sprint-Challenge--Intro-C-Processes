#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    struct dirent *ent;

    // DIR *directory;

    if (argc == 1) {
      // struct dirent *ent;

      // DIR *directory;

      DIR *directory = opendir(".");
      if (directory == NULL){
        fprintf(stderr, "ERROR MESSAGE: Directory is NULL\n");
        return -1;
      }
      while ((ent = readdir(directory))){
        printf("%s\n", ent->d_name);
      }
      closedir(directory);
      return 0;
    }

    for (int i = 0; i < argc; i++) {
        // struct dirent *ent;

        // DIR *directory;
        DIR *directory = opendir(argv[i]);

        printf("%s\n", argv[i]);
        // ent = readdir(directory);
        if (directory == NULL){
          fprintf(stderr, "ERROR MESSAGE: Directory is NULL\n");
          return -1;
        }
        while((ent = readdir(directory))){
          puts(ent->d_name);
        }
        closedir(directory);
      }
        // Close directory        
        // closedir(directory);
    

  return 0;
}