package switchex.service;

public interface SwitchService {

	/* Observators */
	
	boolean isOn();
	boolean isOff();
	int getCount();
	boolean isWorking();
	
	/* Invariants */
	
	// inv: isOff() == !isOn()
	// inv: getCount() >= 0
	
	/* Constructors */
	
	// post: isOn() == false
	// post: getCount() == 0
	void init();
	
	/* Operators */
	
	// pre: isWorking()
	// post: isOn() == !(isOn()@pre)
	// post: getCount() == getCount()@pre + 1
	void press();
}
