#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SORT_BY_ARRIVAL 0
#define SORT_BY_PID 1
#define SORT_BY_BURST 2
#define SORT_BY_START 3
typedef struct{
 int iPID;
 int iArrival, iBurst, iRemainTime;
 int iStart, iFinish, iWaiting, iResponse, iTaT;
} PCB;

FILE *fptr;
fptr = fopen("input.txt","r");

void inputProcess(int n, PCB P[])
{
    
    for(int i=0;i<n;i++)
    {
        int burst,arrival,pid;
        fscanf(fptr,"%d",&pid);
        fscanf(fptr,"%d",&arrival);
        fscanf(fptr,"%d",&burst);
        P[i].iPID = pid;
        P[i].iArrival = arrival;
        P[i].iBurst = burst;
        printf("Tien trinh %d: Arrival=%d Burst=%d\n",pid,arrival,burst);
    }
}
void printProcess(int n, PCB P[])
{
    for(int i=0;i<n;i++)
    printf("pid: %d,\t Arrival: %d\t Burst: %d\n",P[i].iPID,P[i].iArrival,P[i].iBurst);
}
void exportGanttChart (int n, PCB P[])
{
    printf(" ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<P[i].iBurst;j++)
            printf("--");
        printf(" ");
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<P[i].iBurst-1;j++) printf(" ");
        printf("P%d",P[i].iPID);
        for(int j=0;j<P[i].iBurst-1;j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<P[i].iBurst;j++)
        printf("--");
        printf(" ");
    }
    printf("\n");
    // printf timeline
    printf("%d",P[0].iStart);
    for(int i=0; i<n; i++) {
        for(int j=0; j<P[i].iBurst; j++) printf("  ");
        if(P[i].iTaT > 9) printf("\b");
        printf("%d",P[i].iFinish);
    }
    printf("\n");
}
void pushProcess(int *n, PCB P[], PCB Q)
{
    (*n)++;
    P[(*n)] = Q;
}
void removeProcess(int *n, int index, PCB P[])
{
    for(int i = 1 ;i<(*n);i++)
    {
        P[index] = P[i];
        ++index;
    }
    --(*n);
}
int swapProcess(PCB *P, PCB *Q)
{
    PCB temp = *P;
    *P = *Q;
    *Q = temp;
}
int partition (PCB P[], int low, int high, int iCriteria)
{

    int left = low;
    int right = high - 1;
    if(iCriteria == 0)
    {
    int pivot = P[high].iArrival;
    while(true){
        while(left <= right && P[left].iArrival < pivot) left++;
        while(right >= left && P[right].iArrival > pivot) right--;
        if (left >= right) break;
        swapProcess(&P[left], &P[right]);
        left++;
        right--;
    }
    }
    else if (iCriteria == 1)
    {
        int pivot = P[high].iPID;
        while(true){
        while(left <= right && P[left].iPID < pivot) left++;
        while(right >= left && P[right].iPID > pivot) right--;
        if (left >= right) break;
        swapProcess(&P[left], &P[right]);
        left++;
        right--;
        }
    }
    else if(iCriteria == 2)
    {
        int pivot = P[high].iBurst;
        while(true){
        while(left <= right && P[left].iBurst < pivot) left++;
        while(right >= left && P[right].iBurst > pivot) right--;
        if (left >= right) break;
        swapProcess(&P[left], &P[right]);
        left++;
        right--;
        }
    }
    else
    {
        int pivot = P[high].iStart;
        while(true){
        while(left <= right && P[left].iStart < pivot) left++;
        while(right >= left && P[right].iStart > pivot) right--;
        if (left >= right) break;
        swapProcess(&P[left], &P[right]);
        left++;
        right--;
        }
    }
    swapProcess(&P[left], &P[high]);
    return left;
}
void quickSort(PCB P[], int low, int high, int iCriteria)
{
    if (low < high)
    {
        int pi = partition(P, low, high,iCriteria);
        quickSort(P, low, pi - 1,iCriteria);
        quickSort(P, pi + 1, high,iCriteria);
    }
}
void calculateAWT(int n, PCB P[])
{}
void calculateATaT(int n, PCB P[])
{}

int main()
{
 PCB Input[10];
 PCB ReadyQueue[10];
 PCB TerminatedArray[10];
 int iNumberOfProcess;
 fscanf(fptr,"%d",&iNumberOfProcess);
 printf("number of Process: %d \n",iNumberOfProcess);
int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0;
 inputProcess(iNumberOfProcess, Input); // tao tien trinh
 quickSort(Input, 0, iNumberOfProcess - 1,SORT_BY_ARRIVAL);
 pushProcess(&iReady, ReadyQueue, Input[0]);
 removeProcess(&iRemain, 0, Input);
 ReadyQueue[0].iStart = ReadyQueue[0].iArrival;
 ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst;
 ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival;
 ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
 ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival;
 printf("\nReady Queue: ");
 printProcess(1, ReadyQueue);
 while (iTerminated < iNumberOfProcess)
 {
 while (iRemain > 0)
 {
     if (Input[0].iArrival <= ReadyQueue[0].iFinish)
     {
        pushProcess(&iReady, ReadyQueue, Input[0]);
        removeProcess(&iRemain, 0, Input); 
        int ptrTo = iReady-1;
        ReadyQueue[0].iRemainTime = (ReadyQueue[0].iBurst + ReadyQueue[0].iArrival)-ReadyQueue[ptrTo].iArrival;
        ReadyQueue[0]
        for(int i=iReady-2;i>=0;i--)
        {
            if(ReadyQueue[i].iBurst > ReadyQueue[ptrTo].iBurst)
            {
                ReadyQueue[i].iFinish += ReadyQueue[ptrTo].iBurst;
                swapProcess(ReadyQueue[i],ReadyQueue[ptrTo]);
                ReadyQueue[i].iFinish += ReadyQueue[ptrTo].iBurst;
                ptrTo--;
            }
            else
            {
                ReadyQueue[ptrTo].iFinish = ReadyQueue[i].iFinish + ReadyQueue[ptrTo].iBurst;
            }
        }
    }
     else break;
 }

     if (iReady > 0)
     {
        pushProcess(&iTerminated, TerminatedArray,ReadyQueue[0]);
        removeProcess(&iReady, 0, ReadyQueue);

     ReadyQueue[0].iStart = TerminatedArray[iTerminated- 1].iFinish;
     ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst;
     ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival;
     ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
     ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival;
     }
 }
 printf("\n===== SRTF Scheduling =====\n");
 exportGanttChart(iTerminated, TerminatedArray);
 quickSort(TerminatedArray, 0, iTerminated - 1,SORT_BY_PID);
//  calculateAWT(iTerminated, TerminatedArray);
//  calculateATaT(iTerminated, TerminatedArray);

 return 0;
}
