/**
 * 
 */
package factory;

import interfaces.IEnchainement;
import interfaces.IGestionEnchainements;
import interfaces.IGestionLivres;
import interfaces.IGestionObjets;
import interfaces.IGestionSections;
import interfaces.ILivre;
import interfaces.IObjet;
import interfaces.ISection;

import composants.CEnchainement.Enchainement;
import composants.CEnchainement.GestionEnchainements;
import composants.CLivre.GestionLivres;
import composants.CLivre.Livre;
import composants.CObjet.GestionObjets;
import composants.CObjet.Objet;
import composants.CSection.GestionSections;
import composants.CSection.Section;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class Factory {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @param titre
	 * @param texte
	 * @param objets
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static ILivre newLivre(String titre, String desc, ISection premiereSection) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new Livre(titre, desc, premiereSection);
		// end-user-code
	}
	
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @param titre
	 * @param texte
	 * @param objets
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static ISection newSection(String titre, String texte) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new Section(titre, texte);
		// end-user-code
	}

	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @param depart
	 * @param arrivee
	 * @param objets
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static IEnchainement newEnchainement(ISection depart, ISection arrivee) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new Enchainement(depart, arrivee);
		// end-user-code
	}

	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @param nom
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static IObjet newObjet(String nom) {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new Objet(nom);
		// end-user-code
	}

	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static IGestionSections newGestionSections() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new GestionSections();
		// end-user-code
	}

	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static IGestionObjets newGestionObjets() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new GestionObjets();
		// end-user-code
	}

	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static IGestionLivres newGestionLivres() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new GestionLivres();
		// end-user-code
	}

	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @return
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	public static IGestionEnchainements newGestionEnchainements() {
		// begin-user-code
		// TODO Module de remplacement de méthode auto-généré
		return new GestionEnchainements();
		// end-user-code
	}
}