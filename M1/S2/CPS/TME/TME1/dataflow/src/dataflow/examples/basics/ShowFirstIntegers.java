package dataflow.examples.basics;

import java.math.BigInteger;

import dataflow.core.IntEvent;
import dataflow.core.Printer;
import dataflow.generators.GenConst;
import dataflow.operators.Add;

public class ShowFirstIntegers {

	public static void main(String[] args) {
		int nb_gen = 30;
		if (args.length > 0) {
			try {
				nb_gen = Integer.parseInt(args[0]);
			} catch(NumberFormatException e) { /* ok use default */ }
		}

		GenConst gen = new GenConst(1);
		
		Add plus = new Add();
		
		Printer printer = new Printer("int(1.." + nb_gen + ") -> ");
		
		gen.bindIntEventReceiverService(plus);
		plus.bindIntEventReceiverService(plus);
		plus.bindIntEventReceiverService(printer);
				
		
		plus.onIntEvent(new IntEvent(BigInteger.ZERO)); // warmup 
		for(int i = 0; i < nb_gen; i++) {
			gen.activate();
			plus.activate();
			printer.activate();
		}
		
	}

}
