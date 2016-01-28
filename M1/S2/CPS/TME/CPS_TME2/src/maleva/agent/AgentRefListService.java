
package maleva.agent;

import maleva.framework.Service;

public interface AgentRefListService extends Service {
    AgentRef[] getAgentRefs();
    int getNbAgentRefs();
}