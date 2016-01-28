package maleva.framework;

/** The controller interface for separate initialize phase
 * in the component lifecycle.
 * Implementors of this controller may be externally 
 * initialized, which becomes then different than creation.
 * 
 * @author Frederic Peschanski
 */
public interface LCInitializeController extends LifeCycleController {

    /** Start the initialization phase of a component.
     * this method may be safely overloaded to allow parameters for
     * the initialization. It is a good practice to end the overloaded
     * initialize with a call to the initialize method without parameter
     * in order to cope with the lifecycle management issues.
     * 
     *  @throws LifeCycleException if the component may not be initialized
     */
    public void initialize() throws LifeCycleException; // to call when component has
                                                        // been correctly initialized
}

