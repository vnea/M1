package filesprio.impl;

import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

import filesprio.service.FilesPrioService;

public class FilesPrioImpl<T> implements FilesPrioService<T> {
	protected Map<Integer, List<T>> map;
	
	@Override
	public int size() {
		int sum = 0;
		for (Map.Entry<Integer, List<T>> e : map.entrySet()) {
			sum += e.getValue().size();
		}
		return sum;
	}

	@Override
	public void init() {
		map = new TreeMap<Integer, List<T>>();
	}

	@Override
	public boolean isEmpty() {
		return map.isEmpty();
	}

	@Override
	public int sizePrio(int i) {
		List<T> l = map.get(i);
		return l == null ? 0 : map.get(i).size();
	}

	@Override
	public void putPrio(int i, List<T> e) {
		map.put(i, e);
	}

	@Override
	public boolean isActivePrio(int i) {
		return map.get(i) != null && map.get(i).size() > 0;
	}

	@Override
	public Set<Integer> activePrios() {
		Set<Integer> activePrios = new HashSet<Integer>();
		for (Map.Entry<Integer, List<T>> e : map.entrySet()) {
			if (e.getValue().size() > 0) {
				activePrios.add(e.getKey());
			}
		}
		
		return activePrios;
	}
}
