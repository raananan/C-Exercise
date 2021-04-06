#include<stdio.h>
typedef struct node
{
	int priority;
	int task_code;
	struct node *next;
}Node;
void print_list(Node * top);
Node* Update_list(Node* head);
Node* change_priority(Node* head, int tc, int tp);
Node* add_task(Node* head, int tc, int tp);

int main(){
	int task[] = { 123, 150, 150, 114, 172, 112 };
	int priority[] = { 1, 3, 3, 6, 8, 12 };
	int i;
	Node*head, *newone, *pos;
	for (i = 0; i < sizeof(task) / sizeof(task[0]); i++){
		newone = (Node*)malloc(sizeof(Node));
		newone->priority = priority[i];
		newone->task_code = task[i];
		newone->next = NULL;
		if (!i){
			head = pos = newone;
		}
		else{
			pos->next = newone;
			pos = pos->next;
		}
	}
	print_list(head);
	change_priority(head, 114, 1);
	print_list(head);
	add_task(head, 117, 1);
	print_list(head);
	while (head->next)
	{
		head = Update_list(head);
		print_list(head);
	}
	system("pause");
	return 0;
}
void print_list(Node * top){
	while (top){
		printf("%d:%d -> ", top->task_code, top->priority);
		top = top->next;
	}
	printf("NULL\n\n");
}

Node* Update_list(Node* head)
{
	Node* temp = head->next;
	free(head);
	return temp;
}



Node* change_priority(Node* head, int tc, int tp)
{
	Node* pos = head, *prev = NULL, *pos2 = head, *temp = NULL;
	while (pos->task_code != tc)
	{
		prev = pos;
		pos = pos->next;
	}
	pos->priority = tp;
	prev->next = pos->next;
	while (pos->priority < tp)
	{
		pos2->next;
	}
	temp = pos2->next;
	pos2->next = pos;
	pos->next = temp;
}

Node* add_task(Node* head, int tc, int tp)
{
	Node* pos = head, *prev = NULL, *pos2 = head, *temp = NULL;
	while (pos->priority < tp)
	{
		pos2->next;
	}
	Node* newone = (Node*)malloc(sizeof(Node));
	newone->priority = tp;
	newone->task_code = tc;
	temp = pos2->next;
	pos2->next = newone;
	newone->next = temp;
}