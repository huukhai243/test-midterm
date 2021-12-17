#include<stdio.h>
#include<string.h>

struct Address {
char name[30];
char phone[30];
char email[30];
};
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
void outAddress(struct Address a)
{
	printf("Name: %s",a.name);
	printf("Phone number: %s",a.phone);
	printf("Email: %s\n",a.email);

}
int main()
{
	struct Address a[10];
	char x[30];
	int n;
	readFile("input.txt",a,&n);
	printf("\nAfter sort by name\n");
	sort_name(a,n);
	int i;
	for(i=0;i<n;i++)
	{
		outAddress(a[i]);
	}
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
}
