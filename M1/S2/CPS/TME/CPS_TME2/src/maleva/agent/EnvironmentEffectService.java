
package maleva.agent;

import maleva.framework.Service;

public interface EnvironmentEffectService extends Service {
	int getEnvWidth();
	int getEnvHeight();
    void moveAgent(String id, int posx, int posy, int type);
}
