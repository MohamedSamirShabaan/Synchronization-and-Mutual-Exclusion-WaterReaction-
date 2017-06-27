#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "reaction.h"

// Forward declaration. This function is implemented in reaction-runner.c,
// but you needn't care what it does. Just be sure it's called when
// appropriate within reaction_o()/reaction_h().
void make_water();


/*
any reaction varriable have
H >> number.
one pc_mutex to (lock & unlock)
two condition variable
1 - cond_h_come
2 -cond_done
*/

void reaction_init(struct reaction *reaction)
{
    // Initialize coming H condition variable
    pthread_cond_init(&reaction->cond_h_come, NULL);

    // Initialize  condition variable
    pthread_cond_init(&reaction->cond_done, NULL);

    //initialize mutex and condition variables
    pthread_mutex_init(&reaction->pc_mutex, NULL);

    // intial the H number = 0
    reaction->h_number = 0;
}

void reaction_h(struct reaction *reaction)
{
    // lock mutex
    pthread_mutex_lock(&reaction->pc_mutex);

    // when insert this function then we have new H then increase H_number++;
    reaction->h_number++;

    // send a signal to weak up O
    pthread_cond_signal(&reaction->cond_h_come);

    // wait to recieve a signal 
    pthread_cond_wait(&reaction->cond_done, &reaction->pc_mutex);

    // unlock
    pthread_mutex_unlock(&reaction->pc_mutex);
}

void reaction_o(struct reaction *reaction)
{
    // lock mutex
    pthread_mutex_lock(&reaction->pc_mutex);

    // wait untill arrive 2 H
    while(reaction->h_number < 2)
    {
        pthread_cond_wait(&reaction->cond_h_come, &reaction->pc_mutex);
    }

    /*when out from while then we have more or equal 2 h and when call reaction_o we have o
    then we call make_water() to create H2o then send two signal two weak up two threads */
    make_water();
    reaction->h_number -= 2;

    //fi
    pthread_cond_signal(&reaction->cond_done);
    //se
    pthread_cond_signal(&reaction->cond_done);

    // unlock
    pthread_mutex_unlock(&reaction->pc_mutex);
}

