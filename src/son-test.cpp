//============================================================================
// Name        : son-test.cpp
// Author      : Tyler G
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

#include <stfy/son.h>

void test_son_method1(){
	son_t h;
	son_stack_t stack[4];
	printf("Use this project to test the SON project \n");

	son_set_driver(&h, 0);

	if( son_create(&h, "/Users/nkgau/Desktop/test.son", stack, 4) < 0 ){
		printf("Failed to create SON file\n");
		exit(1);
	}

	son_open_obj(&h, "root");
	son_open_obj(&h, "name");


	son_write_str(&h, "first", "Tyler");

	son_write_str(&h, "last", "Gilbert");

	//son_open_obj(&h,"age");
	son_write_num(&h,"age",17);

	son_write_float(&h,"price",10.10);

	char i[2] = "2";
	void * t = (void *) i;

	son_write_data(&h,"data",t,2);

	printf("son_write_false() ret = %d\n",son_write_false(&h,"instock"));

	son_close_obj(&h);
	son_close_obj(&h);


	son_close(&h, 0);

	char buffer[32];

	son_open(&h, "/Users/nkgau/Desktop/test.son");

	son_read_str(&h, "name.last", buffer, 32);
	printf("last name is %s\n", buffer);
	printf("age = %d\n",son_read_num(&h,"name.age"));
	printf("instock = %d\n",son_read_bool(&h,"name.instock"));
	memset(buffer,0,32);
	son_read_data(&h,"name.data",buffer,32);

	    printf("name.data = %s\n",buffer);
	son_close(&h, 0);




}

void test_son_edit_unum(){

	son_t h;
	int ret;
	printf("Use this method to test edit unum SON \n");

	son_set_driver(&h,0);

	son_edit(&h,"/User/nkgau/Desktop/test.son");

	ret = son_edit_unum(&h,"name.salary",0xffffffff);

	printf("ret is %d \n", ret);

	son_close(&h,0);

	son_open(&h,"/Users/nkgau/Desktop/test.son");

	printf("age = %u \n", son_read_unum(&h,"name.salary"));

	son_close(&h,0);

}

void test_son_edit_num(){
	son_t h;

	int ret;

	printf("Use this method to test edit num SON\n");

	son_set_driver(&h,0);

	son_edit(&h,"/Users/nkgau/Desktop/test.son");

	ret = son_edit_num(&h,"name.age",71);

	printf("ret is %d \n",ret);

	son_close(&h,0);

	son_open(&h,"/Users/nkgau/Desktop/test.son");

	printf("age = %d\n",son_read_num(&h,"name.age"));

	son_close(&h,0);

}
void test_son_edit_str(){
	son_t h;

	int ret;

	printf("Use this method to test edit str SON \n");

	son_set_driver(&h,0);

	son_edit(&h,"/Users/nkgau/Desktop/test.son");
    char buffer[32] = "Naren";

    //ret = son_edit_data(&h,"name.first",buffer,sizeof(buffer));
    ret = son_edit_str(&h,"name.first",buffer);

    printf("ret is %d \n", ret);

    son_close(&h,0);

    memset(buffer,0,32);

    son_open(&h,"/Users/nkgau/Desktop/test.son");

    son_read_str(&h,"name.first",buffer,32);

    son_close(&h,0);

    printf("last name is %s \n",buffer);

}

void test_son_edit_method(){
	son_t h;
	//son_stack_t stack[4];
	int ret;

	printf("Use this method to test edit SON \n");

	son_set_driver(&h,0);
    son_edit(&h,"/Users/nkgau/Desktop/test.son");


	char buffer[32] = "Hell";

    ret = son_edit_data(&h,"name.first",buffer,sizeof(buffer));

    printf("ret is %d \n",ret);

    son_close(&h,0);

	memset(buffer, 0, 32);

	son_open(&h,"/Users/nkgau/Desktop/test.son");

	son_read_str(&h,"name.first",buffer,32);

	son_close(&h,0);

	printf("Last name is %s \n",buffer);

}

void test_son_edit_float(){
	son_t h;

	int ret;

	printf("Use this method to test edit float SON\n");

	son_set_driver(&h,0);

	son_edit(&h,"/Users/nkgau/Desktop/test.son");


	ret = son_edit_float(&h,"name.price",13.60);

	printf("ret is %d\n",ret);

	son_close(&h,0);

	son_open(&h,"/Users/nkgau/Desktop/test.son");

	printf("name.price = %f\n ",son_read_float(&h,"name.price"));

	son_close(&h,0);
}

void test_son_edit_bool(){
	son_t h;

	int ret;

	printf("Use this method to test edit bool SON\n");

	son_edit(&h,"/Users/nkgau/Desktop/test.son");

	ret = son_edit_bool(&h,"name.instock",TRUE);

	printf("son_edit_bool ret = %d\n",ret);
	son_close(&h,0);

	son_open(&h,"/Users/nkgau/Desktop/test.son");

	printf("name.instock %d \n",son_read_bool(&h,"name.instock"));

	son_close(&h,0);

}

void test_son_edit_data(){
    son_t h;

    int ret;

    char buffer[32];
    printf("Use this method to test edit data SON\n");

    son_edit(&h,"/Users/nkgau/Desktop/test.son");

    char i[2] = "3";
    	void * t = (void *) i;
    ret = son_edit_data(&h,"name.data",t,2);

    printf("son_edit_data() ret= %d\n",ret);

    son_close(&h,0);

    son_open(&h,"/Users/nkgau/Desktop/test.son");

    son_read_data(&h,"name.data",buffer,32);

    printf("name.data = %s\n",buffer);

    son_close(&h,0);
}

int main(){
	test_son_method1();//
    //test_son_edit_method();
	//test_son_edit_str();
	//test_son_edit_num();
	//test_son_edit_float();
	//test_son_edit_bool();
	test_son_edit_data();
	return 0;
}
