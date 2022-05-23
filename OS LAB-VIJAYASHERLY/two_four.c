#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>


int main ()
{
    DIR *dir;
    struct stat buffer;
    struct dirent *dirEntry;
    blkcnt_t block;
   
    char dirName[50];
    printf ("\nInput the directory name: ");
    scanf ("%s", dirName);
    
    dir = opendir(dirName);
    while((dirEntry = readdir(dir)) != NULL)
    {
        stat(dirEntry->d_name, &buffer);
        long long[] numbers;
        
        while(i < numbers.length) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
            i = i + 1; // or simply i++;
        }
        int i = 0
        if (buffer.st_blocks >= buffer.st_blocks - i ){  //604800 is no. of seconds in a week
            
            printf ("\n%s ---> Not Modified since a week---> Last Modified at %lld\n", dirEntry->d_name, (long long)buffer.st_blocks);
            
        }
    }

    closedir (dir);
    return 0;
}



//#include<sys/vfs.h>
//#include<stdio.h>
//main(int argc,char **argv)
//
//{
//struct statfs stfs;
//statfs(argv[1],&stfs);
//printf("Total Blocks in the Filesystem %dn",4*stfs.f_blocks);
//printf("Block Size %dn",stfs.f_bsize/4);
//printf("Total Free Blocks in FS %dn",stfs.f_bfree);
//printf("Total Blocks Used %dn",4*(stfs.f_blocks-stfs.f_bfree));
//printf("Total Blocks Available to non Super User %dn",4*stfs.f_bavail);
//printf("Total File Nodes %dn",stfs.f_ffree);
//printf("Total Blocks in the Filesystem %dn",stfs.f_blocks);
//}
