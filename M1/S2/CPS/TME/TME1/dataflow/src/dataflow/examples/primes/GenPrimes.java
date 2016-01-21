package dataflow.examples.primes;

import dataflow.core.Composite;
import dataflow.core.IntEventReceiverService;
import dataflow.core.RequireIntEventReceiverService;
import dataflow.examples.basics.GenInt;

public class GenPrimes implements Composite,
			/* require */
			RequireIntEventReceiverService {

	private GenInt gen;
	private PrimeFilter head;
	
	public GenPrimes() {
		gen = new GenInt(2);
		head = new PrimeFilter();
		gen.bindIntEventReceiverService(head);
	}	
	
	@Override
	public void bindIntEventReceiverService(IntEventReceiverService serv) {
		head.bindIntEventReceiverService(serv);
	}
		
	@Override
	public void activate() {
		gen.activate();
		head.activate();
	}

}
