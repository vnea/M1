/**
 * 
 */
package composants.CEnchainement;

import interfaces.IEnchainement;
import interfaces.IGestionEnchainements;
import interfaces.IObjet;

import java.util.ArrayList;
import java.util.List;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class GestionEnchainements implements IGestionEnchainements {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private List<IEnchainement> enchainements = new ArrayList<IEnchainement>();

	/** 
	 * (non-Javadoc)
	 * @see IGestionEnchainements#listeEnchainements()
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public List<IEnchainement> listeEnchainements() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return enchainements;
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionEnchainements#addEnchainement(String texte, IGestionEnchainements sectionArrivee, IObjet... objets)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void addEnchainement(IEnchainement enchainement) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		enchainements.add(enchainement);
		// end-user-code
	}

	/** 
	 * (non-Javadoc)
	 * @see IGestionEnchainements#removeEnchainement(IEnchainement enchainement)
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public void removeEnchainement(IEnchainement enchainement) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		enchainements.remove(enchainement);
		// end-user-code
	}
}