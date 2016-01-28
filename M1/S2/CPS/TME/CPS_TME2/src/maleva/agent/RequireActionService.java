
package maleva.agent;

import maleva.framework.RequireService;
import maleva.framework.ServiceBindException;

public interface RequireActionService extends RequireService {
    void bindActionService(ActionService as) throws ServiceBindException;
}

