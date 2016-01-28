
package maleva.agent;

import maleva.framework.RequireService;
import maleva.framework.ServiceBindException;

public interface RequireEnvironmentRegisterService extends RequireService {
    void bindEnvironmentRegisterService(EnvironmentRegisterService ees) throws ServiceBindException;
}
