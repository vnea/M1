
package maleva.framework;

/** The root of Service export interfaces
 * Composite components may export internal services
 * provided by internal subcomponents without filtering
 * the client bindings. If filtering is needed then the
 * composite component may simply provide the service
 * and use the subcomponent as a delegate.
 * 
 * @author Frederic Peschanski
 */
public interface ExportService {
    /** export to clients an internal service provided by a subcomponent
     *  Composites generally rename the export method to allow the 
     *  discrimination among exported services (overload is not 
     *  possible since there is only a return type).
     *  After the export, a client component may bind to the service,
     *  the binding crosscuts the composite boundary.
     *  It is possible to filter the service by promoting the inner
     *  service to the enclosing composite, as a provided service
     *  (in this case, the service is *not* exported).
     *
     *  @return the exported service
     *  @throws ServiceExportException if the export is not allowed
     */
    Service exportService() throws ServiceExportException;
}
