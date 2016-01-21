package dataflow.examples.basics;

import java.math.BigInteger;

import dataflow.core.Composite;
import dataflow.core.IntEvent;
import dataflow.core.IntEventReceiverService;
import dataflow.core.RequireIntEventReceiverService;
import dataflow.generators.GenConst;
import dataflow.operators.Add;

public class GenInt implements Composite,
			/* require */
			RequireIntEventReceiverService {

	private GenConst gen;
	private Add plus;
	
	public GenInt(int startValue) {
		gen = new GenConst(BigInteger.ONE);
		plus = new Add();
		gen.bindIntEventReceiverService(plus);
		plus.bindIntEventReceiverService(plus);
		plus.onIntEvent(new IntEvent(BigInteger.valueOf(startValue-1))); // warmup
	}	
	
	@Override
	public void bindIntEventReceiverService(IntEventReceiverService serv) {
		plus.bindIntEventReceiverService(serv);
	}
		
	@Override
	public void activate() {
		gen.activate();
		plus.activate();
	}

}
