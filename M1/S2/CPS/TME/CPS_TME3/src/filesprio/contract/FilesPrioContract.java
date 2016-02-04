package filesprio.contract;

import java.util.List;

import filesprio.service.FilesPrioService;

public class FilesPrioContract<T> extends FilesPrioDecorator<T>  {
	public FilesPrioContract(FilesPrioService<T> delegate) {
		super(delegate);
	}

	private void checkInvariant() {
		if (!(super.isEmpty() == (super.size() == 0))) {
			throw new InvariantError("!(isEmpty() == (size() == 0))");
		}
	}
	
	@Override
	public void init() {
		/* Pré-conditions */

		/* Initialisation */
		super.init();
		
		/* Invariants */
		checkInvariant();
		
		/* Post-conditions */
		// \post: size() == 0
		if (!(super.size() == 0)) {
			throw new PostconditionError("!(size() == 0)");
		}
	}
	
	@Override
	public void putPrio(int i, List<T> e) {
		/* Pré-conditions */
		// \pre: i >= 0
		if(!(i >= 0)) {
			throw new PreconditionError("!(i >= 0)");
		}

		// \pre: e != null
		if (!(e != null)) {
			throw new PreconditionError("!(e != null)");
		}
		
		/* Pre-invariant */
		checkInvariant();

		/* Captures */
		final int sizePrio_atPre = super.sizePrio(i);
		//final boolean isActivePrio_atPre = super.isActivePrio(i);
		
		/* Traitement */
		super.putPrio(i, e);

		/* Post-invariant */
		checkInvariant();

		/* Post-conditions */
		// \post: sizePrio(i) == sizePrio(i)@pre + 1
		if (!(sizePrio_atPre == super.sizePrio(i) + 1)) {
			throw new
			PostconditionError("!(sizePrio_atPre == super.sizePrio(i) + 1)");
		}
		
		// \post: isActivePrio(i) == isActivePrio(i)@pre
//		if (!(sizePrio_atPre == super.sizePrio(i) + 1)) {
//			throw new
//			PostconditionError("!(sizePrio_atPre == super.sizePrio(i) + 1)");
//		}
	}
}
