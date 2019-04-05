#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int listing(const char *path) 
{
  // Declaring the ent pointer to struct dirent
  struct dirent *ent;

  // Declaring buff struct
  struct stat buf;

  // Calling stat using the full address and buf address
  stat("./lsls.c", &buf);

  // Declaring the directory pointer with DIR and assigning it with opendir()
  DIR *directory = opendir(path);

  // Checking if the directory is NULL and returning proper from stderr
  if (directory == NULL) 
  {
    // Using perror over fprintf(stderr, "strings") because it'll give a more precise error output.
    perror("opendir");
    return -1;
  }

  // While directory is not NULL it'll keep printing from readdir
  while((ent = readdir(directory))){
    printf("%10lld   %s\n", buf.st_size, ent->d_name);
  }
  closedir(directory);
  return 0;
}

int main(int argc, char **argv) {

  // If argc is 1 then it'll run current directory
  if (argc == 1){
    listing(".");
  }
  else{
    // else it'll iterate through argc and run the array of argv through lsls function and output accordingly.
    for (int i = 0; i < argc; i++) {
      listing(argv[i]);
    }
  }

  return 0;
}
