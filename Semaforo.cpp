
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

class Semaforo {
    public:
    int buffer;

    void SemaforoInit(int *S);
    void signal(int *S);
    void wait(int *S);
};

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