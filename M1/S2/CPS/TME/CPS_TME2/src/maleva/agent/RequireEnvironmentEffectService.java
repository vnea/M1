
package maleva.agent;

import maleva.framework.RequireService;
import maleva.framework.ServiceBindException;

public interface RequireEnvironmentEffectService extends RequireService {
    void bindEnvironmentEffectService(EnvironmentEffectService ees) throws ServiceBindException;
}
