

using namespace std;
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h> 
#define CUSTOMERS 0
#define BARBERS 1
#define MUTEX 2 
#define CHAIRS 5 
void signal(int sem_id,int sem_num,struct sembuf *semaphore) 
{
semaphore->sem_num=sem_num;
semaphore->sem_op=1;
semaphore->sem_flg=0;
semop(sem_id,semaphore,1);
} 
void wait(int sem_id,int sem_num,struct sembuf *semaphore) 
{
semaphore->sem_num=sem_num;
semaphore->sem_op=-1;
semaphore->sem_flg=0;
semop(sem_id,semaphore,1);
} 
void initSem(int sem_id,int sem_num,int val)
{
union semnum {
int val;
struct semid_ds *buf;
unsigned short *array;
}argument;

argument.val=val;
semctl(sem_id,sem_num,SETVAL,argument);
} 

int main() 
{
int sem_key=1111,shm_key=2222;
int sem_id,shm_id;
int *waiting;
struct sembuf semaphore;
int count=1;
shm_id=shmget(shm_key,sizeof(int),IPC_CREAT|0666);
sem_id=semget(sem_key,3,IPC_CREAT|0666);
*waiting=0;
initSem(sem_id,CUSTOMERS,0);
initSem(sem_id,BARBERS,1);
initSem(sem_id,MUTEX,1);
printf("There are %d chairs.\n",CHAIRS);

if(fork()) {

    /* The barber part. */
    while(1)
    {
        wait(sem_id,CUSTOMERS,&semaphore);
        wait(sem_id,MUTEX,&semaphore);
        *waiting=*waiting-1;
        signal(sem_id,BARBERS,&semaphore);
        signal(sem_id,MUTEX,&semaphore);
        printf("The barber is now cutting hair.\n"); 
        cout<<"Esperando "<< waiting<<"\n";
        sleep(6);  
    }
}
else {

        /* The customer part. */
    while(1) {
        sleep(1);   
        wait(sem_id,MUTEX,&semaphore);
        if(*waiting < CHAIRS)
        {
            printf("Customer %d is seated.\n",count++);
            *waiting=*waiting+1;
            signal(sem_id,CUSTOMERS,&semaphore);
            signal(sem_id,MUTEX,&semaphore); 
        }
        else 
        {
            printf("Customer %d left the shop.\n",count++);
            signal(sem_id,MUTEX,&semaphore);
        }
    }
}}