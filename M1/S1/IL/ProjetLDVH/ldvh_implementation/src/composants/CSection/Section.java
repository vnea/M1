/**
 * 
 */
package composants.CSection;

import factory.Factory;
import interfaces.IGestionEnchainements;
import interfaces.IGestionObjets;
import interfaces.ISection;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class Section implements ISection {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private IGestionObjets objetsRecuperables;
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
	private String texte;
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private IGestionEnchainements enchainements;

	public Section(String titre, String texte) {
		this.titre = titre;
		this.texte = texte;
		objetsRecuperables = Factory.newGestionObjets();
		enchainements = Factory.newGestionEnchainements();
	}

	/** 
	 * (non-Javadoc)
	 * @see ISection#getEnchainements()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public IGestionEnchainements getEnchainements() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return enchainements;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ISection#getObjetsRécupérables()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public IGestionObjets getObjetsRecuperables() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return objetsRecuperables;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ISection#setTexte(String texte)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void setTexte(String texte) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		this.texte = texte;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ISection#setTitre(String titre)
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
	 * @see ISection#getTexte()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public String getTexte() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return texte;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see ISection#getTitre()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public String getTitre() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return titre;
		// end-user-code
	}
}