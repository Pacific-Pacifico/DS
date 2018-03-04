#include<stdio.h>
#include<stdlib.h>
#include"insert.c"
#include"delete.c"
#include"create.c"
#include"display.c"
#include"count.c"
#include"search.c"
#include"reverse.c"

struct node *create_list(struct node *);
void display(struct node *);
void count(struct node *);
void search(struct node *,int);
struct node *ins_beg(struct node *,int);
struct node *ins_end(struct node *,int);
struct node *ins_after(struct node *,int);
struct node *ins_before(struct node *,int);
struct node *ins_pos(struct node *,int,int);
struct node *del_pos(struct node *,int);
struct node *reverse(struct node *);
