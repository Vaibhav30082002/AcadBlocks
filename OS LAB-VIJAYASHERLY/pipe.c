// Vaibhav Shah
// 20BBS0162
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
const char *get_filename_ext(const char *filename) {
const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
    }
int main(void) {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    int f_d = 0;
    struct stat st;
    if (d) {
        while ((dir = readdir(d)) != NULL) {
        if(strcmp(get_filename_ext(dir->d_name),"c") == 0 && dir->d_type == DT_REG){ printf("%s ", dir->d_name);
            f_d = open(dir->d_name,O_RDONLY);
            if(-1 == f_d)
            {
                printf("\n NULL File descriptor\n");
                return -1; }
                errno = 0;
                 if(fstat(f_d, &st))
                {
                    printf("\nfstat error: [%s]\n",strerror(errno)); close(f_d);
                    return -1;
                    }
                    char *modeval = malloc(sizeof(char) * 9 + 1);
            mode_t perm = st.st_mode;
            modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
            modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
            modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
            modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
            modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
            modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
            modeval[6] = (perm & S_IROTH) ? 'r' : '-';
            modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
            modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
            modeval[9] = '\0';
            
            printf("%s ",modeval);
            char time[50];
            strftime(time, 50, "%Y-%m-%d %H:%M:%S",localtime(&st.st_mtime));
            printf ("%s ", time);
            struct passwd *pw = getpwuid(st.st_uid);
             struct group *gr = getgrgid(st.st_gid);
            printf("%s %s\n", pw->pw_name, gr->gr_name);
            
        }
        }
            closedir(d);
    }
            return 0;
}
