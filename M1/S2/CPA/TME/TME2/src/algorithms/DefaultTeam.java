package algorithms;

import java.awt.Point;
import java.util.ArrayList;
import java.util.Random;

import supportGUI.Circle;
import supportGUI.Line;

public class DefaultTeam {

  // calculDiametre: ArrayList<Point> --> Line
  //   renvoie une pair de points de la liste, de distance maximum.
  public Line calculDiametre(ArrayList<Point> points) {
    if (points.size()<3) {
      return null;
    }

    Point p=points.get(0);
    Point q=points.get(1);

    return new Line(p,q);
  }

  // calculDiametreOptimise: ArrayList<Point> --> Line
  //   renvoie une pair de points de la liste, de distance maximum.
  public Line calculDiametreOptimise(ArrayList<Point> points) {
    if (points.size()<3) {
      return null;
    }

    Point p=points.get(1);
    Point q=points.get(2);

    /*******************
     * PARTIE A ECRIRE *
     *******************/
    return new Line(p,q);
  }

  // calculCercleMin: ArrayList<Point> --> Circle
  //   renvoie un cercle couvrant tout point de la liste, de rayon minimum.
  public Circle calculCercleMin(ArrayList<Point> points) {
    if (points.isEmpty()) {
      return null;
    }

    Point center=points.get(0);
    int radius=100;

    /*******************
     * PARTIE A ECRIRE *
     *******************/
    return new Circle(center,radius);
  }

  // enveloppeConvexe: ArrayList<Point> --> ArrayList<Point>
  //   renvoie l'enveloppe convexe de la liste.
  public ArrayList<Point> enveloppeConvexe(ArrayList<Point> points){
    if (points.size()<3) {
      return null;
    }

    // Application du filtre par pixel
    System.out.println(points.size());
    points = triParPixel(points);
    System.out.println(points.size());

    ArrayList<Point> enveloppe = new ArrayList<Point>();
    boolean sur_enveloppe = true;
    int i;
    double produit_vec, prod_vec_tmp;
    //ArrayList<Point> pts_tmp = new ArrayList<Point>();
    Random rand = new Random();
    Point c = null;
    double distance;
    
    for(Point a : points){
    	for(Point b : points){
    		if(a.equals(b)){
    			continue;
    		}
    		
    		produit_vec = 0.0;    		
    		sur_enveloppe = true;
    		i = 0;
    		
    		//On prend un point au hasard pour initialisation
    		while(produit_vec == 0.0){
    			c = points.get(rand.nextInt(points.size()));
    			produit_vec = vectorProductZ(a, b, a, c);
    		}
    		
    		//On test si chaque point est du même côté
        	while(sur_enveloppe && i<points.size()){
        		c =  points.get(i);
        		prod_vec_tmp = vectorProductZ(a, b, a, c);
        		if(produit_vec * prod_vec_tmp < 0.0){
        			sur_enveloppe = false;
        		}
        		else if(prod_vec_tmp == 0){ //Si les points sont alignés
        			distance = a.distance(b);
        			// On prend les plus éloignés
        			if(distance < a.distance(c)){
        				b = c;
        			}
        		}
        		i++;
        	}
        	// On les ajoutent à l'enveloppe s'ils n'en font pas déjà parti
        	/* On ne retire pas les doublons finalement 
        	 * car sinon les cotés ne seront pas tracés 
        	 * comme on veux (là ils sont tous reliés entre eux du coup)*/
        	if(sur_enveloppe){
        		//if(!enveloppe.contains(a))
        			enveloppe.add(a);
        		//if(!enveloppe.contains(b))
        			enveloppe.add(b);
        	}
        }
    }
  
    return enveloppe;
  }
  
  private double vectorProductZ(Point p1, Point p2, Point p3, Point p4) {
		final double ux = p2.getX() - p1.getX();
		final double uy = p2.getY() - p1.getY();
		final double vx = p4.getX() - p3.getX();
		final double vy = p4.getY() - p3.getY();

		return ux * vy - uy * vx;
	}

  private ArrayList<Point> triParPixel(ArrayList<Point> points) {
	  ArrayList<Point> ymin = new ArrayList<>(points.size());
	  ArrayList<Point> ymax = new ArrayList<>(points.size());

	  // On remplit ymin et yman à null
	  for (Point p : points)  {
		  ymin.add(null);
		  ymax.add(null);
	  }
	  
	  // Mise à jour de ymin
	  for (Point p : points) {
		  int px = (int) p.getX();
		  Point yminPx = ymin.get(px);
		  /*
		   *  Ici je ne sais pas si c'est yminPx.getY() > p.getY() ou yminPx.getY() < p.getY()
		   *  vu que l'axe des Y est inversé
		   */
		  if (yminPx == null || yminPx.getY() < p.getY()) {
			  ymin.set(px, p);
		  }
	  }
	  
	  // Mise à jour de yman
	  for (Point p : points) {
		  int py = (int) p.getY();
		  Point ymaxPy = ymax.get(py);
		  if (ymaxPy == null || ymaxPy.getX() < p.getX()) {
			  ymax.set(py, p);
		  }
	  }
	  
	  // On n'ajoute dans result que les éléments non nuls
	  ArrayList<Point> result = new ArrayList<>(points.size());
	  for (int i = 0; i < points.size(); ++i)  {
		  if (ymin.get(i) != null) {
			  result.add(ymin.get(i));
		  }
		  if (ymax.get(i) != null) {
			  result.add(ymax.get(i));
		  }
	  }	  
	  
	  return result;
  }
}
