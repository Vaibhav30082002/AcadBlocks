//Name : Vaibhav Shah
//Reg. No.: 20BBS0162

#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>

int main ()
{
    DIR *dir;
    struct stat buffer;
    struct dirent *dirEntry; // man 3 readdir
    time_t now = time(0);
   
    char dirName[50];
    printf ("\nInput the directory name: ");
    scanf ("%s", dirName);
    printf ("\n");
    
    dir = opendir(dirName);
    while((dirEntry = readdir(dir)) != NULL)
    {
        stat(dirEntry->d_name, &buffer);
        if (now - buffer.st_atime >= 604800){  //604800 is no. of seconds in a week
            
            printf ("%s ---> Not Accessed since a week---> Last Accessed at %s\n", dirEntry->d_name, ctime (&buffer.st_atime));
            
        }
    }

    closedir (dir);
    return 0;
}

