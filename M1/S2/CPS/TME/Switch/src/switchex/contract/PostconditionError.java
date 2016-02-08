package switchex.contract;

public class PostconditionError extends ContractError {
	private static final long serialVersionUID = 5070397146756819924L;

	public PostconditionError(String message) {
		super("Postcondition failed: " + message);
	}
}
