
package maleva.agent;

import maleva.framework.Service;

public interface EnvironmentRegisterService extends Service {
    void registerAgent(String id, int posx, int posy, int type);
    void unregisterAgent(String id);
}
