package dataflow.core;

import java.math.BigInteger;

import dataflow.core.IntEventReceiverService;
import dataflow.core.IntEvent;
import dataflow.generators.SimpleGenerator;

public class Relay extends SimpleGenerator
	implements /* provide */
			   IntEventReceiverService {
	
	private BigInteger inputValue;
	
	public Relay() {
		inputValue = null;
	}

	@Override
	public void onIntEvent(IntEvent event) {
		if(inputValue!=null) {
			throw new Error("Receiving a value while waiting for activation.");		
		}
		inputValue = event.getValue();
	}
	
	@Override
	public void activate() {
		if(inputValue==null) {
			throw new Error("Missing input value at activation.");		
		}
		send(new IntEvent(inputValue));
		inputValue = null;
	}



}
