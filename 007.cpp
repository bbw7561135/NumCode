//C primer plus在学完结构后 链表上线
//结构中不能含有与本身类型相同的结构 但可以包含指向同类型结构的指针！
#include <stdio.h>
#include <stdlib.h> //malloc()
#include <string.h> //strcpy()

#define TSIZE 50

struct film
{
    char title[TSIZE];
    int rating;
    struct film * next;
};

char * s_get(char * st, int n) //get name and rating
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!='\n')
                continue;//这段处理字符串输入可见Cprimerplus字符串章节
    }
    return ret_val;
}




int main()
{

    struct film * head = NULL;
    struct film * previous;
    struct film * current;
    char input[TSIZE];

    //collect data
    puts("Enter first movie title: ");
    while(s_get(input,TSIZE)!=NULL && input[0]!='\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if(head==NULL) //first struct
            head = current;
        else
            previous->next = current; //subsequent struct
        current->next = NULL;//for the moment it is the final struct
        strcpy(current->title,input);
        puts("Enter the rating<0-10>: ");
        scanf("%d",&current->rating);//==&(current-rating)
        while(getchar()!='\n')
            continue;
        puts("Enter the next film title (empty line to stop): ");
        previous = current;//p指向最后个结构 c准备迎接新成员
        //此时p.next= NULL
    }

    //show link
    if(head==NULL)
        printf("No data entered.");
    else
        printf("Here is the movie list :\n");
    current = head;
    while(current != NULL)
    {
        printf("Movie: %s.  Rating: %d\n",current->title,current->rating);
        current = current->next;
    }

    //free the memory
    current = head;
    while(current != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    printf("Bye.\n");

    return 0;
}




