#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ftw.h>
#include <sys/stat.h>

static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    if(typeflag == FTW_F){
            num_regular++;
            return 0;
    }else if(typeflag == FTW_D){
            num_dirs++;
            return 0;
    }else{
            return 0;
    }
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check arguments and set things up
    num_dirs = num_regular = 0;

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results 
    printf("There were %d directories. \n", num_dirs);
    printf("There were %d regular files. \n", num_regular);
}
