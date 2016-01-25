/******************************* td2_2.canevas *******************************/

#include "../../../lib_fthread/fthread.h"
#include <stdio.h>
#include <unistd.h>

ft_event_t evt;

void traceinstants(void *a) {
    int i, j = *((int *) a);
    for (i = 0; i < j; ++i) {
        printf("Instant %d\n", i);
        ft_thread_cooperate();
    }
}

void awaiter(void *args)
{
    int i;

    for (i = 0; i < 5; ++i) {
        fprintf(stdout, "debut awater\n");

        ft_thread_await(evt);
        fprintf(stdout, "Evénement reçu\n");
        ft_thread_cooperate_n(3);
    }
    fprintf(stdout, "stop generator!\n");

    ft_scheduler_stop((ft_thread_t) args);
}

void generator(void *args)
{
    int i;
    for (i = 0;; ++i) {
        ft_thread_cooperate_n(7);
        fprintf(stdout, "Evénement numéro %d envoyé\n", i);
        ft_thread_generate(evt);
    }   
}

int main()
{
    ft_thread_t ft_trace, ft_awaiter, ft_generator;
    ft_scheduler_t sched = ft_scheduler_create();

    evt = ft_event_create (sched);
    int j = 55;
    ft_trace = ft_thread_create(sched, traceinstants, NULL, (void *) &j);
    ft_generator = ft_thread_create(sched, generator, NULL, NULL);
    ft_awaiter = ft_thread_create(sched, awaiter, NULL, (void *) ft_generator);
    
    ft_scheduler_start(sched);
    ft_exit();
    
    return 0;
}

