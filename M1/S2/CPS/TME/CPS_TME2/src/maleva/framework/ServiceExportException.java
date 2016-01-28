package maleva.framework;

public class ServiceExportException extends Exception {
	private static final long serialVersionUID = 2087532937666202418L;

	public ServiceExportException(String message) {
        super("Cannot export service : " + message);
    }
}
