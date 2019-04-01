#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

    // Calling the struct dirent to the pointer *ent
    struct dirent *ent;

  // if (argc == 1){

  // }

  // for (int i = 0; i < argc; i++) {
  //   printf("%s\n", argv[i]);

  // }
    DIR *directory;

    // Assigning directory with opendir depending on argc equal to 1 or not.
    // DIR *directory = argc == 1 ? opendir(".") : opendir(*argv);

    // directory = argc == 1 ? opendir(".") : opendir(*argv);
    // Assigning ent address to readdir()
    // ent = readdir(directory);



    // If the directory is NULL then return the error message
    // if (argc == 1) {
      

    //   return 0;
    // }
    // else print the names
    if (argc == 1) {
      directory = opendir(".");
      if (directory == NULL){
        fprintf(stderr, "ERROR MESSAGE: Directory is NULL\n");
      }
      while ((ent = readdir(directory))){
        printf("%s\n", ent->d_name);
      }
      closedir(directory);
      return 0;
    }

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
        directory = opendir(argv[i]);
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