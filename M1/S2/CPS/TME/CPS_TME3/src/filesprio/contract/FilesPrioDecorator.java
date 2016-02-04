package filesprio.contract;

import java.util.List;
import java.util.Set;

import filesprio.service.FilesPrioService;

public class FilesPrioDecorator<T> implements FilesPrioService<T> {
	private FilesPrioService<T> delegate;

	protected FilesPrioDecorator(FilesPrioService<T> delegate) {
		this.delegate = delegate;
	}
	
	@Override
	public void init() {
		delegate.init();		
	}
	
	@Override
	public int size() {
		return delegate.size();
	}

	@Override
	public boolean isEmpty() {
		return delegate.isEmpty();
	}

	@Override
	public int sizePrio(int i) {
		return delegate.sizePrio(i);
	}

	@Override
	public void putPrio(int i, List<T> e) {
		delegate.putPrio(i, e);		
	}

	@Override
	public boolean isActivePrio(int i) {
		return delegate.isActivePrio(i);
	}

	@Override
	public Set<Integer> activePrios() {
		return delegate.activePrios();
	}
}
