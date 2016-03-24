mtype = {red, orange, green}; 
chan ch = [1] of {mtype, bit};

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
    ch ! color, blink;

    /* Main loop */
    do
    :: color == green -> color = orange; ch ! color, blink;
    :: color == orange -> color = red; ch ! color, blink;
    :: color == red -> color = green; ch ! color, blink;
    :: true -> atomic {
                   true;
                   color = orange;
                   blink = 1;
                   ch ! color, blink;
               }
               goto end
    od;

    end:
}

proctype obs()
{
    mtype newFeu;
    mtype oldFeu;
    bit blink;
    
    ch ? oldFeu, blink;
    
    /* Assertions */  
    ch ? newFeu, blink;  
    do
    :: oldFeu == red && blink != 1 -> assert(newFeu != orange); 
                        oldFeu = newFeu; 
                        ch ? newFeu, blink;
    :: oldFeu == orange && blink != 1-> assert(newFeu != green);
                                        oldFeu = newFeu; 
                                        ch ? newFeu, blink;
    :: oldFeu == green && blink != 1 -> assert(newFeu != red); assert(blink == 0); 
                                                 oldFeu = newFeu; 
                                                 ch ? newFeu, blink;
    :: oldFeu == orange && blink == 1 -> goto end
    :: else -> assert(false);
    od;
    
    end:
}

init
{
    atomic {
        run feu();
        run obs();
    }
}

