package filesprio.service;

import java.util.List;
import java.util.Set;

public interface FilesPrioService<T> {
	
	/* Observators */
	public int size();
	public boolean isEmpty();
	public int sizePrio(int i);
	public boolean isActivePrio(int i);
	
	/* Invariants */
	// \inv: size() == sum(sizePrio(i) \forall i \in activePrios())
	// \inv: empty() == size() == 0
	// \inv: isActivePrio()
	// \inv: \forall i \in activePrios(), sizePrio(i) > 0
	// \inv: \forall i \not \in activePrios(), sizePrio(i) = 0
	
	/* Constructors */
	// \post: size() == 0
	public void init();
	
	/* Operators */
	// \pre: i > 0
	// \pre: e != null
	// \post: sizePrio(i) == sizePrio(i)@pre + 1
	public void putPrio(int i, List<T> e);
	
	public Set<Integer> activePrios();
}
