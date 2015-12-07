/**
 * 
 */
package composants.CObjet;

import interfaces.IObjet;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class Objet implements IObjet {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private String nom;

	public Objet(String nom) {
		// TODO Auto-generated constructor stub
		this.nom = nom;
	}

	/** 
	 * (non-Javadoc)
	 * @see IObjet#setNom(String nom)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void setNom(String nom) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		this.nom = nom;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IObjet#getNom()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public String getNom() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return nom;
		// end-user-code
	}
}