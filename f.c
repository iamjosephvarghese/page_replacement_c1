#include<stdio.h>

void fifo();
void lru();
//void lfu();

int capacity,n,set[10],seq[10],ch,ctno=1,i,j,k,l,flag;

void main()
{
        printf("Enter the capacity:");
        scanf("%d",&capacity);
        printf("Enter no. of elements in sequence:");
        scanf("%d",&n);

        do{

                printf("Menu\n1.FIFO\n2.LRU\n3.LFU\n");
                scanf("%d",&ch);

                switch(ch)
                {
                        case 1:fifo();
                                break;

                        case 2:lru();
                                break;

                        case 3://lfu();
                                break;

                        default: printf("Enter a valid option!");
                }

                printf("Do you want to continue?Press 1 to continue!");
                scanf("%d",&ctno);
        }while(ctno==1);

}

void fifo()
{
        int fault=0;

        printf("Enter the sequence:\n");

        for(i=0;i<n;i++)
        {
                printf("Enter input %d:",i+1);
                scanf("%d",&seq[i]);
        }

        printf("The input sequence is:\n");
        for(i=0;i<n;i++)
        {
                printf("%d ",seq[i]);
        }
        printf("\n");




        for(i=0;i<capacity;i++)
        {
                set[i] = seq[i];
                printf("Input is %d  ",seq[i]);
                printf("PAGE FAULT\n");
                fault++;
        }



        //going in sequence
        for(j=capacity;j<n;j++)
        {
                flag = 0;
                printf("Input is %d  ",seq[j]);
                //going in frame or capacity
                for(i=0;i<capacity;i++)
                {
                        if(set[i] == seq[j])
                        {
                                flag = 1;
                                break;
                        }else{
                                flag = 0;
                                continue;
                        }
                }
                if(flag==0)
                {
                        printf("PAGE FAULT\n");
                        fault++;
                        k=0;
                        for(k=0;k<capacity-1;k++)
                        {
                                set[k]=set[k+1];
                        }

                        //adding the new value to set queue
                        set[k] = seq[j];

                }else{
                        printf("No Page Fault!\n");
                }
        }
        printf("Total Page Faults = %d\n",fault);

}



void lru()
{

        int fault=0;



        printf("Enter the sequence:\n");

        for(i=0;i<n;i++)
        {
                printf("Enter input %d:",i+1);
                scanf("%d",&seq[i]);
        }

        printf("The input sequence is:\n");
        for(i=0;i<n;i++)
        {
                printf("%d ",seq[i]);
        }
        printf("\n");




        for(i=0;i<capacity;i++)
        {
                set[i] = seq[i];
                printf("Input is %d  ",seq[i]);
                printf("PAGE FAULT\n");
                fault++;
        }

        for(j=capacity;j<n;j++)
        {
                flag = 0;
                printf("Input is %d  ",seq[j]);

                for(i=0;i<capacity;i++)
                {
                        if(set[i] == seq[j])
                        {


                                for(l=i;l<capacity-1;l++)
                                {
                                        set[l]=set[l+1];
                                }
                                set[l]=seq[j];



                                flag=1;
                                break;
                        }else{
                                flag=0;
                                continue;
                        }
                }
                if(flag == 0)
                {
                        printf("PAGE FAULT!\n");
                        fault++;


                        for(k=capacity-1;k>0;k--)
                        {
                                set[k] = set[k-1];

                        }

                        set[0] = seq[j];
                }else{
                        printf("No Page Faults\n");
                }
        }
        printf("Total Page Faults = %d\n",fault);
}

