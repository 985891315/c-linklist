#include<stdio.h>
#include<stdlib.h>//malloc头函数 
#include<string.h>
/*
本代码的缺点 
没有写创建链表函数 只能使用一个链表操作 
没有写 保存链表函数 
*/

//定义结构体 放入数据和next指针 
typedef struct student{
	int score;
	int long num;
	char name[20];
	struct student *next;
}STU;

STU *head;//头地址设置为全局变量 

    void a_scanf();//输入数据函数 
	void link_cod(STU **head,STU *a_new);//链接新节点到链表函数 
	void a_printf(STU *head);//逐个打印链表函数 
	int a_find(STU* head);//按照学号查找 
	void a_line_up(STU* head);//按照成绩从大到小排序 
	void link_delete(STU **head);//链表的删除 (通过学号删除)

int main()
{
	int a=0;
	printf("请选择相应操作的数字：\n");
	printf("1.输入数据\n");
	printf("2.打印所有\n");
	printf("3.查找学生信息\n");
	printf("4.删除学生信息\n");
	printf("5.退出\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:a_scanf(),main();
		break;
		case 2:a_printf(head),main();
		break;
		case 3:a_find(head),main();
		break;
		case 4:link_delete(&head),main();
		break;
		case 5:break;
		default :break;
	} 
	return 0;
	
	
}
void link_delete(STU **head)//链表的删除 (通过学号删除)
{
	STU *pf=*head,*pd;
	long int n=0;
	printf("请输入要删除学生的学号：");
	scanf("%ld",&n);
	if(*head==NULL){
		printf("此链表为空，无法删除。");
	}
	while(pf->num!=n&&pf->next!=NULL){
		pd=pf;
		pf=pf->next;
		printf("00000");
	}
	if(pf->num==n){
		if(pf==*head){
			*head=pf->next;
		}else{
			pd->next=pf->next;
		}
		free(pf);
		pf=NULL;
	}else{
		printf("您要删除的学生数据不存在"); 
	}
}

void a_line_up(STU* head)//按照成绩从大到小排序 
{

	STU* pf;
	STU* pb=head;
	STU temp=*pb;
	pf=pb->next;
	while(pb!=NULL)
	{
		pf=pb->next;
		while(pf!=NULL)
		{	
			if(pb->score<pf->score){
				strcpy(temp.name,pf->name);  //注意注意字符串如何传值 
				temp.num=pf->num;
				temp.score=pf->score;
				strcpy(pf->name,pb->name);
				pf->num=pb->num;
				pf->score=pb->score;
				strcpy(pb->name,temp.name); 
				pb->num=temp.num;
				pb->score=temp.score;
			}
		    pf=pf->next;
		}
		pb=pb->next;	
	}
 } 
int a_find(STU* head)//按照学号查找 
{
	int long num;
	STU *move=head;
	printf("请输入学号：");
	scanf("%ld",&num);
	while(move){
		if(move->num==num){
			printf("找到了");
			printf("姓名：%s 学号：%ld,分数:%d",move->name,move->num,move->score);
			break;
		}else{
			printf("没有找到此学生"); 
			break;
		}
	}
}
void a_scanf()//输入链表数据函数 
{
	STU *a_new=NULL;
	int i=0;
	int n=0;
	printf("要输入几个数据\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a_new=(STU*)malloc(sizeof(STU));
		printf("请输入第%d个数据：\n姓名  学号  分数\n",i+1);
		scanf("%s %ld %d",&a_new->name,&a_new->num,&a_new->score);
		link_cod(&head,a_new);
	}
	
}

void link_cod(STU **head,STU *a_new)//链接新节点到链表函数 
{
	STU *move=*head;
	if(*head==NULL){
		*head=a_new;
		a_new->next=NULL;
	}else{
		while(move->next!=NULL){
			move=move->next;
		}
		move->next=a_new;
		a_new->next=NULL;
	}
}
void a_printf(STU *head)//逐个输出链表内数据 
{
	STU *move=head;
	printf("姓名 学号 得分\n");
	while(move!=NULL){
		printf("%s   %ld   %d\n",move->name,move->num,move->score);
		move=move->next;
	}
}

