package maleva.framework;

/** The basic interface implemented by all Tamago composites.
 *  A composite (generally) contains subcomponents and may
 *  require, provide and export services.
 *
 * @author Frederic Peschanski
 */
public interface Composite extends Component, ExportService {
}

