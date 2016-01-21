package dataflow.examples.primes;

import dataflow.core.Printer;

public class ShowPrimes {

	public static void main(String[] args) {
		int nb_gen = 30;
		if (args.length > 0) {
			try {
				nb_gen = Integer.parseInt(args[0]);
			} catch(NumberFormatException e) { /* ok use default */ }
		}

		GenPrimes gen = new GenPrimes();
		Printer printer = new Printer("primes() -> ");
		
		gen.bindIntEventReceiverService(printer);
		
		for(int i = 0; i < nb_gen; i++) {
			gen.activate();
			printer.activate();
		}
		
	}

}
