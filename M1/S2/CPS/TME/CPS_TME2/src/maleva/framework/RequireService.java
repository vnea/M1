/*******************************************
 * Copyright (C) 2005, Frederic Peschanski*
 *         >> DO NOT DISTRIBUTE <<         *
 *******************************************/

package maleva.framework;

/** The root of Service requirement interfaces
 * A component requiring a given service must implement
 * this interface and the bind method so that the
 * component can be dynamically bound to a provider
 * (implementor) component.
 * 
 * @author Frederic Peschanski
 */
public interface RequireService {
    /** Bind dynamically a provider service to the component.
     *  Components generally overload the bind method to allow the 
     *  discrimination among required services
     *
     *  @param s the required service to bind to
     *  @throws ServiceBindException if the binding is not allowed
     */
    void bind(Service s) throws ServiceBindException;
}
