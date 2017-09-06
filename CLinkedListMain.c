#include <stdio.h>
#include "CLinkedList.h"
#include <stdlib.h>

Emp*duty(List *plist, char *name, int day);
void show(Emp*emp);

int main(void)
{
	List list;
	int data, i, nodeNum;
	emp *worker;
	ListInit(&list);

	worker = (emp*)malloc(sizeof(emp));
	strcpy(worker->name,"±è¿õ±â");
	worker->wnum = 100;
	worker->order = 1;
	LInsert(&list, worker);
	
	worker = (emp*)malloc(sizeof(emp));
	strcpy(worker->name, "È÷È÷È÷");
	worker->wnum = 59;
	worker->order = 2;
	LInsert(&list, worker);

	worker = (emp*)malloc(sizeof(emp));
	strcpy(worker->name, "Å°Å°Å°");
	worker->wnum = 15;
	worker->order = 3;
	LInsert(&list, worker);


	worker = duty(&list, "±è¿õ±â", 5);
	show(worker);

	worker = duty(&list, "È÷È÷È÷", 6);
	show(worker);

	if (LFirst(&list, &worker))
	{
		free(worker);
		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &worker))
				free(worker);
		}
	}

	getch();
	return 0;
}

Emp*duty(List *plist, char *name, int day)
{
	int i, num;
	Emp *ret;
	num = LCount(plist);

	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret);
			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i >= num - 1)
			return NULL;
	}

	for (i = 0; i < day; i++)
		LNext(plist, &ret);
	return ret;
}

void show(Emp*emp)
{
	printf("name: %s\n", emp->name);
	printf("number: %d\n", emp->wnum);
}