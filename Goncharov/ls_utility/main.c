//
//  main.c
//  utility_ls
//
//  Created by Alexey Goncharov on 31.03.13.
//  Copyright (c) 2013 DIHT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include <dirent.h>


int main(int argc, const char * argv[])
{

  DIR *dpdf;
  struct dirent *epdf;
  int i = 0;
  char *nPath;
  if (argc > 1) {
    char *dirName = (char *)argv[1];
    int length = (int)strlen(dirName);
    nPath = malloc((2 + length)*sizeof(char));
    strcpy(nPath, "./");
    strcat(nPath, dirName);
    dpdf = opendir(nPath);
  } else {
    dpdf = opendir("./");
  }
  if (dpdf != NULL){
    while ((epdf = readdir(dpdf))){
      char *nameOfFile = epdf->d_name;
      if (nameOfFile[0] != '.') {
        printf("%s\n", nameOfFile);
        ++i;
      }
    }
  }
  if (i == 0) {
    printf("no files in such directory or directory doesn't exists");
  }
  return 0;
}

