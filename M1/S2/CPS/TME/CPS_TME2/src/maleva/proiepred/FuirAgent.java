
package maleva.proiepred;

import maleva.agent.Action;
import maleva.agent.Agent;
import maleva.agent.AgentRef;
import maleva.agent.ComportementAgent;
import maleva.framework.LifeCycleException;

public class FuirAgent extends ComportementAgent {
	
	public FuirAgent(Agent outer) {
		super(outer);
	}
	
	/* Stepper controller */
	
	public boolean step() throws LifeCycleException {
		if(arls==null)
			throw new LifeCycleException("AgentRefListService not bound");
		AgentRef[] arefs = arls.getAgentRefs();
		if(arefs==null) {
			action = null; // cannot take any decision
			System.out.println("FuirAgent failed for "+outer.getID());
			return false; // step not finished
		}
		
		action = new Action(Action.MOVE,ComportementAgent.computeAngle(arefs,180));
		return true; // step is finished
	}
}