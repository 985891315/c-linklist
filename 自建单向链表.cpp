#include<stdio.h>
#include<stdlib.h>//mallocͷ���� 
#include<string.h>
/*
�������ȱ�� 
û��д���������� ֻ��ʹ��һ��������� 
û��д ���������� 
*/

//����ṹ�� �������ݺ�nextָ�� 
typedef struct student{
	int score;
	int long num;
	char name[20];
	struct student *next;
}STU;

STU *head;//ͷ��ַ����Ϊȫ�ֱ��� 

    void a_scanf();//�������ݺ��� 
	void link_cod(STU **head,STU *a_new);//�����½ڵ㵽������ 
	void a_printf(STU *head);//�����ӡ������ 
	int a_find(STU* head);//����ѧ�Ų��� 
	void a_line_up(STU* head);//���ճɼ��Ӵ�С���� 
	void link_delete(STU **head);//�����ɾ�� (ͨ��ѧ��ɾ��)

int main()
{
	int a=0;
	printf("��ѡ����Ӧ���������֣�\n");
	printf("1.��������\n");
	printf("2.��ӡ����\n");
	printf("3.����ѧ����Ϣ\n");
	printf("4.ɾ��ѧ����Ϣ\n");
	printf("5.�˳�\n");
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
void link_delete(STU **head)//�����ɾ�� (ͨ��ѧ��ɾ��)
{
	STU *pf=*head,*pd;
	long int n=0;
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%ld",&n);
	if(*head==NULL){
		printf("������Ϊ�գ��޷�ɾ����");
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
		printf("��Ҫɾ����ѧ�����ݲ�����"); 
	}
}

void a_line_up(STU* head)//���ճɼ��Ӵ�С���� 
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
				strcpy(temp.name,pf->name);  //ע��ע���ַ�����δ�ֵ 
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
int a_find(STU* head)//����ѧ�Ų��� 
{
	int long num;
	STU *move=head;
	printf("������ѧ�ţ�");
	scanf("%ld",&num);
	while(move){
		if(move->num==num){
			printf("�ҵ���");
			printf("������%s ѧ�ţ�%ld,����:%d",move->name,move->num,move->score);
			break;
		}else{
			printf("û���ҵ���ѧ��"); 
			break;
		}
	}
}
void a_scanf()//�����������ݺ��� 
{
	STU *a_new=NULL;
	int i=0;
	int n=0;
	printf("Ҫ���뼸������\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a_new=(STU*)malloc(sizeof(STU));
		printf("�������%d�����ݣ�\n����  ѧ��  ����\n",i+1);
		scanf("%s %ld %d",&a_new->name,&a_new->num,&a_new->score);
		link_cod(&head,a_new);
	}
	
}

void link_cod(STU **head,STU *a_new)//�����½ڵ㵽������ 
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
void a_printf(STU *head)//���������������� 
{
	STU *move=head;
	printf("���� ѧ�� �÷�\n");
	while(move!=NULL){
		printf("%s   %ld   %d\n",move->name,move->num,move->score);
		move=move->next;
	}
}

