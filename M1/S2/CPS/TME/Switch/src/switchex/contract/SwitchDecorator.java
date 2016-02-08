package switchex.contract;

import switchex.service.SwitchService;

public abstract class SwitchDecorator implements SwitchService {
	private SwitchService delegate;
	
	protected SwitchDecorator(SwitchService delegate) {
		this.delegate = delegate;
	}
	
	@Override
	public boolean isOn() {
		return delegate.isOn();
	}

	@Override
	public boolean isOff() {
		return delegate.isOff();
	}

	@Override
	public int getCount() {
		return delegate.getCount();
	}

	@Override
	public boolean isWorking() {
		return delegate.isWorking();
	}

	@Override
	public void init() {
		delegate.init();
	}

	@Override
	public void press() {
		delegate.press();
	}

}
