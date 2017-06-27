#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// reaction struct 
struct reaction{
    // h_number to count number of H
    int h_number;

    // mutex to lock and unlock 
    pthread_mutex_t pc_mutex;

   //condition varriable 
    pthread_cond_t cond_h_come;
    pthread_cond_t cond_done;
};

void reaction_init(struct reaction *reaction);
void reaction_h(struct reaction *reaction);
void reaction_o(struct reaction *reaction);
