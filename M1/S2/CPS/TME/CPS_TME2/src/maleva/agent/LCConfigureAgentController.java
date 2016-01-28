
package maleva.agent;

import maleva.framework.LifeCycleController;
import maleva.framework.LifeCycleException;

public interface LCConfigureAgentController extends LifeCycleController {
    void configure(Environnement env, int x, int y) throws LifeCycleException;
}
