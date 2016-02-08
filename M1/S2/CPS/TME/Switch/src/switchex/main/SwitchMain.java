package switchex.main;

import switchex.contract.SwitchContract;
import switchex.impl.SwitchImpl;
import switchex.service.SwitchService;

public class SwitchMain {

	public static void main(String... args) {
		
		System.out.println("Sans contrat :");

		SwitchService s1 = new SwitchImpl();
		s1.init();
		for(int i=0;i<30;i++) {
			s1.press();
			System.out.println("[" + i + "]: " + s1);
		}

		System.out.println("Avec contrat :");
		
		SwitchService s2 = new SwitchImpl();
		SwitchService s2Contracted = new SwitchContract(s2);
		s2Contracted.init(); // avec contrat
		// s2.init();  // sans contrat
		for(int i=0;i<30;i++) {
			s2Contracted.press(); // avec contrat
			// s2.press();   // sans contrat
			System.out.println("[" + i + "]: " + s2);
		}
		
	}
}
