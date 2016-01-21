package dataflow.core;


public interface RequireNamedIntEventReceiverService extends RequireIntEventReceiverService {
	void bindIntEventReceiverService(String bindName, IntEventReceiverService serv);
}
