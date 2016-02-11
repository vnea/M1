package bridge.contracts;

import bridge.decorators.LimitedRoadDecorator;
import bridge.services.LimitedRoadService;

public class LimitedRoadContract extends LimitedRoadDecorator {

	public LimitedRoadContract(LimitedRoadService delegate) {
		super(delegate);
	}

	public void checkInvariant() {
		// remarque : include et non refine donc on n'hérite
		// pas des invariants de RoadSectionService, il faut refaire des tests.
				
		/* A COMPLETER */
		// inv: getNbCars() >= 0
		if(!(getNbCars() >= 0)) {
			Contractor.defaultContractor().invariantError("LimitedRoadContract","The number of cars should be positive");
		}
		
		// inv: isFull() = getNbCars() == getLimit()
		if(!(isFull() == (getNbCars() == getLimit()))) {
			Contractor.defaultContractor().invariantError("LimitedRoadService","!(isFull() = getNbCars() == getLimit())");
		}
		
		// inv: getNbCars() <= getLimit()
		if(!(getNbCars() <= getLimit())) {
			Contractor.defaultContractor().invariantError("LimitedRoadService","!(getNbCars() <= getLimit())");
		}
	}
	
	/* A COMPLETER */
	@Override
	public void enter() {
		
		// inv pre
		checkInvariant();
				
		// pre: getNbCars() > 0
		if(super.isFull()) {
			Contractor.defaultContractor().preconditionError("LimitedRoadService", "enter", "The limit is already reached");
		}
		
		// captures
		int getNbCars_atPre = getNbCars();
		
		// run
		super.enter();
		
		// int post
		checkInvariant();
		// post: getNbCars() == getNbCars()@pre + 1 
		if(!(getNbCars() == getNbCars_atPre + 1)) {
			Contractor.defaultContractor().postconditionError("LimitedRoadService", "enter", "The cars count did not increase");
		}
	}
	
	@Override
	public void leave() {
		
		// inv pre
		checkInvariant();
				
		// pre: getNbCars() > 0
		if(!(getNbCars() > 0)) {
			Contractor.defaultContractor().preconditionError("LimitedRoadService", "leave", "The number of cars is not strictly positive");
		}
		// captures
		int getNbCars_atPre = getNbCars();
		
		// run
		super.leave();
		// int post
		checkInvariant();
		// post: getNbCars() == getNbCars()@pre - 1 
		if(!(getNbCars() == getNbCars_atPre - 1)) {
			Contractor.defaultContractor().postconditionError("LimitedRoadService", "leave", "The cars count did not decrease");
		}
	}

	@Override
	public void init() {
		super.init();
		checkInvariant();
		
		// post: getNbCars() == 0
		if (!(getNbCars() == 0)) {
			Contractor.defaultContractor().postconditionError("LimitedRoadService", "init", "The number of cars is not null");
		}
	}


	@Override
	public void init(int lim) {
		// pre: lim > 0
		if (!(lim > 0)) {
			Contractor.defaultContractor().preconditionError("LimitedRoadService", "init", "Limit must be strictly positive");
		}
		
		super.init(lim);
		checkInvariant();
		
		// post: getNbCars() == 0
		if (!(getNbCars() == 0)) {
			Contractor.defaultContractor().postconditionError("LimitedRoadService", "init", "The number of cars is not null");
		}
		
		// post: getLimit() == 0
		if (!(getLimit() == lim)) {
			Contractor.defaultContractor().postconditionError("LimitedRoadService", "init", "The limit is not correct");
		}
	}
	
}
