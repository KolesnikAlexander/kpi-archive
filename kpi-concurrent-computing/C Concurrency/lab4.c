#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 15
#define LENGTH_AT_START 8
#define USLEEP_IS_ALLOWED 1

pthread_t thread1;
pthread_t thread2;
pthread_t thread3;
pthread_t thread4;
pthread_t thread5;

sem_t sem_q;
sem_t  sem_synchro;

FILE* log;

int exit_counter;
int last_time_emptied;

pthread_mutex_t mut_q = PTHREAD_MUTEX_INITIALIZER;



//Element of stack
    typedef struct Elem_1 {
        int number;
    } Elem;

//Stack
    Elem* stack[N];
    int top = -1;
   int counter = -1;

void add_elem()
{
    counter++;
    top++;
    //Creation of a new element
    Elem*  p = (Elem*)malloc(sizeof(Elem));
    //p->number = top;
    p->number = counter;
    
    stack[top] = p;
    if(top == N-1){
        if(last_time_emptied == 1){
            exit_counter++;
            last_time_emptied = 0;
            
        }
            
    }
}/* Змінна для зберігання поточного значення лічильника семафора */
void* thread_producer(void* arg)
{
/* Змінна для зберігання номера потоку */
int num = *(int*)arg;

int sem_value;


    while (1) {
        if(exit_program()) break;
        
        //point of synchro for thread 1
            if(num == 1)
            {
                fprintf(log,"\nProducer1 waits for SEMAPHORE to open\n");
                sem_wait(&sem_synchro);
                fprintf(log,"\nSEMAPHORE is opened for Producer1\n");
            }
            
    if (pthread_mutex_trylock(&mut_q) == 0){
        sem_getvalue(&sem_q,&sem_value);
        if (sem_value < N) {													
            add_elem();
            
             //point of synchro for thread 5
            if(num == 5)
            { 
                fprintf(log, "\nProducer5 has opened the SEMAPHORE.\n");
                sem_post(&sem_synchro);
            }

	    sem_getvalue(&sem_q,&sem_value);
	    fprintf(log, "Producer thread%d: semaphore=%d; element %d CREATED; \n",
		   num,sem_value,stack[top]->number);
         sem_post (&sem_q);
          

	}
	  pthread_mutex_unlock (&mut_q);
}
else{
 fprintf(log, "Producer thread%d does some useful work (mutex is not captured)\n",num);
}
    if(USLEEP_IS_ALLOWED)
        usleep(250);
    }


    if(num == 5)
            { 
                fprintf(log, "\nProducer5 has opened the SEMAPHORE to finish 1st.\n");
                sem_post(&sem_synchro);
            }
    fprintf(log, "Producer thread%d  stopped !!!\n",num);
    return NULL;
}

void* get_elem()
{
    Elem* p = stack[top];
    stack[top] = NULL;
     top--;
     
      if(top == 0){
        if(last_time_emptied == 0)
            exit_counter++;
            last_time_emptied = 1;
        }
     return p;
}

void* thread_consumer (void* arg)
{

int num = *(int*)arg;

Elem* curr_elem=NULL;

int sem_value;

        while (1) {
            if(exit_program()) break;
                //pthread_mutex_lock (&mut_q);
            if (pthread_mutex_trylock(&mut_q) == 0){
               
                if ( sem_trywait (&sem_q) == 0 ){
                    curr_elem = (Elem*)get_elem();
                    sem_getvalue(&sem_q,&sem_value);
                    fprintf(log, "Consumer thread%d: semaphore=%d; element %d TAKEN; \n",
                        num,sem_value,curr_elem->number);
                    
                     //  actions_for_elem (curr_elem);
                         free (curr_elem);
                         pthread_mutex_unlock (&mut_q);

                }
                else{
                    pthread_mutex_unlock (&mut_q);
                    fprintf(log, "Consumer thread%d does some useful work(no elements to take)\n",num);
                }
        }
        else{
            fprintf(log, "Consumer thread%d does some useful work (mutex is not captured)\n",num);
            
        }
        if(USLEEP_IS_ALLOWED)
            usleep(1);
    }

        fprintf(log, "Consumer thread%d  stopped !!!\n",num);

	return NULL;
}

int exit_program(){
    if(exit_counter >= 5)
        return 1;
    else
        return 0;
}

int main(){
    printf("Program started...\n");
    
    log = fopen( "log", "w" );
    
    sem_init(&sem_q, 0, 0);
    sem_init(&sem_synchro,0,0);
    
    exit_counter = 0;
    last_time_emptied = 0;
  
    int sem_value;
    sem_getvalue(&sem_q,&sem_value);  
  
    fprintf(log, "semaphore=%d\n",sem_value);

    int i;
    for(i = 0;i < LENGTH_AT_START;i++) {
		add_elem();
		sem_post(&sem_q);
	}

    fprintf(log, "Stack with elements from 0-th to %d-th has been created !!!\n",LENGTH_AT_START-1);
	sem_getvalue(&sem_q,&sem_value);
    
        fprintf(log, "semaphore=%d\n",sem_value);
        
        int thread1_number=1;
        int thread2_number=2;
        int thread3_number=3;
        int thread4_number=4;
        int thread5_number=5;
        
        pthread_create (&thread1,NULL,&thread_producer,(void*)&thread1_number);
        pthread_create (&thread2,NULL,&thread_producer,(void*)&thread2_number);
        pthread_create (&thread3,NULL,&thread_producer,(void*)&thread3_number);
        pthread_create (&thread4,NULL,&thread_consumer,(void*)&thread4_number);
         pthread_create (&thread5,NULL,&thread_producer,(void*)&thread5_number);
        
        pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);
        pthread_join(thread3,NULL);
        pthread_join(thread4,NULL);
        pthread_join(thread5,NULL);
        
        fprintf(log,"All threads stopped !!!\n");
        fclose(log);
        printf("Program finished, results are saved in the log file\n");
        return 0;
     
}