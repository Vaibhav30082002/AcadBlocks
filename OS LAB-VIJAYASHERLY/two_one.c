#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>

int main ()
{
    DIR *dir;
    struct stat buffer;
    struct dirent *dirEntry;
    time_t now = time(0);
   
    char dirName[50];
    printf ("\nInput the directory name: ");
    scanf ("%s", dirName);
    
    dir = opendir(dirName);
    while((dirEntry = readdir(dir)) != NULL)
    {
        stat(dirEntry->d_name, &buffer);
        if (now - buffer.st_mtime >= 604800){  //604800 is no. of seconds in a week
            
            printf ("\n%s ---> Not Modified since a week---> Last Modified at %s\n", dirEntry->d_name, ctime (&buffer.st_mtime));
            
        }
    }

    closedir (dir);
    return 0;
}


