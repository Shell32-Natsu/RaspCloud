#include <stdio.h>
#include "../include/file.h"
#include "../include/marco.h"


int main(void)
{
	new_file("testfile");
	new_dir("testdir");
	char list[MSTRLEN];
	list_file(list);
	puts(list);
	return 0;
}
