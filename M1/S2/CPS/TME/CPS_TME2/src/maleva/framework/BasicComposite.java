
package maleva.framework;

/** A helper implementation for Composite interface
 * Composite components that do not rely on
 * implementation inheritance may safely extends this
 * abstract class.
 * 
 * @author Frederic Peschanski
 */
public abstract class BasicComposite extends BasicComponent 
    implements Composite {
    
    public Service exportService() throws ServiceExportException {
        throw new ServiceExportException("Cannot export abstract 'Service'");
    }
}
