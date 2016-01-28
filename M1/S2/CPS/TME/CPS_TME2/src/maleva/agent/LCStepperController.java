
package maleva.agent;

import maleva.framework.LifeCycleController;
import maleva.framework.LifeCycleException;

public interface LCStepperController extends LifeCycleController {
    boolean step() throws LifeCycleException;
}
