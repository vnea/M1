package dataflow.generators;

import java.util.ArrayList;
import java.util.List;

import dataflow.core.Component;
import dataflow.core.IntEventReceiverService;
import dataflow.core.IntEventSender;
import dataflow.core.IntEvent;
import dataflow.core.RequireIntEventReceiverService;

public abstract class SimpleGenerator 
			implements Component, IntEventSender,
					   /* require */
					   RequireIntEventReceiverService {
	
	// first version: unnamed bindings
	protected List<IntEventReceiverService> receivers;
	
	protected SimpleGenerator() {
		receivers = new ArrayList<IntEventReceiverService>();
	}
	
	@Override
	public void bindIntEventReceiverService(IntEventReceiverService serv) {
		receivers.add(serv);
	}
		
	@Override
	public void send(IntEvent intEvent) {
		for(IntEventReceiverService receiver : receivers) {
				receiver.onIntEvent(intEvent);
		}
	}
}
