package dataflow.examples.fibo;

import java.math.BigInteger;

import dataflow.core.Composite;
import dataflow.core.IntEvent;
import dataflow.core.IntEventReceiverService;
import dataflow.core.Relay;
import dataflow.core.RequireIntEventReceiverService;
import dataflow.operators.Add;

/*
 * 
 * Exercice 2 -- Question 4
 * 
 * A compléter  
 * 
 */


public class GenFibo implements Composite,
			/* require */
			RequireIntEventReceiverService {

	final private Add add;
	final private Relay f0, f1;
	
	public GenFibo() {
		add = new Add();
		f0 = new Relay();
		f1 = new Relay();
		f0.bindIntEventReceiverService(f1);
		f1.bindIntEventReceiverService(add);
		add.bindIntEventReceiverService(f0);
		add.bindIntEventReceiverService(add);

		add.onIntEvent(new IntEvent(BigInteger.ZERO));
		f1.onIntEvent(new IntEvent(BigInteger.ONE));
		f0.onIntEvent(new IntEvent(BigInteger.ONE));
	}
	
	@Override
	public void bindIntEventReceiverService(IntEventReceiverService serv) {
		add.bindIntEventReceiverService(serv);
	}
		
	@Override
	public void activate() {
		f1.activate();
		f0.activate();
		add.activate();
	}
}
