#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//4 types of nodes have been created 
struct individual;
struct business;
struct group;
struct org;

typedef struct individual individual;
typedef struct business business;
typedef struct group group;
typedef struct org org;

//date struct for storing Creation date and Birthday in dd mm yy format
typedef struct
{
    int dd;
    int mm;
    int yy;
}date;

//point struct for storing 2D coordinate for Business and Organisation
typedef struct
{
    int x;
    int y;
}point;

//string struct for storing posted content and Name
typedef struct
{
    char str[100];
}string;

//1)
struct individual
{
    //unique id
    int id;

    //birthday date
    date bd;

    //name of individual
    string name;

    //date of creation of node
    date creation;

    //contents : array of strings
    string contents[100];
    int consiz;

    //check : 0 -> node deleted , 1 -> node active
    int check;

    //links
    //1. All groups to which this individual belongs
    group* membership_group[100];
    int mgsize;

    //2. All businesses which this individual owns
    business* ownership_business[100];
    int obsize;

    //3. All organizations to which this individual belongs
    org* membership_organizations[100];
    int mosize;

    //4. All businesses of which this individual is customer
    business* customership_business[100];
    int cbsize;
};

//2)
struct group
{
    //unique id
    int id;

    //name of group
    string name;

    //date of creation of node
    date creation;

    //contents : array of strings
    string contents[100];
    int consiz;

    //check : 0 -> node deleted , 1 -> node active
    int check;

    //links
    //1. All individuals which are members of this group
    individual* membership_individual[100];
    int misize;

    //2. All business which are members of this group
    business* membership_business[100];
    int mbsize;

};

//3)
struct business
{
    //unique id
    int id;

    //name of business
    string name;

    //date of creation of node
    date creation;

    //2D coordinate
    point coord;

    //contents : array of strings
    string contents[100];
    int consiz;

    //check : 0 -> node deleted , 1 -> node active
    int check;

    //links
    //1. All individuals which cutomer / owner of this business
    individual* customer_individual[100];
    individual* owner_individual[100];
    int cisize;
    int oisize;

    //2. All groups of which this business is a member
    group* membership_group[100];
    int mgsize;

};

//4)
struct org
{
    //unique id
    int id;

    //name of organisation
    string name;

    //date of creation of node
    date creation;

    //2D coordinate
    point coord;

    //contents : array of strings
    string contents[100];
    int consiz;

    //check : 0-> node deleted , 1 -> node active
    int check;

    //links
    //1. All individuals which cutomer / owner of this business
    individual* membership_individual[100];
    int misize;
};


//Number to Type mapping :
//1->individual
//2->business
//3->group
//4->organization


//Prints the content of node passed in parameters : identified by type and correspoding pointer used to print the content if the node exits
//If the type is invalid or If the pointer corresponding to the type is NULL or if that node is deleted then nothing is printed
void print_content(int type,individual * p1,business * p2,group * p3,org * p4);

//Prints the <Name,ID> of direct neighbours of a given node
void print_links(int type,individual * p1,business * p2,group * p3,org * p4);

//Takes ID of node whose links are to be printed form user and after finding this node calls print_links function
void print_1_hop(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz);

//Prints all data of a given type of node except its contents and links
void print_node(int type,individual * p1,business * p2,group * p3,org * p4);

//Makes links between pair of valid ID's of nodes entered by user
void make_link(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz);

//Created of node of passed type by taking input of all necessary data in corresponding struct
//Memory is allocated to first vacant pointer in the sti (for individual) , stb (for business) , stg (for group) , sto (for organisation) array 
//Then all necessary fields are filled by user input 
//For making links with other nodes make_link is called
void create_node(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz,int type);

//Checks if entered node exits and if it exits changes its change variable to 0
void delete_node(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz);

//Searches node based on name , type , birthday and prints the node ID of nodes matching the input
void search_node(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz);

//Posts content entered by user in a node whose ID is entered by user , if same content is already present then it doesn't add content
void post_content(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz);

//Searches for a content entered by user in all nodes and prints ID of those nodes who have posted this content
void search_content(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz);

//Iterates over all groups and organisations and prints all individuals linked them i.e. prints all 2 hop realtions of all pairs of individuals
void print_linked_individual(group* stg[100],org* sto[100],int * gsiz,int * osiz);

//7 : INTERFACE
void interface(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz);

//All strings are assumed to be of 100 size at max and containing no whitespace character
//The number of contents posted by a particular node is bound by 100
//The total number of nodes of each type are bound by 100