package switchex.contract;

public class ContractError extends Error {
	private static final long serialVersionUID = 5070397146756819924L;

	public ContractError(String message) {
		super(message);
	}
}
