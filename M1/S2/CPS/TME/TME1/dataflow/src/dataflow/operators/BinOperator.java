package dataflow.operators;

import java.math.BigInteger;

import dataflow.core.Component;
import dataflow.core.IntEventReceiverService;
import dataflow.core.IntEvent;
import dataflow.generators.SimpleGenerator;

public abstract class BinOperator extends SimpleGenerator 
		implements Component,
		           /* provide */
				   IntEventReceiverService {

	protected BigInteger leftValue;
	protected BigInteger rightValue;
	
	protected BinOperator() {
		leftValue = null;
		rightValue = null;
	}
	
	protected abstract BigInteger operator();
	
	@Override
	public void onIntEvent(IntEvent event) {
		if(leftValue==null) {
			leftValue = event.getValue();
		} else if(rightValue==null){
			rightValue = event.getValue();
		} else {
			throw new Error("Receiving a value while waiting for activation.");
		}
	}
	
	@Override
	public void activate() {
		if(leftValue==null) {
			throw new Error("Missing left operand at activation.");
		}
		if(rightValue==null) {
			throw new Error("Missing right operand at activation.");
		}
		
		BigInteger result = operator();
		leftValue = null;
		rightValue = null;
		send(new IntEvent(result));	
	}
}
