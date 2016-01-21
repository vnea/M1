package dataflow.operators;

import java.math.BigInteger;


public class Div extends BinOperator {

	public Div() {}
	
	@Override
	protected BigInteger operator() {
		return leftValue.divide(rightValue);
	}

}
