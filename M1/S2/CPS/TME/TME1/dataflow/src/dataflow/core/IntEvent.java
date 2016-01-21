package dataflow.core;

import java.math.BigInteger;

public class IntEvent {
	private BigInteger val;
	
	public IntEvent(BigInteger val) {
		this.val = val;
	}
	
	public BigInteger getValue() {
		return val;
	}
	
	@Override
	public String toString() {
		return val.toString();
	}
}
