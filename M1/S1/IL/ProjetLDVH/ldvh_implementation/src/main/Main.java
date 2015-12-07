package main;

import factory.Factory;
import interfaces.IEnchainement;
import interfaces.IGestionLivres;
import interfaces.ILivre;
import interfaces.IObjet;
import interfaces.ISection;

public class Main {
	public static void main(String args[]) {
		// Création des objets
		IObjet o1 = Factory.newObjet("Plume");

		// Créations de différentes sections + ajout des objets
		ISection s1 = Factory.newSection("Section 1", "C'est la section 1 (départ)");
		ISection s2 = Factory.newSection("Section 2", "C'est la section 2");
		s1.getObjetsRecuperables().addObjet(o1);

		// Création des enchainements + ajout des objets
		IEnchainement e1 = Factory.newEnchainement(s1, s2);
		e1.getObjets().addObjet(o1);

		// Ajout des enchainements aux sections
		s1.getEnchainements().addEnchainement(e1);
		
		// Création du livre + ajout des sections
		ILivre livre = Factory.newLivre("Mon LDVH", "C'est la description du livre", s1);
		livre.getSections().addSection(s2);
		
		// Création d'un gestionnaire de livre + chargement du livre
		IGestionLivres gl = Factory.newGestionLivres();
		gl.chargerLivre(livre);
	}
}


