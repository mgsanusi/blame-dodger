#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct list
{
	int i;
	int n;
	struct list *next;
};

int compar(const void * a, const void * b)
{
	return *(int*)a - *(int*)b;
}

void add(int x, struct list **l)
{
	if(*l==NULL)
	{
		*l=(struct list*)malloc(sizeof(struct list));
		(*l)->i = x;	
		(*l)->n = 1;
		(*l)->next = NULL;	
	}
	else if((*l)->i==x)
	{
		((*l)->n) ++;
	}
	else
	{
		add(x, &((*l)->next));
	}
	return;
}

void rfree(struct list **l)
{
	if(*l==NULL)
		return;
	if((*l)->next!=NULL)
		rfree(&((*l)->next));
	free(*l);
	return;
}

int main()
{
	int t, n, i, j, k, x, tab[MAX];
	struct list *l=NULL, *p=NULL;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<2*n-1;j++)
		{
			for(k=0;k<n;k++)
			{
				scanf("%d",&x);
				add(x,&l);
			}
		}
		for(p=l,j=0;p!=NULL;p=p->next)
		{
			if(p->n %2 == 1)
			{
				tab[j]=p->i;
				j++;
			}
		}
		qsort(tab, j, sizeof(int),compar);
		printf("Case #%d: ",i+1);
		for(k=0;k<j;k++)
			printf("%d ",tab[k]);
		printf("\n");
		rfree(&l);
		l=NULL;
		
	}
	return 0;
}
