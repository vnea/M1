package dataflow.examples.fact;

import java.math.BigInteger;

import dataflow.core.Composite;
import dataflow.core.IntEvent;
import dataflow.core.IntEventReceiverService;
import dataflow.core.RequireIntEventReceiverService;
import dataflow.examples.basics.GenInt;
import dataflow.operators.Mul;


/*
 * 
 * Exercice 2 -- Question 3
 * 
 * A compléter  
 * 
 */

public class GenFact implements Composite,
			/* require */
			RequireIntEventReceiverService {

	final private GenInt gen;
	final private Mul mul;
	
	public GenFact() {
		final int START_VALUE = 1;
		gen = new GenInt(START_VALUE);
		mul = new Mul();
		gen.bindIntEventReceiverService(mul);
		mul.bindIntEventReceiverService(mul);
		mul.onIntEvent(new IntEvent(BigInteger.valueOf(START_VALUE)));
	}	
	
	@Override
	public void bindIntEventReceiverService(IntEventReceiverService serv) {
		mul.bindIntEventReceiverService(serv);
	}
		
	@Override
	public void activate() {
		gen.activate();
		mul.activate();
	}

}
