package dataflow.operators;

import java.math.BigInteger;


public class Sub extends BinOperator {

	public Sub() {}
	
	@Override
	protected BigInteger operator() {
		return leftValue.subtract(rightValue);
	}

}
