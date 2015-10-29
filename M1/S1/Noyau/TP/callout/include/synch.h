#ifndef _SYNCH_H
#define _SYNCH_H

/**
 * @fn int tsleep(int pri, void *obs)
 * Permet au processus de s'endormir sur une ressource
 * @param pri : priorit� au reveil
 * @param obs : ressource observ�e
 * @return rend 0
 */
int tsleep(int, void*);

/**
 * @fn int twakeup(void *obs)
 * Permet au processus de reveiller l'ensemble des processus endormis sur une certaine ressource 
 * @param obs : ressource observ�e
 * @return rend -1 en cas d'erreur sinon 0
 */
int twakeup(void*);

/**
 * @fn int tsleep_time(int sec)
 * Permet au processus de s'endormir pendant une dur�e exprim�e en seconde
 * @param sec : dur�e de l'endormissement
 * @return rend -1 en cas d'erreur sinon 0
 */
int tsleep_time(int sec); 

#endif /* _SYNCH_H */
