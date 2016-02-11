package bridge.contracts;

import bridge.services.BridgeService;

public class BridgeContract extends LimitedRoadContract implements BridgeService {

	public BridgeContract(BridgeService delegate) {
		super(delegate);
	}

	@Override
	protected BridgeService getDelegate() {
		return (BridgeService) super.getDelegate();
	}
	
	@Override
	public int getNbIn() {
		return getDelegate().getNbIn();
	}

	@Override
	public int getNbOut() {
		return getDelegate().getNbOut();
	}
	
	public void checkInvariant() {
		// TODO
		// raffinement donc
		super.checkInvariant();
		
		// inv: getNbCars() == (getNbIn() + getNbOut()
		if (!(getNbCars() == (getNbIn() + getNbOut()))) {
			Contractor.defaultContractor().invariantError("BridgeService","The number of cars is not equal to nbIn + nbOut");
		}
		
		// inv: getNbIn() >= 0
		if (!(getNbIn() >= 0)) {
			Contractor.defaultContractor().invariantError("BridgeService","Nbin is not positive");
		}
		
		// inv: getNbOut() >= 0
		if (!(getNbOut() >= 0)) {
			Contractor.defaultContractor().invariantError("BridgeService","Nbout is not positive");
		}
	}
	

	@Override
	public void init() {
		// TODO
		getDelegate().init();
	}

	@Override
	public void init(int lim) {
		// TODO
		getDelegate().init(lim);
		
		// post: getNbIn() == 0
		if (!(getNbIn() == 0)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "init", "Nbin is not null");
		}
		
		// post: getNbOut() == 0
		if (!(getNbOut() == 0)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "init", "Nbout is not null");
		}
		
		// post: getLimit() == 0
		if (!(getLimit() == lim)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "init", "The limit is not correct");
		}
	}

	@Override
	public void enterIn() {
		// inv pre
		checkInvariant();
		
		// pre
		if (!(!isFull())) {
			Contractor.defaultContractor().preconditionError("BridgeService", "enterIn", "The road is full");
		}
		
		// captures
		final int nbIn_atPre = getDelegate().getNbIn();
		final int nbOut_atPre = getDelegate().getNbOut();

		
		// run
		getDelegate().enterIn();
		
		// inv post
		checkInvariant();
		
		// post: getNbIn() == nbIn_atPre + 1
		if (!(getNbIn() == nbIn_atPre + 1)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "enterIn", "Nbin count did not increase");
		}
		
		// post: getNbOut() == nbOut_atPre
		if (!(getNbOut() == nbOut_atPre)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "enterIn", "Nbout count changed");
		}
	}

	@Override
	public void leaveIn() {
		// inv pre
		checkInvariant();
		
		// pre
		if (!(getNbIn() > 0)) {
			Contractor.defaultContractor().preconditionError("BridgeService", "leaveIn", "No cars in the road");
		}
		
		// captures
		final int nbIn_atPre = getDelegate().getNbIn();
		final int nbOut_atPre = getDelegate().getNbOut();

		
		// run
		getDelegate().leaveIn();
		
		// inv post
		checkInvariant();
		
		// post: getNbIn() == nbIn_atPre - 1
		if (!(getNbIn() == nbIn_atPre - 1)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "leaveIn", "Nbin count did not decrease");
		}
		
		// post: getNbOut() == nbOut_atPre
		if (!(getNbOut() == nbOut_atPre)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "leaveIn", "Nbout count changed");
		}
	}

	@Override
	public void enterOut() {
		// inv pre
		checkInvariant();
		
		// pre
		if (!(!isFull())) {
			Contractor.defaultContractor().preconditionError("BridgeService", "enterOut", "The road is full");
		}
		
		// captures
		final int nbIn_atPre = getDelegate().getNbIn();
		final int nbOut_atPre = getDelegate().getNbOut();

		
		// run
		getDelegate().enterOut();
		
		// inv post
		checkInvariant();
		
		// post: getNbOut() == nbOut_atPre + 1
		if (!(getNbOut() == nbOut_atPre + 1)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "enterOut", "Nbout count did not increase");
		}
		
		// post: getNbIn() == nbIn_atPre
		if (!(getNbIn() == nbIn_atPre)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "enterOut", "Nbin count change");
		}
	}

	@Override
	public void leaveOut() {
		// inv pre
		checkInvariant();
		
		// pre
		if (!(getNbOut() > 0)) {
			Contractor.defaultContractor().preconditionError("BridgeService", "leaveOut", "No cars in the road");
		}
		
		// captures
		final int nbIn_atPre = getDelegate().getNbIn();
		final int nbOut_atPre = getDelegate().getNbOut();

		
		// run
		getDelegate().leaveOut();
		
		// inv post
		checkInvariant();
		
		// post: getNbOut() == nbOut_atPre - 1
		if (!(getNbOut() == nbOut_atPre - 1)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "leaveOut", "Nbout count did not decrease");
		}
		
		// post: getNbIn() == nbIn_atPre
		if (!(getNbIn() == nbIn_atPre)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "leaveOut", "Nbin count change");
		}
	}
	
	@Override
	public void enter() {
		// inv pre
		checkInvariant();
		
		// captures
		final int nbIn_atPre = getDelegate().getNbIn();
		final int nbOut_atPre = getDelegate().getNbOut();
		
		// run
		super.enter();
		
		// post: getNbIn() == nbIn_atPre + 1
		if (!(getNbIn() == nbIn_atPre + 1)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "enter", "Nbin count did not increase");
		}
		
		// post: getNbOut() == nbOut_atPre
		if (!(getNbOut() == nbOut_atPre)) {
			Contractor.defaultContractor().postconditionError("BridgeService", "enter", "Nbout count changed");
		}
		
		// inv post
		checkInvariant();
	}
	
	@Override
	public void leave() {
		// inv pre
		checkInvariant();
		
		// captures
		final int nbIn_atPre = getDelegate().getNbIn();
		final int nbOut_atPre = getDelegate().getNbOut();
		
		// run
		super.leave();
		
		// leaveIn
		if (nbIn_atPre > 0) {
			// post: getNbIn() == nbIn_atPre - 1
			if (!(getNbIn() == nbIn_atPre - 1)) {
				Contractor.defaultContractor().postconditionError("BridgeService", "leaveIn", "Nbin count did not decrease");
			}
			
			// post: getNbOut() == nbOut_atPre
			if (!(getNbOut() == nbOut_atPre)) {
				Contractor.defaultContractor().postconditionError("BridgeService", "leaveIn", "Nbout count changed");
			}
		}
		// leaveOut
		else {
			// post: getNbOut() == nbOut_atPre - 1
			if (!(getNbOut() == nbOut_atPre - 1)) {
				Contractor.defaultContractor().postconditionError("BridgeService", "leaveOut", "Nbout count did not decrease");
			}
			
			// post: getNbIn() == nbIn_atPre
			if (!(getNbIn() == nbIn_atPre)) {
				Contractor.defaultContractor().postconditionError("BridgeService", "leaveOut", "Nbin count change");
			}
		}
		
		// inv post
		checkInvariant();
	}
}
