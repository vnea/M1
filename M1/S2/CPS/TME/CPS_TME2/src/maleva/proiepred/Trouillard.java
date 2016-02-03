
package maleva.proiepred;

import maleva.agent.Agent;
import maleva.agent.Effecteur;
import maleva.agent.EnvironmentEffectService;
import maleva.agent.EnvironmentFetchService;
import maleva.agent.RandomMouvement;
import maleva.framework.LifeCycleException;
import maleva.framework.ServiceBindException;

public class Trouillard extends Agent {
	
	/* properties */
	
	/* inner components */
	CapteurProie capteur;
	FuirAgent fuir;
	RandomMouvement rndmvt;
	Effecteur effecteur;
	
	public Trouillard(String id) {
		super(id,TYPE_PROIE);
		capteur = null;
		fuir = null;
		rndmvt = null;
		effecteur = null;
	}
	
	/* properties */
	public int getViewDist() {
		return capteur.getViewDist();
	}
	
	public void setViewDist(int vdist) {
		capteur.setViewDist(vdist);
	}
	
	/* external bindings */
	public void bindEnvironmentFetchService(EnvironmentFetchService efs) throws ServiceBindException {
		if(capteur==null)
			throw new ServiceBindException("Cannot bind Service : capteur inner component not initialized");
		capteur.bindEnvironmentFetchService(efs);
	}
	
	public void bindEnvironmentEffectService(EnvironmentEffectService ees) throws ServiceBindException {
		if(effecteur==null)
			throw new ServiceBindException("Cannot bind Service : effecteur inner component not initialized");
		effecteur.bindEnvironmentEffectService(ees);
	}
	
	public boolean isBound() {
		return super.isBound() && capteur.isBound() && effecteur.isBound();
	}
	
	/* LCInitializeController */
	
	public void initialize() throws LifeCycleException {
		super.initialize();
		
		// create inner components
		capteur = new CapteurProie(this);
		fuir = new FuirAgent(this);
		rndmvt = new RandomMouvement(this);
		effecteur = new Effecteur(this);
		
		// inner bindings
		
		try {
			fuir.bindAgentRefListService(capteur);
			effecteur.bindActionService(fuir);
			effecteur.bindActionService(rndmvt);
		} catch(ServiceBindException sbe) {
			initialized = false;
			LifeCycleException lce = new LifeCycleException("Service bind exception");
			lce.initCause(sbe);
			throw lce;
		}
		
	}
	
	/* LCStepperController */
	
	public boolean step() throws LifeCycleException {
		super.step();
		
		if(capteur.step() && fuir.step()) {
			System.out.println("Trouillard '"+getID()+"' sees agents, flee");
			return effecteur.step();
		} else if(rndmvt.step()) {
			System.out.println("Agent '"+getID()+"' sees nothing or cannot follow");
			return effecteur.step();
		}		
		System.out.println("Agent '"+getID()+"' cannot do nothing");
		return false;
	}
	
}
