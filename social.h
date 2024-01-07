#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//****
struct individual;
struct business;
struct group;
struct org;

typedef struct individual individual;
typedef struct business business;
typedef struct group group;
typedef struct org org;

typedef struct
{
    int dd;
    int mm;
    int yy;
}date;

typedef struct
{
    int x;
    int y;
}point;

typedef struct
{
    char str[100];
}string;

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

    //check : 0-> node deleted , 1 -> node active
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

    //4. All businesses which this individual owns
    business* customership_business[100];
    int cbsize;
};

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

    //check : 0-> node deleted , 1 -> node active
    int check;

    //links
    //1. All individuals which are members of this group
    individual* membership_individual[100];
    int misize;

    //2. All business which are members of this group
    business* membership_business[100];
    int mbsize;

};

struct business
{
    //unique id
    int id;

    //name of group
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
    individual* customer_individual[100];
    individual* owner_individual[100];
    int cisize;
    int oisize;

    //2. All groups of which this business is a member
    group* membership_group[100];
    int mgsize;

};

struct org
{
    //unique id
    int id;

    //name of group
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


//type :
//1->individual
//2->business
//3->group
//4->organization


void print_content(int type,individual * p1,business * p2,group * p3,org * p4)
{
    printf("Contents of node are : \n");
    if(type==1)
    {
        if(p1==NULL)
        {
            printf("Error\n");
            return;
        }
        if(p1->check==0)
        {
            return;
        }
        for(int i=0;i<p1->consiz;i++)
        {
            printf("%s\n",p1->contents[i].str);
        }
    }
    else if(type==2)
    {
        if(p2==NULL)
        {
            printf("Error\n");
            return;
        }
        if(p2->check==0)
        {
            return;
        }
        for(int i=0;i<p2->consiz;i++)
        {
            printf("%s\n",p2->contents[i].str);
        }
    }
    else if(type==3)
    {
        if(p3==NULL)
        {
            printf("Error\n");
            return;
        }
        if(p3->check==0)
        {
            return;
        }
        for(int i=0;i<p3->consiz;i++)
        {
            printf("%s\n",p3->contents[i].str);
        }
    }
    else if(type==4)
    {
        if(p4==NULL)
        {
            printf("Error\n");
            return;
        }
        if(p4->check==0)
        {
            return;
        }
        for(int i=0;i<p4->consiz;i++)
        {
            printf("%s\n",p4->contents[i].str);
        }
    }
    else
    {
        printf("Invalid type\n");
    }
    return;
}

//3
void print_links(int type,individual * p1,business * p2,group * p3,org * p4)
{
    if(type==1)
    {
        if(p1->check==0)
        {
            return;
        }
        printf("Groups of which %s is a member (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->mgsize;i++)
        {
            group * temp = p1->membership_group[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p1->mgsize);

        printf("Business of which %s is a owner (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->obsize;i++)
        {
            business * temp = p1->ownership_business[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p1->obsize);

        printf("Business of which %s is a customer (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->cbsize;i++)
        {
            business * temp = p1->customership_business[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p1->cbsize);

        printf("Organisations of which %s is a member (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->mosize;i++)
        {
            org * temp = p1->membership_organizations[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p1->mosize);
    }
    else if(type==2)
    {
        if(p2->check==0)
        {
            return;
        }
        printf("Individuals who are owner of %s (ID , Name) :\n",p2->name.str);
        for(int i=0;i<p2->oisize;i++)
        {
            individual * temp = p2->owner_individual[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p2->oisize);

        printf("Individuals who are customer of %s (ID , Name) :\n",p2->name.str);
        for(int i=0;i<p2->cisize;i++)
        {
            individual * temp = p2->customer_individual[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p2->cisize);

        printf("Groups of which %s is a member (ID , Name) :\n",p2->name.str);
        for(int i=0;i<p2->mgsize;i++)
        {
            group * temp = p2->membership_group[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p2->mgsize);
    }
    else if(type==3)
    {
        if(p3->check==0)
        {
            return;
        }
        printf("Individuals who are member of %s (ID , Name) :\n",p3->name.str);
        for(int i=0;i<p3->misize;i++)
        {
            individual * temp = p3->membership_individual[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p3->misize);

        printf("Business which are member of %s (ID , Name) :\n",p3->name.str);
        for(int i=0;i<p3->mbsize;i++)
        {
            business * temp = p3->membership_business[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p3->mbsize);
    }
    else if(type==4)
    {
        if(p4->check==0)
        {
            return;
        }
        printf("Individuals who are member of %s (ID , Name) :\n",p4->name.str);
        for(int i=0;i<p4->misize;i++)
        {
            individual * temp = p4->membership_individual[i];
            printf("%d %s\n",temp->id,temp->name.str);
        }
        printf("Total count : %d\n",p4->misize);
    }
    else
    {
        printf("Invalid type\n");
    }
    return;
}

void print_node(int type,individual * p1,business * p2,group * p3,org * p4)
{
    if(type==1)
    {
        if(p1->check==0)
        {
            return;
        }
        printf("Node ID : ");
        printf("%d\n",p1->id);

        printf("Birthday : ");
        printf("%d %d %d\n",(p1->bd.dd),(p1->bd.mm),(p1->bd.yy));

        printf("Name : ");
        printf("%s\n",p1->name.str);

        printf("Creation date : ");
        printf("%d %d %d\n",(p1->creation.dd),(p1->creation.mm),(p1->creation.yy));
    }
    else if(type==2)
    {
        if(p2->check==0)
        {
            return;
        }
        printf("Node ID : ");
        printf("%d\n",p2->id);

        printf("Name : ");
        printf("%s\n",p2->name.str);

        printf("Creation date : ");
        printf("%d %d %d\n",(p2->creation.dd),(p2->creation.mm),(p2->creation.yy));

        printf("2D coordinate : (%d,%d)",p2->coord.x,p2->coord.y);
    }
    else if(type==3)
    {
        if(p3->check==0)
        {
            return;
        }
        printf("Node ID : ");
        printf("%d\n",p3->id);

        printf("Name : ");
        printf("%s\n",p3->name.str);

        printf("Creation date : ");
        printf("%d %d %d\n",(p3->creation.dd),(p3->creation.mm),(p3->creation.yy));
    }
    else
    {
        if(p4->check==0)
        {
            return;
        }
        printf("Node ID : ");
        printf("%d\n",p4->id);

        printf("Name : ");
        printf("%s\n",p4->name.str);

        printf("Creation date : ");
        printf("%d %d %d\n",(p4->creation.dd),(p4->creation.mm),(p4->creation.yy));

        printf("2D coordinate : (%d,%d)",p4->coord.x,p4->coord.y);   
    }
}

//1
void create_node(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz,int type)
{
    if(type==1)
    {
        int siz = *isiz;
        *isiz = siz + 1;

        //allocating memory
        sti[siz] = (individual*)malloc(sizeof(individual));

        printf("Enter unique node id :\n");
        scanf("%d",&(sti[siz]->id));

        printf("Enter Birthday in the format dd mm yy :\n");
        scanf("%d",&(sti[siz]->bd.dd));
        scanf("%d",&(sti[siz]->bd.mm));
        scanf("%d",&(sti[siz]->bd.yy));

        printf("Enter name :\n");
        scanf("%s",sti[siz]->name.str);

        printf("Enter today's date :\n");
        scanf("%d",&(sti[siz]->creation.dd));
        scanf("%d",&(sti[siz]->creation.mm));
        scanf("%d",&(sti[siz]->creation.yy));

        sti[siz]->check=1;
        sti[siz]->consiz=0;

        sti[siz]->mgsize=0;
        sti[siz]->mosize=0;
        sti[siz]->obsize=0;

        //taking links
        int n;
        printf("Enter number of links to be made :\n");
        scanf("%d",&n);
        while(n--)
        {
            int ty;
            printf("Enter type of link :\n");
            printf("Press 1 : Add group to which %s belongs\nPress 2 : Add business of which %s is owner\nPress 3 : Add organization of which %s is member\n",sti[siz]->name.str,sti[siz]->name.str,sti[siz]->name.str);
            scanf("%d",&ty);
            if(ty==1)
            {
                printf("Enter group id :\n");
                int x;
                scanf("%d",&x);
                int flag=0;
                for(int i=0;i<*gsiz;i++)
                {
                    if(stg[i]->check)
                    {
                        if(stg[i]->id==x)
                        {
                            flag=1;

                            stg[i]->membership_individual[stg[i]->misize]=sti[siz];
                            stg[i]->misize+=1;

                            sti[siz]->membership_group[sti[siz]->mgsize]=stg[i];
                            sti[siz]->mgsize+=1;

                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node :\n");
                    int siz1 = *gsiz;
                    *gsiz = siz1+1;
                    stg[siz1] = (group*)malloc(sizeof(group));
                    scanf("%s",stg[siz1]->name.str);
                    stg[siz1]->check=1;
                    stg[siz1]->consiz=0;
                    stg[siz1]->creation=sti[siz]->creation;
                    stg[siz1]->id=x;
                    stg[siz1]->misize=1;
                    stg[siz1]->mbsize=0;
                    stg[siz1]->membership_individual[0]=sti[siz];

                    sti[siz]->membership_group[sti[siz]->mgsize]=stg[siz1];
                    sti[siz]->mgsize+=1;
                }
            }
            else if(ty==2)
            {
                int x,ch;
                printf("Enter business id:\n");
                scanf("%d",&x);
                printf("Press 1 for ownership\nPress 2 for customership\n");
                scanf("%d",&ch);
                if((ch!=1)&&(ch!=2))
                {
                    printf("Invalid choice,Please re-enter\n");
                    n++;
                    continue;
                }
                int flag=0;
                for(int i=0;i<*bsiz;i++)
                {
                    if(stb[i]->check)
                    {
                        if(stb[i]->id==x)
                        {
                            flag=1;
                            if(ch==1)
                            {
                                stb[i]->owner_individual[stb[i]->oisize]=sti[siz];
                                stb[i]->oisize+=1;

                                sti[siz]->ownership_business[sti[siz]->obsize]=stb[i];
                                sti[siz]->obsize+=1;
                            }
                            else 
                            {
                                stb[i]->customer_individual[stb[i]->oisize]=sti[siz];
                                stb[i]->cisize+=1;

                                sti[siz]->customership_business[sti[siz]->cbsize]=stb[i];
                                sti[siz]->cbsize+=1;
                            }
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node :\n");
                    int siz1 = *bsiz;
                    *bsiz = siz1+1;
                    stb[siz1] = (business*)malloc(sizeof(group));
                    scanf("%s",stb[siz1]->name.str);
                    stb[siz1]->check=1;
                    stb[siz1]->consiz=0;
                    stb[siz1]->creation=sti[siz]->creation;
                    stb[siz1]->id=x;
                    stb[siz1]->mgsize=0;
                    stb[siz1]->cisize=0;
                    stb[siz1]->oisize=0;
                    if(ch==1)
                    {
                        stb[siz1]->owner_individual[stb[siz1]->oisize]=sti[siz];
                        stb[siz1]->oisize+=1;

                        sti[siz]->ownership_business[sti[siz]->obsize]=stb[siz1];
                        sti[siz]->obsize+=1;
                    }
                    else 
                    {
                        stb[siz1]->customer_individual[stb[siz1]->oisize]=sti[siz];
                        stb[siz1]->cisize+=1;

                        sti[siz]->customership_business[sti[siz]->cbsize]=stb[siz1];
                        sti[siz]->cbsize+=1;
                    }
                }
            }
            else if(ty==3)
            {
                printf("Enter organisation id :\n");
                int x;
                scanf("%d",&x);
                int flag=0;
                for(int i=0;i<*osiz;i++)
                {
                    if(sto[i]->check)
                    {
                        if(sto[i]->id==x)
                        {
                            flag=1;

                            sto[i]->membership_individual[sto[i]->misize]=sti[siz];
                            sto[i]->misize+=1;

                            sti[siz]->membership_organizations[sti[siz]->mosize]=sto[i];
                            sti[siz]->mosize+=1;
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node to create it:\n");
                    int siz1 = *osiz;
                    *osiz = siz1+1;
                    sto[siz1] = (org*)malloc(sizeof(group));
                    scanf("%s",sto[siz1]->name.str);
                    sto[siz1]->check=1;
                    sto[siz1]->consiz=0;
                    sto[siz1]->creation=sti[siz]->creation;
                    sto[siz1]->id=x;
                    sto[siz1]->misize=1;
                    sto[siz1]->membership_individual[0]=sti[siz];

                    sti[siz]->membership_organizations[sti[siz]->mosize]=sto[siz1];
                    sti[siz]->mosize+=1;
                }
            }
            else
            {
                printf("Invalid Choice , Please re-enter\n");
                n++;
            }
        }
        print_node(1,sti[siz],NULL,NULL,NULL);
    }
    else if(type==2)
    {
        
    }
    else if(type==3)
    {

    }
    else if(type==4)
    {

    }
    else
    {
        printf("Invalid choice\n");
        return;
    }
}

//1
void delete_node(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz,int type)
{
    int x;
    printf("Enter id of node to delete :\n");
    scanf("%d",&x);
    for(int i=0;i<*isiz;i++)
    {
        if(sti[i]->check)
        {
            if(sti[i]->id==x)
            {
                sti[i]->check=0;
                printf("Node successfully deleted\n");
                return;
            }
        }
    }
    for(int i=0;i<*bsiz;i++)
    {
        if(stb[i]->check)
        {
            if(stb[i]->id==x)
            {
                stb[i]->check=0;
                printf("Node successfully deleted\n");
                return;
            }
        }
    }
    for(int i=0;i<*gsiz;i++)
    {
        if(stg[i]->check)
        {
            if(stg[i]->id==x)
            {
                stg[i]->check=0;
                printf("Node successfully deleted\n");
                return;
            }
        }
    }
    for(int i=0;i<*osiz;i++)
    {
        if(sto[i]->check)
        {
            if(sto[i]->id==x)
            {
                sto[i]->check=0;
                printf("Node successfully deleted\n");
                return;
            }
        }
    }
    printf("Could not find entered node\n");
}

//2
void search_node(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
{
    printf("Press 1 to search with name\nPress 2 to search with type\nPress 3 to search with birthday\n");
    int ty;
    scanf("%d",&ty);
    if(ty==1)
    {
        printf("Enter name :\n");
        string s;
        int flag=0;
        scanf("%s",s.str);
        for(int i=0;i<*isiz;i++)
        {
            if(strcmp(s.str,sti[i]->name.str))
            {
                printf("Node id : %d\n",sti[i]->id);
                flag=1;
            }
        }
        for(int i=0;i<*bsiz;i++)
        {
            if(strcmp(s.str,stb[i]->name.str))
            {
                printf("Node id : %d\n",stb[i]->id);
                flag=1;
            }
        }
        for(int i=0;i<*gsiz;i++)
        {
            if(strcmp(s.str,stg[i]->name.str))
            {
                printf("Node id : %d\n",stg[i]->id);
                flag=1;
            }
        }
        for(int i=0;i<*osiz;i++)
        {
            if(strcmp(s.str,sto[i]->name.str))
            {
                printf("Node id : %d\n",sto[i]->id);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No matching records found\n");
        }
    }
    else if(ty==2)
    {
        printf("Enter type :\n");
        scanf("%d",&ty);
        if(ty==1)
        {
            for(int i=0;i<*isiz;i++)
            {
                printf("Node id : %d\n",sti[i]->id);
            }
            printf("total : %d\n",*isiz);
        }
        else if(ty==2)
        {
            for(int i=0;i<*bsiz;i++)
            {
                printf("Node id : %d\n",stb[i]->id);
            }
            printf("total : %d\n",*bsiz);
        }
        else if(ty==3)
        {
            for(int i=0;i<*gsiz;i++)
            {
                printf("Node id : %d\n",stg[i]->id);
            }
            printf("total : %d\n",*gsiz);
        }
        else if(ty==4)
        {
            for(int i=0;i<*osiz;i++)
            {
                printf("Node id : %d\n",sto[i]->id);
            }
            printf("total : %d\n",*osiz);
        }
        else
        {
            printf("Invalid choice\n");
            return;
        }
    }
    else if(ty==3)
    {
        date temp;
        int flag=0;
        printf("Enter birthday dd mm yy:\n");
        scanf("%d%d%d",&(temp.dd),&(temp.mm),&(temp.yy));
        for(int i=0;i<*isiz;i++)
        {
            if((sti[i]->bd.dd=temp.dd)&&(sti[i]->bd.mm=temp.mm)&&(sti[i]->bd.yy=temp.yy))
            {
                printf("Node id : %d\n",sti[i]->id);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No matching records found\n");
        }
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }
}

//4
void post_content(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
{
    int x;
    printf("Enter id of node whose content is to be added\n");
    scanf("%d",&x);
    for(int i=0;i<*isiz;i++)
    {
        if(sti[i]->check)
        {
            if(sti[i]->id==x)
            {
                printf("Enter content to enter\n");
                scanf("%s",sti[i]->contents[sti[i]->consiz].str);
                sti[i]->consiz += 1;
                for(int j=0;j<sti[i]->consiz-1;j++)
                {
                    if(strcmp(sti[i]->contents[j].str,sti[i]->contents[sti[i]->consiz-1].str))
                    {
                        sti[i]->consiz -=1;
                        break;
                    }
                }
                return;
            }
        }
    }

    for(int i=0;i<*bsiz;i++)
    {
        if(stb[i]->check)
        {
            if(stb[i]->id==x)
            {
                printf("Enter content to enter\n");
                scanf("%s",stb[i]->contents[stb[i]->consiz].str);
                stb[i]->consiz += 1;
                for(int j=0;j<stb[i]->consiz-1;j++)
                {
                    if(strcmp(stb[i]->contents[j].str,stb[i]->contents[stb[i]->consiz-1].str))
                    {
                        stb[i]->consiz -=1;
                        break;
                    }
                }
                return;
            }
        }
    }

    for(int i=0;i<*gsiz;i++)
    {
        if(stg[i]->check)
        {
            if(stg[i]->id==x)
            {
                printf("Enter content to enter\n");
                scanf("%s",stg[i]->contents[stg[i]->consiz].str);
                stg[i]->consiz += 1;
                for(int j=0;j<stg[i]->consiz-1;j++)
                {
                    if(strcmp(stg[i]->contents[j].str,stg[i]->contents[stg[i]->consiz-1].str))
                    {
                        stg[i]->consiz -=1;
                        break;
                    }
                }
                return;
            }
        }
    }

    for(int i=0;i<*osiz;i++)
    {
        if(sto[i]->check)
        {
            if(sto[i]->id==x)
            {
                printf("Enter content to enter\n");
                scanf("%s",sto[i]->contents[sto[i]->consiz].str);
                sto[i]->consiz += 1;
                for(int j=0;j<sto[i]->consiz-1;j++)
                {
                    if(strcmp(sto[i]->contents[j].str,sto[i]->contents[sto[i]->consiz-1].str))
                    {
                        sto[i]->consiz -=1;
                        break;
                    }
                }
                return;
            }
        }
    }
    printf("Node does note exist , first create node\n");
}

//5
void search_content(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
{
    printf("Enter content to search :\n");
    string temp;
    scanf("%s",temp.str);
}