#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
 
// A structure to represent a queue

struct Address {
char name[30];
char phone[30];
char email[30];
};

void outAddress(struct Address a)
{
	printf("\nName: %s",a.name);
	printf("Phone number: %s",a.phone);
	printf("Email: %s",a.email);
	printf("\n");

}
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Address* list;
};


struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    queue->rear = capacity - 1;
    queue->list = (struct Address*)malloc(
        queue->capacity * sizeof(struct Address));
    return queue;
}
 

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
 

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

struct Address front(struct Queue* queue)
{
    struct Address nothing;
    if (isEmpty(queue))
        return nothing;
    return queue->list[queue->front];
}

struct Address dequeue(struct Queue* queue)
{
    struct Address nothing;
    if (isEmpty(queue))
        return nothing;
    struct Address item = queue->list[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
void enqueue(struct Queue* queue, struct Address a)
{
    if (isFull(queue))
    {
    	printf("\nThis address is removed\n");
    	outAddress(front(queue));
    	dequeue(queue);
	}
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->list[queue->rear] = a;
    queue->size = queue->size + 1;
}
void modify(struct Queue* queue,struct Address a )
{
    queue->list[queue->front] = a;
}

void input_address(struct Address*a)
{
	printf("Input name: ");
    fgets(a->name,30,stdin);
    printf("Input phone number: ");
    fgets(a->phone,30,stdin);
    printf("Input email: ");
    fgets(a->email,30,stdin);
}
int search(struct Address arr[], int n, char x[])
{
    int i;
    for (i = 0; i < n; i++) {
		char* cmp = strtok(arr[i].name, "\n");
		if (strcmp(cmp, x) == 0)
            return i;
	}

    return -1;
}
void readFile(const char*fname, struct Address a[], int* n)
{
    FILE*f=fopen(fname,"rt");
	if(f==NULL)
		return;
	else
	{
		int i=0;
		while(!feof(f))
		{
			fgets(a[i].name,30,f);
			fgets(a[i].phone,30,f);
			fgets(a[i].email,30,f);
			fscanf(f,"\n");
			i++;
		}
		*n=i;		
	}
    fclose(f);
}
void sort_name(struct Address a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].name[0]>a[j].name[0])
			{
				struct Address temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	struct Queue* queue = createQueue(10);
	struct Address a[10];
	char x[30];
	int n;
	readFile("input.txt",a,&n);
	printf("\nAfter sort by name\n");
	sort_name(a,n);
	int i;
	for(i=0;i<n;i++)
	{
		enqueue(queue,a[i]);
	}
	struct Address b;
	input_address(&b);
	enqueue(queue,b);
	printf("\n=====================");
	printf("\nEnter name to search: ");
	gets(x);
	printf("Searching...\n");
    int idx = search(a, n, x);
    if (idx == -1)
        printf("Not found this name!\n");
    else {
        printf("Found\n");
        outAddress(a[idx]);
    }
	
    return 0;
}
