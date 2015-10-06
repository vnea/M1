#include <unistd.h>
#include <sys/types.h>

#define ERR_NO_CHILD_CREATED -1

int nfork(int nb_fils)
{
    int nb_children_created = 0;
    int i;
    for (i = 0; i < nb_fils; ++i)
    {
        pid_t pid = fork();
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
    
    // Father
    return nb_children_created;
}

