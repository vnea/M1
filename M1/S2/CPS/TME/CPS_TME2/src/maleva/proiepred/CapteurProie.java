
package maleva.proiepred;

import maleva.agent.Agent;
import maleva.agent.CapteurAgent;
import maleva.framework.LifeCycleException;

public class CapteurProie extends CapteurAgent {

    public CapteurProie(Agent outer) {
	super(outer);
    }
	       
    /* LCStepperController interface */
    public boolean step() throws LifeCycleException {
	if(efs==null)
	    throw new LifeCycleException("Environment fetch service not bound");
	last_seen_agents = efs.fetchProies(outer.getID(), outer.getPosX(),outer.getPosY(),outer.getAngle(),outer.getFieldOfView(),getViewDist());
	if(last_seen_agents==null || last_seen_agents.length==0)
	    return false;
	else
	    return true;
    }
}
