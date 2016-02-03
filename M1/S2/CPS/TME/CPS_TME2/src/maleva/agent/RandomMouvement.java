
package maleva.agent;

import java.util.Random;

import maleva.framework.LifeCycleException;

public class RandomMouvement extends ComportementAgent {
	
	/* fields */
	private Random rand;
	
	/* properties */
	private int angle_step = 10;
	
	public RandomMouvement(Agent outer) {
		super(outer);
		rand = new Random();
	}
	
	/* LCStepperController */
	
	public boolean step() throws LifeCycleException {
		
		// A COMPLETER
		// Generate a number between -outer.getAngle() and +outer.getAngle()
		angle_step = rand.nextInt(2 * outer.getAngle() + 1) - outer.getAngle();
		action = new Action(Action.MOVE, outer.getAngle() + angle_step);

		return true;
	}
}
