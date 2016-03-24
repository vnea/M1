mtype = {red, orange, green}; 

proctype feu() 
{
    /* Before init */
    mtype color;
    
    /* Init */
    bit blink;
    atomic {
        true;
        blink = 1;
        color = orange;
    }
               
    /* After init */
    atomic {
        true;
        blink = 0;
        color = red;
    }

    /* Main loop */
    do
    :: color == green -> color = orange;
    :: color == orange -> color = red;
    :: color == red -> color = green;
    :: true -> atomic {
                   true;
                   color = orange;
                   blink = 1;
               }
               goto end;
    od;

    end:
}

init
{
    atomic {
        run feu();
    }
} 
