/**
 * 
 */
package composants.CEnchainement;

import factory.Factory;
import interfaces.IEnchainement;
import interfaces.IGestionObjets;
import interfaces.ISection;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class Enchainement implements IEnchainement {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private ISection depart;
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private ISection arrivee;
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private IGestionObjets objets;

	public Enchainement(ISection depart, ISection arrivee) {
		// TODO Auto-generated constructor stub
		this.depart = depart;
		this.arrivee = arrivee;
		this.objets = Factory.newGestionObjets();
	}

	/** 
	 * (non-Javadoc)
	 * @see IEnchainement#getDepart()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public ISection getDepart() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return depart;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IEnchainement#getArrivee()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public ISection getArrivee() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return arrivee;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IEnchainement#getObjets()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public IGestionObjets getObjets() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return objets;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IEnchainement#setDepart(composants.interfaces.ISection section)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void setDepart(ISection section) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		depart = section;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IEnchainement#setArrivee(composants.interfaces.ISection section)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void setArrivee(ISection section) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		arrivee = section;
		// end-user-code
	}
}