package filesprio.contract;

public class PreconditionError extends ContractError {
	private static final long serialVersionUID = 5070397146756819924L;

	public PreconditionError(String message) {
		super("Precondition failed: " + message);
	}
}
