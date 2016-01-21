package dataflow.operators;

import java.math.BigInteger;


public class Add extends BinOperator {

	public Add() {}
	
	@Override
	protected BigInteger operator() {
		return leftValue.add(rightValue);
	}

}
