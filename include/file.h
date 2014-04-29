/*Copyright 2013-2014
 *
 *All rights reserved.
 *
 *Name:file.h
 *Author:XiaDong
 *E-mail:xiadong1994@126.com 
 *Date:2014-4-22
 */

#ifndef _H_RASPCLOUDFILE
#define _H_RASPCLOUDFILE

#include "marco.h"

/*Display the file in directory*/
void list_file(char *file_list);

/*Create a new file*/
bool new_file(const char *name);

/*Create a new directory*/
bool new_dir(const char *name);

/*Enter a directory*/
bool enter_dir(const char *name);

 /*Exit to parent directory*/
bool exit_dir(void);

/*Delete a file*/
bool del_file(const char *name);

/*Delete a directory*/
bool del_dir(const char *name);

/*Get current directory path*/
void get_dir(char *target);

/*Set current directory path*/
void set_dir(char *src);
#endif
