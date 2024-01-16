#include<stdio.h>
#include"social.h"


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


void print_links(int type,individual * p1,business * p2,group * p3,org * p4)
{
    if(type==1)
    {
        if(p1->check==0)
        {
            return;
        }
        int ct=0;
        printf("Groups of which %s is a member (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->mgsize;i++)
        {
            group * temp = p1->membership_group[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);

        ct=0;
        printf("Business of which %s is a owner (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->obsize;i++)
        {
            business * temp = p1->ownership_business[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);

        ct=0;
        printf("Business of which %s is a customer (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->cbsize;i++)
        {
            business * temp = p1->customership_business[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);

        ct=0;
        printf("Organisations of which %s is a member (ID , Name) :\n",p1->name.str);
        for(int i=0;i<p1->mosize;i++)
        {
            org * temp = p1->membership_organizations[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);
    }
    else if(type==2)
    {
        if(p2->check==0)
        {
            return;
        }
        int ct=0;
        printf("Individuals who are owner of %s (ID , Name) :\n",p2->name.str);
        for(int i=0;i<p2->oisize;i++)
        {
            individual * temp = p2->owner_individual[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);

        ct=0;
        printf("Individuals who are customer of %s (ID , Name) :\n",p2->name.str);
        for(int i=0;i<p2->cisize;i++)
        {
            individual * temp = p2->customer_individual[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);

        ct=0;
        printf("Groups of which %s is a member (ID , Name) :\n",p2->name.str);
        for(int i=0;i<p2->mgsize;i++)
        {
            group * temp = p2->membership_group[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);
    }
    else if(type==3)
    {
        if(p3->check==0)
        {
            return;
        }
        int ct=0;
        printf("Individuals who are member of %s (ID , Name) :\n",p3->name.str);
        for(int i=0;i<p3->misize;i++)
        {
            individual * temp = p3->membership_individual[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);

        ct=0;
        printf("Business which are member of %s (ID , Name) :\n",p3->name.str);
        for(int i=0;i<p3->mbsize;i++)
        {
            business * temp = p3->membership_business[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);
    }
    else if(type==4)
    {
        if(p4->check==0)
        {
            return;
        }
        int ct=0;
        printf("Individuals who are member of %s (ID , Name) :\n",p4->name.str);
        for(int i=0;i<p4->misize;i++)
        {
            individual * temp = p4->membership_individual[i];
            if(temp->check)
            {
                printf("%d %s\n",temp->id,temp->name.str);
                ct++;
            }
        }
        printf("Total count : %d\n",ct);
    }
    else
    {
        printf("Invalid type\n");
    }
    return;
}


void print_1_hop(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
{
    int x;
    printf("Enter ID of node whose 1 hop neighbors are to be printed : ");
    scanf("%d",&x);

    for(int i=0;i<*isiz;i++)
    {
        if(sti[i]->check)
        {
            if(sti[i]->id==x)
            {
                print_links(1,sti[i],NULL,NULL,NULL);
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
                print_links(2,NULL,stb[i],NULL,NULL);
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
                print_links(3,NULL,NULL,stg[i],NULL);
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
                print_links(4,NULL,NULL,NULL,sto[i]);
                return;
            }
        }
    }

    printf("Entered Node does not exist\n");
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

        printf("2D coordinate : (%d,%d)\n",p2->coord.x,p2->coord.y);
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

        printf("2D coordinate : (%d,%d)\n",p4->coord.x,p4->coord.y);   
    }
}

void make_link(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
{
    printf("Press 1 to add link between individual and any business , group , organisation\n");
    printf("Press 2 to add link between business and any individual , group\n");
    printf("Press 3 to add link between group and any individual , business\n");
    printf("Press 4 to add link between organisation and any individual\n");
    int ty;
    scanf("%d",&ty);
    if(ty==1)
    {
        printf("Enter Individual ID :");
        int id;
        scanf("%d",&id);
        individual * temp=NULL;
        for(int i=0;i<*isiz;i++)
        {
            if(sti[i]->check)
            {
                if(sti[i]->id==id)
                {
                    temp=sti[i];
                    break;
                }
            }
        }
        if(temp==NULL)
        {
            printf("Node does not exist\n");
        }
        else
        {
            int ty;
            printf("Enter type of link :\n");
            printf("Press 1 : Add group to which %s belongs\nPress 2 : Add business of which %s is owner or customer\nPress 3 : Add organization of which %s is member\n",temp->name.str,temp->name.str,temp->name.str);
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

                            stg[i]->membership_individual[stg[i]->misize]=temp;
                            stg[i]->misize+=1;

                            temp->membership_group[temp->mgsize]=stg[i];
                            temp->mgsize+=1;

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
                    stg[siz1]->creation=temp->creation;
                    stg[siz1]->id=x;
                    stg[siz1]->misize=1;
                    stg[siz1]->mbsize=0;
                    stg[siz1]->membership_individual[0]=temp;

                    temp->membership_group[temp->mgsize]=stg[siz1];
                    temp->mgsize+=1;
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
                    printf("Invalid choice\n");
                    return;
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
                                stb[i]->owner_individual[stb[i]->oisize]=temp;
                                stb[i]->oisize+=1;

                                temp->ownership_business[temp->obsize]=stb[i];
                                temp->obsize+=1;
                            }
                            else 
                            {
                                stb[i]->customer_individual[stb[i]->cisize]=temp;
                                stb[i]->cisize+=1;

                                temp->customership_business[temp->cbsize]=stb[i];
                                temp->cbsize+=1;
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
                    stb[siz1] = (business*)malloc(sizeof(business));
                    scanf("%s",stb[siz1]->name.str);
                    printf("Enter coordinate (x,y) of %s :\n",stb[siz1]->name.str);
                    scanf("%d%d",&(stb[siz1]->coord.x),&(stb[siz1]->coord.y));
                    stb[siz1]->check=1;
                    stb[siz1]->consiz=0;
                    stb[siz1]->creation=temp->creation;
                    stb[siz1]->id=x;
                    stb[siz1]->mgsize=0;
                    stb[siz1]->cisize=0;
                    stb[siz1]->oisize=0;
                    if(ch==1)
                    {
                        stb[siz1]->owner_individual[stb[siz1]->oisize]=temp;
                        stb[siz1]->oisize+=1;

                        temp->ownership_business[temp->obsize]=stb[siz1];
                        temp->obsize+=1;
                    }
                    else 
                    {
                        stb[siz1]->customer_individual[stb[siz1]->cisize]=temp;
                        stb[siz1]->cisize+=1;

                        temp->customership_business[temp->cbsize]=stb[siz1];
                        temp->cbsize+=1;
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

                            sto[i]->membership_individual[sto[i]->misize]=temp;
                            sto[i]->misize+=1;

                            temp->membership_organizations[temp->mosize]=sto[i];
                            temp->mosize+=1;
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node to create it:\n");
                    int siz1 = *osiz;
                    *osiz = siz1+1;
                    sto[siz1] = (org*)malloc(sizeof(org));
                    scanf("%s",sto[siz1]->name.str);
                    printf("Enter coordinate (x,y) of %s :\n",sto[siz1]->name.str);
                    scanf("%d%d",&(sto[siz1]->coord.x),&(sto[siz1]->coord.y));
                    sto[siz1]->check=1;
                    sto[siz1]->consiz=0;
                    sto[siz1]->creation=temp->creation;
                    sto[siz1]->id=x;
                    sto[siz1]->misize=1;
                    sto[siz1]->membership_individual[0]=temp;

                    temp->membership_organizations[temp->mosize]=sto[siz1];
                    temp->mosize+=1;
                }
            }
            else
            {
                printf("Invalid Choice\n");
            }
        }
    }
    else if(ty==2)
    {
        printf("Enter business ID :");
        int id;
        scanf("%d",&id);
        business * temp=NULL;
        for(int i=0;i<*bsiz;i++)
        {
            if(stb[i]->check)
            {
                if(stb[i]->id==id)
                {
                    temp=stb[i];
                    break;
                }
            }
        }
        if(temp==NULL)
        {
            printf("Node does not exist\n");
        }
        else
        {
            int ty;
            printf("Enter type of link :\n");
            printf("Press 1 : Add individual as a owner or cutomer of %s \nPress 2 : Add groups of which %s is a member\n",temp->name.str,temp->name.str);
            scanf("%d",&ty);
            if(ty==1)
            {
                int x,ch;
                printf("Enter individual id:\n");
                scanf("%d",&x);
                printf("Press 1 for ownership\nPress 2 for customership\n");
                scanf("%d",&ch);
                if((ch!=1)&&(ch!=2))
                {
                    printf("Invalid choice\n");
                    return;
                }
                int flag=0;
                for(int i=0;i<*isiz;i++)
                {
                    if(sti[i]->check)
                    {
                        if(sti[i]->id==x)
                        {
                            flag=1;
                            if(ch==1)
                            {
                                sti[i]->ownership_business[sti[i]->obsize]=temp;
                                sti[i]->obsize+=1;

                                temp->owner_individual[temp->oisize]=sti[i];
                                temp->oisize+=1;
                            }
                            else 
                            {
                                sti[i]->customership_business[sti[i]->cbsize]=temp;
                                sti[i]->cbsize+=1;

                                temp->customer_individual[temp->cisize]=sti[i];
                                temp->cisize+=1;
                            }
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node :\n");
                    int siz1 = *isiz;
                    *isiz = siz1+1;
                    sti[siz1] = (individual*)malloc(sizeof(individual));
                    scanf("%s",sti[siz1]->name.str);
                    printf("Enter birthday of %s in dd mm yy form :\n",sti[siz1]->name.str);
                    scanf("%d%d%d",&(sti[siz1]->bd.dd),&(sti[siz1]->bd.mm),&(sti[siz1]->bd.yy));
                    sti[siz1]->check=1;
                    sti[siz1]->consiz=0;
                    sti[siz1]->creation=temp->creation;
                    sti[siz1]->id=x;
                    sti[siz1]->mgsize=0;
                    sti[siz1]->obsize=0;
                    sti[siz1]->mosize=0;
                    sti[siz1]->cbsize=0;
                    if(ch==1)
                    {
                        sti[siz1]->ownership_business[sti[siz1]->obsize]=temp;
                        sti[siz1]->obsize+=1;

                        temp->owner_individual[temp->oisize]=sti[siz1];
                        temp->oisize+=1;
                    }
                    else 
                    {
                        sti[siz1]->customership_business[sti[siz1]->cbsize]=temp;
                        sti[siz1]->cbsize+=1;

                        temp->customer_individual[temp->cisize]=sti[siz1];
                        temp->cisize+=1;
                    }
                }
            }
            else if(ty==2)
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

                            stg[i]->membership_business[stg[i]->mbsize]=temp;
                            stg[i]->mbsize+=1;

                            temp->membership_group[temp->mgsize]=stg[i];
                            temp->mgsize+=1;
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node to create it:\n");
                    int siz1 = *gsiz;
                    *gsiz = siz1+1;
                    stg[siz1] = (group*)malloc(sizeof(group));
                    scanf("%s",stg[siz1]->name.str);
                    stg[siz1]->check=1;
                    stg[siz1]->consiz=0;
                    stg[siz1]->creation=temp->creation;
                    stg[siz1]->id=x;
                    stg[siz1]->misize=0;
                    stg[siz1]->mbsize=1;
                    stg[siz1]->membership_business[0]=temp;

                    temp->membership_group[temp->mgsize]=stg[siz1];
                    temp->mgsize+=1;
                }
            }
            else
            {
                printf("Invalid Choice\n");
            }
        }
    }
    else if(ty==3)
    {
        printf("Enter group ID :");
        int id;
        scanf("%d",&id);
        group * temp=NULL;
        for(int i=0;i<*gsiz;i++)
        {
            if(stg[i]->check)
            {
                if(stg[i]->id==id)
                {
                    temp=stg[i];
                    break;
                }
            }
        }
        if(temp==NULL)
        {
            printf("Node does not exist\n");
        }
        else
        {
            int ty;
            printf("Enter type of link :\n");
            printf("Press 1 : Add individual as member of %s \nPress 2 : Add business as member of %s\n",temp->name.str,temp->name.str);
            scanf("%d",&ty);
            if(ty==1)
            {
                printf("Enter individual id :\n");
                int x;
                scanf("%d",&x);
                int flag=0;
                for(int i=0;i<*isiz;i++)
                {
                    if(sti[i]->check)
                    {
                        if(sti[i]->id==x)
                        {
                            flag=1;

                            sti[i]->membership_group[sti[i]->mgsize]=temp;
                            sti[i]->mgsize+=1;

                            temp->membership_individual[temp->misize]=sti[i];
                            temp->misize+=1;
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node to create it:\n");
                    int siz1 = *isiz;
                    *isiz = siz1+1;
                    sti[siz1] = (individual*)malloc(sizeof(individual));
                    scanf("%s",sti[siz1]->name.str);
                    printf("Enter birthday of %s in dd mm yy form :\n",sti[siz1]->name.str);
                    scanf("%d%d%d",&(sti[siz1]->bd.dd),&(sti[siz1]->bd.mm),&(sti[siz1]->bd.yy));
                    sti[siz1]->check=1;
                    sti[siz1]->consiz=0;
                    sti[siz1]->creation=temp->creation;
                    sti[siz1]->id=x;
                    sti[siz1]->mgsize=1;
                    sti[siz1]->obsize=0;
                    sti[siz1]->mosize=0;
                    sti[siz1]->cbsize=0;
                    sti[siz1]->membership_group[0]=temp;

                    temp->membership_individual[temp->misize]=sti[siz1];
                    temp->misize += 1;
                }
            }
            else if(ty==2)
            {
                printf("Enter business id :\n");
                int x;
                scanf("%d",&x);
                int flag=0;
                for(int i=0;i<*bsiz;i++)
                {
                    if(stb[i]->check)
                    {
                        if(stb[i]->id==x)
                        {
                            flag=1;

                            stb[i]->membership_group[stb[i]->mgsize]=temp;
                            stb[i]->mgsize+=1;

                            temp->membership_business[temp->mbsize]=stb[i];
                            temp->mbsize+=1;
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Note : Node does not exist in Social Network currently\nEnter name of this node to create it:\n");
                    int siz1 = *bsiz;
                    *bsiz = siz1+1;
                    stb[siz1] = (business*)malloc(sizeof(business));
                    scanf("%s",stb[siz1]->name.str);
                    printf("Enter coordinate (x,y) :\n");
                    scanf("%d%d",&(stb[siz1]->coord.x),&(stb[siz1]->coord.y));
                    stb[siz1]->check=1;
                    stb[siz1]->consiz=0;
                    stb[siz1]->creation=temp->creation;
                    stb[siz1]->id=x;
                    stb[siz1]->cisize=0;
                    stb[siz1]->oisize=0;
                    stb[siz1]->mgsize=1;
                    stb[siz1]->membership_group[0]=temp;

                    temp->membership_business[temp->mbsize]=stb[siz1];
                    temp->mbsize += 1;
                }
            }
            else
            {
                printf("Invalid Choice\n");
            }
        }
    }
    else if(ty==4)
    {
        printf("Enter organisation ID :");
        int id;
        scanf("%d",&id);
        org * temp=NULL;
        for(int i=0;i<*osiz;i++)
        {
            if(sto[i]->check)
            {
                if(sto[i]->id==id)
                {
                    temp=sto[i];
                    break;
                }
            }
        }
        if(temp==NULL)
        {
            printf("Node does not exist\n");
        }
        else
        {
            printf("Enter individual ID :\n");
            int x;
            scanf("%d",&x);
            int flag=0;
            for(int i=0;i<*isiz;i++)
            {
                if(sti[i]->check)
                {
                    if(sti[i]->id==x)
                    {
                        flag=1;

                        sti[i]->membership_organizations[sti[i]->mosize]=temp;
                        sti[i]->mosize += 1;

                        temp->membership_individual[temp->misize]=sti[i];
                        temp->misize += 1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                printf("Note : Node does not exist in Social Network currently\nEnter name of this node to create it:\n");
                int siz1 = *isiz;
                *isiz = siz1+1;
                sti[siz1] = (individual*)malloc(sizeof(individual));
                scanf("%s",sti[siz1]->name.str);
                printf("Enter birthday of %s in dd mm yy form :\n",sti[siz1]->name.str);
                scanf("%d%d%d",&(sti[siz1]->bd.dd),&(sti[siz1]->bd.mm),&(sti[siz1]->bd.yy));
                sti[siz1]->check=1;
                sti[siz1]->consiz=0;
                sti[siz1]->creation=temp->creation;
                sti[siz1]->id=x;
                sti[siz1]->mgsize=0;
                sti[siz1]->obsize=0;
                sti[siz1]->mosize=1;
                sti[siz1]->cbsize=0;
                sti[siz1]->membership_organizations[0]=temp;
                temp->membership_individual[temp->misize]=sti[siz1];
                temp->misize += 1;
            }
        }
    }
    else
    {
        printf("Invalid choice\n");
    }
}

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
        sti[siz]->cbsize=0;

        printf("PRINTING ENTERED NODE :\n");
        print_node(1,sti[siz],NULL,NULL,NULL);
    }
    else if(type==2)
    {
        int siz = *bsiz;
        *bsiz = siz + 1;

        //allocating memory
        stb[siz] = (business*)malloc(sizeof(business));

        printf("Enter unique node id :\n");
        scanf("%d",&(stb[siz]->id));

        printf("Enter name :\n");
        scanf("%s",stb[siz]->name.str);

        printf("Enter today's date :\n");
        scanf("%d",&(stb[siz]->creation.dd));
        scanf("%d",&(stb[siz]->creation.mm));
        scanf("%d",&(stb[siz]->creation.yy));

        printf("Enter coordinates (x,y) :\n");
        scanf("%d%d",&(stb[siz]->coord.x),&(stb[siz]->coord.y));
        stb[siz]->check=1;
        stb[siz]->consiz=0;

        stb[siz]->cisize=0;
        stb[siz]->mgsize=0;
        stb[siz]->oisize=0;

        printf("PRINTING ENTERED NODE :\n");
        print_node(2,NULL,stb[siz],NULL,NULL);
    }
    else if(type==3)
    {
        int siz = *gsiz;
        *gsiz = siz + 1;

        //allocating memory
        stg[siz] = (group*)malloc(sizeof(group));

        printf("Enter unique node id :\n");
        scanf("%d",&(stg[siz]->id));

        printf("Enter name :\n");
        scanf("%s",stg[siz]->name.str);

        printf("Enter today's date :\n");
        scanf("%d",&(stg[siz]->creation.dd));
        scanf("%d",&(stg[siz]->creation.mm));
        scanf("%d",&(stg[siz]->creation.yy));

        stg[siz]->check=1;
        stg[siz]->consiz=0;

        stg[siz]->misize=0;
        stg[siz]->mbsize=0;

        printf("PRINTING ENTERED NODE :\n");
        print_node(3,NULL,NULL,stg[siz],NULL);
    }
    else if(type==4)
    {
        int siz = *osiz;
        *osiz = siz + 1;

        //allocating memory
        sto[siz] = (org*)malloc(sizeof(org));

        printf("Enter unique node id :\n");
        scanf("%d",&(sto[siz]->id));

        printf("Enter name :\n");
        scanf("%s",sto[siz]->name.str);

        printf("Enter today's date :\n");
        scanf("%d",&(sto[siz]->creation.dd));
        scanf("%d",&(sto[siz]->creation.mm));
        scanf("%d",&(sto[siz]->creation.yy));

        printf("Enter coordinate (x,y) :\n");
        scanf("%d%d",&(sto[siz]->coord.x),&(sto[siz]->coord.y));

        sto[siz]->check=1;
        sto[siz]->consiz=0;

        sto[siz]->misize=0;

        printf("PRINTING ENTERED NODE :\n");
        print_node(4,NULL,NULL,NULL,sto[siz]);
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }
}


void delete_node(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
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
            if(sti[i]->check)
            {
                if(strcmp(s.str,sti[i]->name.str)==0)
                {
                    printf("Node id : %d\n",sti[i]->id);
                    flag=1;
                }
            }
        }
        for(int i=0;i<*bsiz;i++)
        {
            if(stb[i]->check)
            {
                if(strcmp(s.str,stb[i]->name.str)==0)
                {
                    printf("Node id : %d\n",stb[i]->id);
                    flag=1;
                }
            }
        }
        for(int i=0;i<*gsiz;i++)
        {
            if(stg[i]->check)
            {
                if(strcmp(s.str,stg[i]->name.str)==0)
                {
                    printf("Node id : %d\n",stg[i]->id);
                    flag=1;
                }
            }
        }
        for(int i=0;i<*osiz;i++)
        {
            if(sto[i]->check)
            {
                if(strcmp(s.str,sto[i]->name.str)==0)
                {
                    printf("Node id : %d\n",sto[i]->id);
                    flag=1;
                }
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
        int ct=0;
        if(ty==1)
        {
            for(int i=0;i<*isiz;i++)
            {
                if(sti[i]->check)
                {
                    printf("Node id : %d\n",sti[i]->id);
                    ct++;
                }
            }
            printf("total : %d\n",ct);
        }
        else if(ty==2)
        {
            for(int i=0;i<*bsiz;i++)
            {
                if(stb[i]->check)
                {
                    printf("Node id : %d\n",stb[i]->id);
                    ct++;
                }
            }
            printf("total : %d\n",ct);
        }
        else if(ty==3)
        {
            for(int i=0;i<*gsiz;i++)
            {
                if(stg[i]->check)
                {
                    printf("Node id : %d\n",stg[i]->id);
                    ct++;
                }
            }
            printf("total : %d\n",ct);
        }
        else if(ty==4)
        {
            for(int i=0;i<*osiz;i++)
            {
                if(sto[i]->check)
                {
                    printf("Node id : %d\n",sto[i]->id);
                    ct++;
                }
            }
            printf("total : %d\n",ct);
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
            if(sti[i]->check&&(sti[i]->bd.dd==temp.dd)&&(sti[i]->bd.mm==temp.mm)&&(sti[i]->bd.yy==temp.yy))
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
                    if(strcmp(sti[i]->contents[j].str,sti[i]->contents[sti[i]->consiz-1].str)==0)
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
                    if(strcmp(stb[i]->contents[j].str,stb[i]->contents[stb[i]->consiz-1].str)==0)
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
                    if(strcmp(stg[i]->contents[j].str,stg[i]->contents[stg[i]->consiz-1].str)==0)
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
                    if(strcmp(sto[i]->contents[j].str,sto[i]->contents[sto[i]->consiz-1].str)==0)
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


void search_content(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
{
    printf("Enter content to search :\n");
    string temp;
    scanf("%s",temp.str);

    int ct = 0;

    for(int i=0;i<*isiz;i++)
    {
        if(sti[i]->check)
        {
            for(int j=0;j<sti[i]->consiz;j++)
            {
                if(strcmp(sti[i]->contents[j].str,temp.str)==0)
                {
                    printf("Node id : %d\n",sti[i]->id);
                    ct++;
                }
            }
        }
    }

    for(int i=0;i<*bsiz;i++)
    {
        if(stb[i]->check)
        {
            for(int j=0;j<stb[i]->consiz;j++)
            {
                if(strcmp(stb[i]->contents[j].str,temp.str)==0)
                {
                    printf("Node id : %d\n",stb[i]->id);
                    ct++;
                }
            }
        }
    }

    for(int i=0;i<*gsiz;i++)
    {
        if(stg[i]->check)
        {
            for(int j=0;j<stg[i]->consiz;j++)
            {
                if(strcmp(stg[i]->contents[j].str,temp.str)==0)
                {
                    printf("Node id : %d\n",stg[i]->id);
                    ct++;
                }
            }
        }
    }

    for(int i=0;i<*osiz;i++)
    {
        if(sto[i]->check)
        {
            for(int j=0;j<sto[i]->consiz;j++)
            {
                if(strcmp(sto[i]->contents[j].str,temp.str)==0)
                {
                    printf("Node id : %d\n",sto[i]->id);
                    ct++;
                }
            }
        }
    }
    printf("Total count : %d\n",ct);
}

//Iterates over all groups and organisations and prints all individuals linked them i.e. prints all 2 hop realtions of all pairs of individuals
void print_linked_individual(group* stg[100],org* sto[100],int * gsiz,int * osiz)
{
    for(int i=0;i<*gsiz;i++)
    {
        if(stg[i]->check)
        {
            printf("The ID's and contents of individuals linked by group %s : \n",stg[i]->name.str);
            for(int j=0;j<stg[i]->misize;j++)
            {
                if(sto[i]->membership_individual[j]->check)
                {
                    printf("%d\n",stg[i]->membership_individual[j]->id);
                    print_content(1,stg[i]->membership_individual[j],NULL,NULL,NULL);
                    printf("\n");
                }
            }
        }
    }

    for(int i=0;i<*osiz;i++)
    {
        if(sto[i]->check)
        {
            printf("The ID's and contents of individuals linked by organisation %s :\n",sto[i]->name.str);
            for(int j=0;j<sto[i]->misize;j++)
            {
                if(sto[i]->membership_individual[j]->check)
                {
                    printf("%d\n",sto[i]->membership_individual[j]->id);
                    print_content(1,sto[i]->membership_individual[j],NULL,NULL,NULL);
                    printf("\n");
                }
            }
        }
    }
}


void interface(individual* sti[100],business* stb[100],group* stg[100],org* sto[100],int * isiz,int * bsiz,int * gsiz,int * osiz)
{
    while(1)
    {
        printf("******WELCOME********\n");
        printf("Press 1 : To create a node\nPress 2 : To delete a existing node\nPress 3 : To Search for nodes using the name or type or birthday\nPress 4 : To print all 1-hop linked nodes\n");
        printf("Press 5 : To create and post content by a node\nPress 6 : Search for content posted by any node\nPress 7 : Display all contents posted by linked individual i.e. belonging to the same group or organization\n");
        printf("Press 8 : Add Link between pair of valid nodes\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter type of node to create : \n");
            printf("Press 1 : Individual\nPress 2 : Business\nPress 3 : Group\nPress 4 : Organisation\n");
            int ty;
            scanf("%d",&ty);
            if((ty<=0)||(ty>=5))
            {
                printf("Invalid choice\n");
            }
            create_node(sti,stb,stg,sto,isiz,bsiz,gsiz,osiz,ty);
        }
        else if(ch==2)
        {
            delete_node(sti,stb,stg,sto,isiz,bsiz,gsiz,osiz);
        }
        else if(ch==3)
        {
            search_node(sti,stb,stg,sto,isiz,bsiz,gsiz,osiz);
        }
        else if(ch==4)
        {
            print_1_hop(sti,stb,stg,sto,isiz,bsiz,gsiz,osiz);
        }
        else if(ch==5)
        {
            post_content(sti,stb,stg,sto,isiz,bsiz,gsiz,osiz);
        }
        else if(ch==6)
        {
            search_content(sti,stb,stg,sto,isiz,bsiz,gsiz,osiz);
        }
        else if(ch==7)
        {
            print_linked_individual(stg,sto,gsiz,osiz);
        }
        else if(ch==8)
        {
            make_link(sti,stb,stg,sto,isiz,bsiz,gsiz,osiz);
        }
        else
        {
            printf("Invalid choice\n");
        }
        int cont;
        printf("Press 1 if you want to continue else press 0\n");
        scanf("%d",&cont);
        if(cont!=1)
        {
            break;
        }
    }
}


int main()
{
    //we will be maintaining 4 arrays of pointers which will store the addresses of added nodes of each type
    individual* sti[100];int isiz=0;
    business* stb[100];int bsiz=0;
    group* stg[100];int gsiz=0;
    org* sto[100];int osiz=0;

    interface(sti,stb,stg,sto,&isiz,&bsiz,&gsiz,&osiz);

    return 0;
}