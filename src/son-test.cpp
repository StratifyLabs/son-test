//============================================================================
// Name        : son-test.cpp
// Author      : Tyler G
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstdlib>
using namespace std;

#include <stfy/son.h>

int main(){
	son_t h;
	son_stack_t stack[4];
	printf("Use this project to test the SON project\n");

	son_set_driver(&h, 0);

	if( son_create(&h, "/Users/tgil/Desktop/test.son", stack, 4) < 0 ){
		printf("Failed to create SON file\n");
		exit(1);
	}

	son_open_obj(&h, "root");
	son_open_obj(&h, "name");

	son_write_str(&h, "first", "Tyler");
	son_write_str(&h, "last", "Gilbert");

	son_close_obj(&h);
	son_close_obj(&h);

	son_close(&h, 0);

	char buffer[32];


	son_open(&h, "/Users/tgil/Desktop/test.son");

	son_read_str(&h, "name.first", buffer, 32);
	son_close(&h, 0);

	printf("First name is %s\n", buffer);



	return 0;
}
