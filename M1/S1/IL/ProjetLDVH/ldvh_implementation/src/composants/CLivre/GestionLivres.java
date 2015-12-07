/**
 * 
 */
package composants.CLivre;

import interfaces.IEnchainement;
import interfaces.IGestionLivres;
import interfaces.ILivre;
import interfaces.IObjet;
import interfaces.ISection;

import java.util.ArrayList;
import java.util.List;

/** 
 * <!-- begin-UML-doc -->
 * <!-- end-UML-doc -->
 * @author 3107638
 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
 */
public class GestionLivres implements IGestionLivres {
	/** 
	 * <!-- begin-UML-doc -->
	 * <!-- end-UML-doc -->
	 * @generated "UML vers Java (com.ibm.xtools.transform.uml2.java5.internal.UML2JavaTransform)"
	 */
	private List<ILivre> livres = new ArrayList<ILivre>();

	@Override
	public List<ILivre> listeLivres() {
		// TODO Auto-generated method stub
		return livres;
	}

	@Override
	public void chargerLivre(ILivre livre) {
		// Titre + description du livre
		System.out.println("Titre du livre : " + livre.getTitre());
		System.out.println("Description du livre : " + livre.getDescription());
		
		// Affichage des sections
		System.out.println("\n\nLes sections : ");
		List<ISection> sections = livre.getSections().listeSections();
		sections.add(0, livre.getSections().getPremiereSection());
		for (ISection section : sections) {
			System.out.println("Titre : " + section.getTitre());
			System.out.println("Texte : " + section.getTexte());
			
			// Affichage des objets récupérables
			List<IObjet> objets = section.getObjetsRecuperables().listeObjets();
			System.out.print("Objet(s) récupérable(s) : ");
			if (objets.isEmpty()) {
				System.out.print("aucun");
			}
			else {
				System.out.print(objets.get(0).getNom());
				for (int i = 1; i <  objets.size(); ++i) {
					System.out.print(" - " + objets.get(i).getNom());
				} 
			}
			System.out.println("\n");
		}
		
		// Affichage des enchainements
		System.out.println("\nLes enchaénements : ");
		for (ISection section : sections) {
			List<IEnchainement> enchainements = section.getEnchainements().listeEnchainements();
			for (IEnchainement enchainement : enchainements) {
				System.out.println("Départ : " + enchainement.getDepart().getTexte());
				System.out.println("Arrivée : " + enchainement.getArrivee().getTexte());

				// Affichage des objets recquis
				List<IObjet> objets = enchainement.getObjets().listeObjets();
				System.out.print("Objet(s) recquis(s) : ");
				if (objets.isEmpty()) {
					System.out.print("aucun");
				}
				else {
					System.out.print(objets.get(0).getNom());
					for (int i = 1; i <  objets.size(); ++i) {
						System.out.print(" - " + objets.get(i).getNom());
					} 
				}
				System.out.println("\n");
			}
		}
	}

	@Override
	public void sauvergarderLivre(ILivre livre) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void supprimerLivre(ILivre livre) {
		// TODO Auto-generated method stub
		
	}
}