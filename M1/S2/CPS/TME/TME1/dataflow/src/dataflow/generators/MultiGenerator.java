package dataflow.generators;

import java.util.HashMap;
import java.util.Map;

import dataflow.core.Component;
import dataflow.core.IntEventReceiverService;
import dataflow.core.IntEventSender;
import dataflow.core.RequireNamedIntEventReceiverService;

public abstract class MultiGenerator 
			implements Component,
			           /* provide */
					   IntEventSender,
					   /* require */
					   RequireNamedIntEventReceiverService {
	
	// first version: unnamed bindings
	protected Map<String, IntEventReceiverService> receivers;
	
	protected MultiGenerator() {
		receivers = new HashMap<String, IntEventReceiverService>();
	}
	
	@Override
	public void bindIntEventReceiverService(IntEventReceiverService serv) {
		bindIntEventReceiverService("default", serv);
	}
	
	@Override
	public void bindIntEventReceiverService(String bindName, IntEventReceiverService serv) {
		receivers.put(bindName, serv);
	}
	
}
