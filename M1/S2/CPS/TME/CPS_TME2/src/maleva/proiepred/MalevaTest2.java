package maleva.proiepred;

import maleva.agent.Agent;
import maleva.view.EnvironmentView;

public class MalevaTest2 {
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		EnvironmentView env = new EnvironmentView(640,400);

		Agent me1 = new Mechant("Serge");
		Agent me2 = new Mechant("Mariok");
		Agent ge1 = new Trouillard("Maya");
		Agent ge2 = new Trouillard("Billy");
		Agent ge3 = new Trouillard("Tony");

		try {
			me1.initialize();
			me2.initialize();
			ge1.initialize();
			ge2.initialize();
			ge3.initialize();

			me1.configure(env,130,130);
			me2.configure(env,150,200);
			ge1.configure(env,170,150);
			ge2.configure(env,180,120);
			ge3.configure(env,140,90);

			for(int i =0;i<100;i++) {
				System.out.println("  =====       STEP: "+i+"       ======");
				me1.step();
				me2.step();
				ge1.step();
				ge2.step();
				Thread.sleep(50);
			}
		} catch(Exception e) {
			e.printStackTrace(System.err);
		}

		env = null;
		
	}

}
