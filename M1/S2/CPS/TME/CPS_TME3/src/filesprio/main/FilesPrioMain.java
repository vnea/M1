package filesprio.main;

import filesprio.contract.FilesPrioContract;
import filesprio.impl.FilesPrioImpl;
import filesprio.impl.FilesPrioImplBug;
import filesprio.service.FilesPrioService;

public class FilesPrioMain {
	
	public static void main(String[] args) {
		/* FilesPrioImpl */
		FilesPrioService<Integer> fp = new FilesPrioImpl<Integer>();
		fp.init();
		FilesPrioService<Integer> fpContracted =
				new FilesPrioContract<Integer>(fp);
		fpContracted.init();
		
		/* FilesPrioImplBug */
		FilesPrioService<Integer> fpBug = new FilesPrioImplBug<Integer>();
		fpBug.init();
		FilesPrioService<Integer> fpBugContracted =
				  new FilesPrioContract<Integer>(fpBug);
		fpBugContracted.init();
	}
}
