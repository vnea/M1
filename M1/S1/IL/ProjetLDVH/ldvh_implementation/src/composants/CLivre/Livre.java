/**
 * 
 */
package composants.CLivre;

import factory.Factory;
import interfaces.IGestionSections;
import interfaces.ILivre;
import interfaces.ISection;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class Livre implements ILivre {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private String titre;
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private String desc;
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private IGestionSections sections;

	public Livre(String titre, String desc, ISection premiereSection) {
		// TODO Auto-generated constructor stub
		this.titre = titre;
		this.desc = desc;
		this.sections = Factory.newGestionSections();
		this.sections.setPremiereSection(premiereSection);
	}

	/** 
	 * (non-Javadoc)
	 * @see ILivre#getTitre()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public String getTitre() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return titre;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ILivre#setTitre(String titre)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void setTitre(String titre) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		this.titre = titre;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ILivre#getDescription()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public String getDescription() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return desc;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ILivre#setDescription(String description)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void setDescription(String description) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		desc = description;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ILivre#getSections()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public IGestionSections getSections() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return sections;
		// end-user-code
	}
}