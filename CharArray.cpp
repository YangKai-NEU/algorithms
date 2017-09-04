#include <stdio.h>

int main(void)
{
    char *p[]={"TENCENT","CAMPUS","RECRUITING"};
    char **pp[]={p+2,p+1,p};
    char ***ppp=pp;
	printf("%s\n",**ppp);

    printf("%s\n",**++ppp);

	printf("%s\n",**ppp);

    printf("%s\n",*++*++ppp);
    return 0;
}