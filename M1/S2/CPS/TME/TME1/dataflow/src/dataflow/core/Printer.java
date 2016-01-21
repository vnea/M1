package dataflow.core;

import java.math.BigInteger;

public class Printer implements Component, 
		/* provide */
		IntEventReceiverService {

	private String separator;
	private BigInteger valueToPrint;
	
	public Printer(String prefix) {
		separator = prefix;
		valueToPrint = null;
	}
	
	public Printer() {
		this("");
	}
	
	@Override
	public void onIntEvent(IntEvent event) {
		if(valueToPrint != null) {
			throw new Error("Receiving a value while waiting for activation.");
		}
		valueToPrint = event.getValue();
	}

	@Override
	public void activate() {
		System.out.print(separator);
		separator = " ";
		if(valueToPrint != null) {
			System.out.print(valueToPrint);
			valueToPrint = null;
		} else {
			System.out.print(".");
		}
	}
	
}
