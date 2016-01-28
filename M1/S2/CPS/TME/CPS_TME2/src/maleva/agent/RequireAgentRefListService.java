
package maleva.agent;

import maleva.framework.RequireService;
import maleva.framework.ServiceBindException;

public interface RequireAgentRefListService extends RequireService {
    void bindAgentRefListService(AgentRefListService arls) throws ServiceBindException;
}

