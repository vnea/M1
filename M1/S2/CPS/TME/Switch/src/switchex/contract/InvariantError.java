package switchex.contract;

public class InvariantError extends ContractError {
	private static final long serialVersionUID = 5070397146756819924L;

	public InvariantError(String message) {
		super("Invariant failed: " + message);
	}
}
