#include<stdio.h>
#include"social.h"


int main()
{
    //we will be maintaining 4 arrays of pointers which will store the addresses of added nodes of each type
    individual* sti[100];int isiz=0;
    business* stb[100];int bsiz=0;
    group* stg[100];int gsiz=0;
    org* sto[100];int osiz=0;

    create_node(sti,stb,stg,sto,&isiz,&bsiz,&gsiz,&osiz,1);
    print_links(1,sti[0],NULL,NULL,NULL);


    return 0;
}