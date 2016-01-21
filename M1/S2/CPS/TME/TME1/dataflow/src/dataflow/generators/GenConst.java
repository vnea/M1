package dataflow.generators;

import java.math.BigInteger;

import dataflow.core.IntEvent;

public class GenConst extends SimpleGenerator {

	private BigInteger constValue;
	
	public GenConst(BigInteger constValue) {
		this.constValue = constValue;
	}
	
	public GenConst(int constValue) {
		this(BigInteger.valueOf(constValue));
	}
	
	@Override
	public void activate() {
		send(new IntEvent(constValue));
	}

}
