package switchex.impl;

import java.util.Random;

import switchex.service.SwitchService;

public class SwitchImpl implements SwitchService {
	public enum State { ON, OFF };
	
	private State state;
	private int count;
	private boolean working;
	private Random rand;
	
	public SwitchImpl() {
		init(); // ou alors dans un état non-initialisé
		working = true; // on force une valeurs
		rand = new Random();
	}
	
	@Override
	public boolean isOn() {
		return state == State.ON;
	}

	@Override
	public boolean isOff() {
		return state == State.OFF;
	}

	@Override
	public int getCount() {
		return count;
	}

	@Override
	public boolean isWorking() {
		return working;
	}

	@Override
	public void init() {
		state = State.OFF; // State.ON;
		count = 0;
	}

	@Override
	public void press() {
		if(state == State.OFF) {
			state = State.ON;
		} else {
			state = State.OFF;
		}
		
		if(Math.random() > 0.5) {
			count -= 1;
		} else {
			count += 1;
		}

		int choice = rand.nextInt(100);
		if(working && choice<100) {
			working = true;
		} else {
			working = false;
		}
	}
	
	@Override
	public String toString() {
		if(working) {
			return "Switch[" + state + "]@" + count;
		} else {
			return "Switch<FAILURE>";
		}
	}
}
