#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int ItemType;
struct SNode
{
	ItemType info;
	SNode *next;
};
struct SList
{
	SNode *head;
	SNode *tail;
};

void initSLNode(SList &sl)
{
	sl.head = NULL;
	sl.tail = NULL;
}
SNode *createSNode(ItemType x)
{
	SNode *p = new SNode;
	if (p == NULL)
	{
		printf("Khong du bo nho");
		getch();
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
bool isEmpty(SList sl)
{
	if (sl.head == NULL) return true;
	else return false;
}

int addValue(SList &sl, SNode *p)
{
	if (p == NULL) return 0;
	if (isEmpty(sl))
	{
		sl.head = p;
		sl.tail = p;
	}
	else {
		sl.tail->next = p;
		sl.tail = p;
	}
	return 1;
}
template<class T>
void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
bool compare_asc(const void *a, const void *b)
{
	SNode * n1 = (SNode *)a;
	SNode * n2 = (SNode *)b;
	return n1->info > n2->info;
}
void SelectionSort(SList &sl, bool(*compare)(const void *, const void *))
{
	for (SNode *i = sl.head; i <= sl.tail; i = i->next)
	{
		for (SNode *j = i+1; j != NULL; j = j->next)
		{
			if (compare(i, j))
			{
				swap(i, j);
			}
		}
	}
}
void createSListNode(SList &sl)
{
	int n;
	ItemType x;
	FILE *f;
	if (!(f=fopen("input.txt", "r")))
	{
		printf("ERROR");
		exit(1);
	}
	initSLNode(sl);
	fscanf(f, "%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		fscanf(f, "%d", &x);
		addValue(sl, createSNode(x));
	}
	fclose(f);
}
void ShowSNode(SList sl)
{
	for (SNode *i = sl.head; i != NULL; i = i->next)
	{
		printf("%d ", i->info);
	}
	printf("\n");
}
void main()
{
	SList sl;
	createSListNode(sl);
	ShowSNode(sl);
	SelectionSort(sl, compare_asc);
	ShowSNode(sl);
	getch();
}