package dataflow.operators;

import java.math.BigInteger;


public class Mul extends BinOperator {

	public Mul() {}
	
	@Override
	protected BigInteger operator() {
		return leftValue.multiply(rightValue);
	}

}
