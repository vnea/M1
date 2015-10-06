#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

#define ERR_NO_CHILD_CREATED -1

int nfork(int nb_fils)
{
    int nb_children_created = 0;
    int i;
    pid_t pid;
    for (i = 0; i < nb_fils; ++i)
    {
        pid = fork();
        // fork works
        if (pid != -1)
        {
            ++nb_children_created;
            // Child
            if (pid == 0)
            {
                return 0;
            }
        }
        // fork error
        else
        {
            return nb_children_created == 0 ? ERR_NO_CHILD_CREATED : nb_children_created;
        }
    }
    
    while (wait(NULL) != -1);
    
    // Father
    return nb_children_created;
}

 int main (int arg, char* argv []) {
   int p;
   int i=1; int N = 3;
    do {
        p = nfork (i) ;
        if (p != 0 )
               printf ("%d - Pere : %d - Moi : %d\n",p, getppid(), getpid());
    } while ((p ==0) && (++i<=N));
    printf ("FIN - Pere : %d - Moi : %d\n",  getppid(), getpid());    
   return 0;
 }

