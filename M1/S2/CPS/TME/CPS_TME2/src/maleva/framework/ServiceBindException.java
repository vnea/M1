
package maleva.framework;

public class ServiceBindException extends Exception {
	private static final long serialVersionUID = 2422151713401895125L;

	public ServiceBindException(String message) {
        super("Cannot bind service : " + message);
    }
}
