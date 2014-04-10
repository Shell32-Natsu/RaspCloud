#include <stdio.h>
#include <string.h>
/*Linux C API*/
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

#define CSTRLEN 1024     //The common string length in this file.
#define MSTRLEN 10240    //The maximum string length in this file.

char cur_path[MSTRLEN]="/";	 //Current path in software.

void disp_file(const char *directory,char *file_list)
{
	/*Display the file in directory*/
    DIR *dir = opendir(directory);
    
    if(dir == NULL)
    {
        fprintf(stderr,"Error:Can not open directory %s\n",directory);
        return;
    }
    
    struct dirent *tmp;
    
    while(tmp = readdir(dir))
    {
        strcat(file_list,tmp->d_name);
        strcat(file_list,"\t");
        if(tmp->d_type == DT_DIR)
            strcat(file_list,"dir");
        else if(tmp->d_type == DT_REG)
        	strcat(file_list,"file");
        strcat(file_list,"\n");
    }
    
    closedir(dir);
}

bool new_file(const char *name)
{
	/*Create a new file*/
	
}
int main(void)
{
    char flist[MSTRLEN]={0},dir[CSTRLEN];
    scanf("%s",dir);
    disp_file(dir,flist);
    puts(flist);
    return 0;
}
