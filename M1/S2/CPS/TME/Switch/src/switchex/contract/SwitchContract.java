package switchex.contract;

import switchex.service.SwitchService;

public class SwitchContract extends SwitchDecorator {

	public SwitchContract(SwitchService service) {
		super(service);
	}
	
	public void checkInvariant() {
		// inv: isOff() == !isOn()
		if(!(isOff() == !isOn()))
			throw new InvariantError("isOff() == !isOn()");
		
		// inv: getCount() >= 0
		if(!(getCount() >= 0))
			throw new InvariantError("getCount() >= 0");

	}
	
	public static void checkSwitchInvariant(SwitchService serv) {
		new SwitchContract(serv).checkInvariant();
	}
	
	@Override
	public void init() {
		// PRE : pas de précondition
		
		// Traitement
		super.init();
		
		// post-init invariant
		checkInvariant();
		
		// post: isOn() == false
		if(!(isOn() == false))
			throw new PostconditionError("isOn() == false");
		
		// post: getCount() == 0
		if(!(getCount() == 0))
			throw new PostconditionError("getCount() == 0");

	}
	
	@Override
	public void press() {
		
		// pre: isWorking()
		if(!(isWorking()))
			throw new PreconditionError("isWorking()");

		// pre-invariant
		checkInvariant();

		// Captures
		boolean isOn_at_pre = isOn();
		int getCount_at_pre = getCount();
		
		// TRAITEMENT
		super.press();

		// post-invariant
		checkInvariant();

		// post: isOn() == !(isOn()@pre)
		if(!(isOn() == !(isOn_at_pre)))
			throw new PostconditionError("isOn() == !(isOn()@pre");
		
		// post: getCount() == getCount()@pre + 1
		if(!(getCount() == getCount_at_pre + 1))
			throw new PostconditionError("getCount() == getCount()@pre + 1");

	}

}
