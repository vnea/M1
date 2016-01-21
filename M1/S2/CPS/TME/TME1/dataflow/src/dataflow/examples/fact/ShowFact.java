package dataflow.examples.fact;

import dataflow.core.Printer;

public class ShowFact {

	public static void main(String[] args) {
		int nb_gen = 30;
		if (args.length > 0) {
			try {
				nb_gen = Integer.parseInt(args[0]);
			} catch(NumberFormatException e) { /* ok use default */ }
		}

		GenFact gen = new GenFact();
		Printer printer = new Printer("fact(1.." + nb_gen + ") -> ");
		
		gen.bindIntEventReceiverService(printer);
				
		
		for(int i = 0; i < nb_gen; i++) {
			gen.activate();
			printer.activate();
		}
		
	}

}
