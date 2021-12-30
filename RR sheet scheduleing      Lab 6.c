             // AbdulRahmann Reda Muhammed Fahmy          G: 2                                    


                                                             /*         CPU - Scheduling - Algorithm - In - C
                                                                        Round Robin Scheduling Algorithm(Pre-emptive)            */

#include<stdio.h>
#include<malloc.h>

void main()
{
    int o, w, tempn, count, terminaltime=0, initialtime, qt, flag=0, *bt, *wt, *tat, *tempbt;
    float avgwt = 0, avgtat = 0;
    printf("\n  Please Enter the number of processes : ");
    scanf("%d", &o);
    tempn = o;

    tempbt = (int*)malloc(o*sizeof(int));
    bt = (int*)malloc(o*sizeof(int));
    wt = (int*)malloc(o*sizeof(int));
    tat = (int*)malloc(o*sizeof(int));
    
    printf("\n Please Enter the Quantum Time : ");
    scanf("%d", &qt);
    printf("\n Please Enter the burst time for each process \n\n");
    for(w=0; w<o; w++)
    {
        printf(" the  Burst time of P%d : ", w);
        scanf("%d", &bt[w]);
        tempbt[w] = bt[w];
        //terminaltime += bt[i];
    }

    wt[0] = 0;
    printf("\n\t GAANT Chart \n");
    printf("\n----------------------------\n");
    
    for(terminaltime=0, count=0; tempn!=0;) {
        initialtime = terminaltime;
        if(tempbt[count] <= qt && tempbt[count] > 0) {
            terminaltime += tempbt[count];
            tempbt[count] = 0;
            wt[count] = terminaltime - bt[count];
            tat[count] = wt[count] + bt[count];
            flag = 1;
        }
        else if(tempbt[count] > qt) {
            tempbt[count] -= qt;
            terminaltime += qt;
        }
        if(tempbt[count] == 0 && flag == 1) {
            tempn--;
            flag=0;
        }
        if(initialtime != terminaltime) {
            printf(" %d\t|| P%d ||\t%d\n", initialtime, count, terminaltime);
        }
        if(count == o-1)
            count = 0;
        else
            ++count;
    }

    printf("\n  the PROCESS \t  the BURST TIME \t the WAITING TIME \t the TURNAROUND TIME \n");
    printf("-----------------------------------------------------------------\n");
    for(w=0; w<o; w++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", w, bt[w], wt[w], tat[w]);
         avgwt += wt[w];
        avgtat += tat[w]; 
    }

   
    avgwt = avgwt/o;
    avgtat = avgtat/o;

    printf("\n the Average of the Waiting Time is = %f \n the Average of Turnaround Time is = %f \n", avgwt, avgtat);
