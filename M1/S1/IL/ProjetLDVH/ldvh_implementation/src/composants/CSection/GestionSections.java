/**
 * 
 */
package composants.CSection;

import interfaces.IGestionSections;
import interfaces.ISection;

import java.util.ArrayList;
import java.util.List;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class GestionSections implements IGestionSections {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private ISection premiereSection;
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private List<ISection> sections = new ArrayList<ISection>();

	/** 
	 * (non-Javadoc)
	 * @see IGestionSections#listeSections()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public List<ISection> listeSections() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return sections;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionSections#getPremiereSection()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public ISection getPremiereSection() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return premiereSection;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionSections#setPremiereSection(ISection section)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void setPremiereSection(ISection section) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		premiereSection = section;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionSections#addSection(ISection section)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void addSection(ISection section) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		sections.add(section);
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionSections#removeSection(ISection section)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void removeSection(ISection section) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		sections.remove(section);
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionSections#editerSection(ISection section)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void editerSection(ISection section) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré

		// end-user-code
	}
}