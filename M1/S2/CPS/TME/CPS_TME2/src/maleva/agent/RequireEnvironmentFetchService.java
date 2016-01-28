
package maleva.agent;

import maleva.framework.RequireService;
import maleva.framework.ServiceBindException;

public interface RequireEnvironmentFetchService extends RequireService {
    void bindEnvironmentFetchService(EnvironmentFetchService ees) throws ServiceBindException;
}

