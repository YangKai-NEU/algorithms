#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	
	printf("%d\n",'\"');
	
	for(int i=0;i<256;i++){
		printf("%d\t%c\n",i,i);
	}

	return 0;
}
