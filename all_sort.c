#include<stdio.h>

void merge(int arr[10], int low, int mid, int high)
{
    int i, j, k;

    int brr[7];
    for (int i = low; i <= high; i++)
    {
        brr[i] = arr[i];
    }

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (brr[i] <= brr[j])
        {
            arr[k++] = brr[i++];
        }
        else
        {
            arr[k++] = brr[j++];
        }
    }

    while (i <= mid)
    {
        arr[k++] = brr[i++];
    }
    while (j <= high)
    {
        arr[k++] = brr[j++];
    }
}

void m_sort(int arr[10], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        m_sort(arr, low, mid);
        m_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void b_sort(int a[10],int n)
{
    int t;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void adv_b_sort(int a[10],int n)
{
    int t;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void in_sort(int a[10],int n)
{
    int t,j;
    for(int i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;(j>=0)&&(a[j]>t);j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=t;
    }
}

void s_sort(int a[10],int n)
{
    int min,t,i,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min =j;
        }
        if(min!=i)
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
        
    }
}

int radixsort(int a[10],int n)
{
	int k,j,div,digits=0,bucketno,i,buckets[10][10],count[10],large;
	large=a[0];
	for(i=1;i<=n-1;i++)
	{
		if(a[i]>large) 
        large=a[i];
	}
	while(large!=0)
	{
		digits++;
		large=large/10;
	}
	div=1;
	for(j=1;j<=digits;j++)
	{
		for(i=0;i<=9;i++)
		{
			count[i]=0;
		}
		for(i=0;i<=n-1;i++)
		{
			bucketno=(a[i]/div)%10;
			buckets[bucketno][count[bucketno]]=a[i];
			count[bucketno]++;
		}
		k=0;
		for(bucketno=0;bucketno<=9;bucketno++)
		{
			for(i=0;i<count[bucketno];i++)
			{
				a[k]=buckets[bucketno][i];
				k++;
			}
		}
		div=div*10;
	}
}

void q_sort(int a[10],int first,int last)
{
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
            i++;
            while(a[j]>a[pivot])
            j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;

        q_sort(a,first,j-1);
        q_sort(a,j+1,last);
    }
}

void main()
{
    int a[10],n;
    printf("enter the size of array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter element : ");
        scanf("%d",&a[i]);
    }
    printf("Array before sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    //b_sort(a,n);
    //adv_b_sort(a,n);
    //in_sort(a,n);
    //s_sort(a,n);
    radixsort(a,n);
    //m_sort(a,0,n-1);
    //q_sort(a,0,n-1);
    printf("\nArray after sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}