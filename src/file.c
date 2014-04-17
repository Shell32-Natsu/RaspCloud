#include <stdio.h>
#include <string.h>
/*Linux C API*/
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define CSTRLEN 1024     //The common string length in this file.
#define MSTRLEN 10240    //The maximum string length in this file.
/*Ansi C don't have type bool, so we define it*/
#define true 1
#define false 0
#define bool int

char cur_path[MSTRLEN]="/";	 //Current path in software.

void list_file(const char *directory,char *file_list)
{
	/*Display the file in directory*/
    char ctmp[MSTRLEN]={0};
    strcat(ctmp,cur_path);
    strcat(ctmp,name);

    DIR *dir = opendir(ctmp);
    
    if(dir == NULL)
    {
        fprintf(stderr,"Error:Can not open directory %s.\n",directory);
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
    char tmp[MSTRLEN]={0};
    strcat(tmp,cur_path);
    strcat(tmp,name);
    if(creat(tmp,S_IWUSR|S_IRUSR) == -1)
    {
        fprintf(stderr,"Error:Can not create file %s.\n",name);
        return false;
    }
    else
        return true;
}

bool new_dir(const char *name)
{
    /*Create a new directory*/

    char tmp[MSTRLEN]={0};
    strcat(tmp,cur_path);
    strcat(tmp,name);
    if(mkdir(tmp,S_IWUSR|S_IRUSR|S_IXUSR) == -1)
    {
        fprintf(stderr,"Error:Can not create file %s.\n",name);
        return false;
    }
    else
        return true;
}

bool enter_dir(const char *name)
{
    /*Enter a directory*/
    char tmp[MSTRLEN]={0};
    strcat(tmp,cur_path);
    strcat(tmp,name);

    if(opendir(tmp) == NULL)
    {
        fprintf(stderr,"Error:Can not enter directory %s.\n",name);
        return false;
    }
    else
    {
        strcat(cur_path,name);
        strcat(cur_path,"/");
        return true;
    }
}

int main(void)
{
    strcpy(cur_path,"/home/xiadong/");
    if(enter_dir("test"))
    {
        puts("yes");
        puts(cur_path);
    }
    else
        puts("no");
    return 0;
}
