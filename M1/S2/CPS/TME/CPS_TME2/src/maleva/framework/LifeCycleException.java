package maleva.framework;

public class LifeCycleException extends Exception {
	private static final long serialVersionUID = 5853423893830037660L;

	public LifeCycleException(String message) {
        super("Life Cycle fault : " + message);
    }
}
