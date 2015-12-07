/**
 * 
 */
package composants.CObjet;

import interfaces.IGestionObjets;
import interfaces.IObjet;

import java.util.ArrayList;
import java.util.List;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class GestionObjets implements IGestionObjets {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private List<IObjet> objets = new ArrayList<IObjet>();

	/** 
	 * (non-Javadoc)
	 * @see IGestionObjets#listeObjets()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public List<IObjet> listeObjets() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return objets;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionObjets#addObjet(IObjet objet)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void addObjet(IObjet objet) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		objets.add(objet);
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionObjets#removeObjet(IObjet objet)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void removeObjet(IObjet objet) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		objets.remove(objet);
		// end-user-code
	}
}