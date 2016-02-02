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
    //System.out.println(points.size());
    
//    points = triParPixel(points);
//    if (true) return points;
    
    //System.out.println(points.size());

    
    ArrayList<Point> enveloppe = new ArrayList<Point>();
    enveloppe = jarvis(points);
    /*
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
    		
    		//On test si chaque point est du m�me c�t�
        	while(sur_enveloppe && i<points.size()){
        		c =  points.get(i);
        		prod_vec_tmp = vectorProductZ(a, b, a, c);
        		if(produit_vec * prod_vec_tmp < 0.0){
        			sur_enveloppe = false;
        		}
        		else if(prod_vec_tmp == 0){ //Si les points sont align�s
        			distance = a.distance(b);
        			// On prend les plus �loign�s
        			if(distance < a.distance(c)){
        				b = c;
        			}
        		}
        		i++;
        	}
        	// On les ajoutent � l'enveloppe s'ils n'en font pas d�j� parti
        	// On ne retire pas les doublons finalement 
        	// car sinon les cot�s ne seront pas trac�s 
        	// comme on veux (l� ils sont tous reli�s entre eux du coup)
        	if(sur_enveloppe){
        		//if(!enveloppe.contains(a))
        			enveloppe.add(a);
        		//if(!enveloppe.contains(b))
        			enveloppe.add(b);
        	}
        }
    }
  */
    return enveloppe;
  }
  
  /*
	public ArrayList<Point> enveloppeConvexe(ArrayList<Point> points) {
		if (points.size() < 3) {
			return null;
		}
	
	    // Application du filtre par pixel
	    points = triParPixel(points);
	
	    
	    ArrayList<Point> enveloppe = new ArrayList<Point>();	    
	    
	    for (Point a : points) {
	    	for (Point b : points) {
	    		if (a != b) {	    			
//	    			int i = 0;
//	    			boolean isEdgeConverHull = true;
//	    			while (isEdgeConverHull && i < points.size()) {
//	    				double valueVectorProduct = vectorProduct2D(a, b, points.get(i));
//	    				if (valueVectorProduct < 0.0) {
//	    					isEdgeConverHull = false;
//	    				}
//	    			}
	    			
	    			
	    			if (isEdgeConvexHull(points, a, b)) {
	    				enveloppe.add(a);
	    				enveloppe.add(b);
	    			}
	    		}
	        }
	    }
	  
	    return enveloppe;
	}
  */
  
  private double vectorProductZ(Point p1, Point p2, Point p3, Point p4) {
		final double ux = p2.getX() - p1.getX();
		final double uy = p2.getY() - p1.getY();
		final double vx = p4.getX() - p3.getX();
		final double vy = p4.getY() - p3.getY();

		return ux * vy - uy * vx;
  }
  
  private double vectorProduct2D(Point p1, Point p2, Point p3) {
		final double ux = p2.getX() - p1.getX();
		final double uy = p2.getY() - p1.getY();
		final double vx = p3.getX() - p1.getX();
		final double vy = p3.getY() - p1.getY();

		return ux * vy - uy * vx;
  }
  
  // Exo 2
  private ArrayList<Point> triParPixel(ArrayList<Point> points) {
	  ArrayList<Point> ymin = new ArrayList<>(points.size());
	  ArrayList<Point> ymax = new ArrayList<>(points.size());

	  // On remplit ymin et yman � null
	  for (int i = 0; i < points.size(); ++i)  {
		  ymin.add(null);
		  ymax.add(null);
	  }
	  
	  // Mise � jour de ymin
	  for (Point p : points) {
		  int px = (int) p.getX();
		  
		  Point yminPx = ymin.get((int) p.getX());
		  if (yminPx == null || yminPx.y < p.y) {
			  ymin.set(px, p);
		  }
		  
		  Point ymaxPx = ymax.get(px);
		  if (ymaxPx == null || ymaxPx.y > p.y) {
			  ymax.set(px, p);
		  }
	  }
	  
	  // On n'ajoute dans result que les �l�ments non nuls
	  ArrayList<Point> result = new ArrayList<>(points.size());
	  for (int i = 0; i < points.size(); i++)  {
		  if (ymin.get(i) != null) {
			  result.add(ymin.get(i));
		  }
	  }
	  
	  for (int i = points.size() - 1; i >= 0; i--)  {
		  if (ymax.get(i) != null) {
			  result.add(ymax.get(i));
		  }
	  }	
	  
	  return result;
  }
  
  private ArrayList<Point> jarvis(ArrayList<Point> points) {	  
	  System.out.println("Start - Jarvis");

	  // Etape 1 : on cherche un premier point P de l'enveloppe convexe : abscisse minimum
	  Point P = points.get(0);
	  int index = 0;
	  for (int i = 1; i < points.size(); ++i) {
		  if (points.get(i).getX() < P.getX()) {
			  P = points.get(i);
			  index = i;
		  }
	  }
	  
	  ArrayList<Point> result = new ArrayList<Point>();
	  result.add(P);
	  

	  // Etape 2 : on cherche un point Q tel que PQ est un c�t� de l'enveloppe convexe
	  Point Q;
	  do {
		  Q = points.get(++index % points.size());
	  } while (!isEdgeConvexHull(points, P, Q));
	  result.add(Q);

	  // Etape 3, 4 et 5
	  do {
		  result.add(Q);
		  
		  Point R = findMinimalAngle(points, P, Q);
		  P = Q;
		  Q = R;
	  } while (P != result.get(0));
	  
	  return result;
  }
  
  private boolean isEdgeConvexHull(ArrayList<Point> points, Point p, Point q) {
	  for (Point r : points) {
		  if (vectorProductZ(p, r, p, q) < 0.0) {
			  return false;
		  }
	  }
	  
	  return true;
  }
  
  private Point findMinimalAngle(ArrayList<Point> points, Point P, Point Q) {
	  Point R = null;
	  double minCosAngle = -1.0;

	  for (Point pi : points) {
		  if (pi != Q && pi != P) {
			  double pqx, pqy, qrx, qry;
			  pqx = Q.x - P.x;
			  pqy = Q.y - P.y;
			  qrx = pi.x - Q.x;
			  qry = pi.y - Q.y;
			  double currentCosAngle = (pqx * qrx + pqy * qry) /
					            	   (Math.sqrt(pqx * pqx + pqy * pqy) *
					                    Math.sqrt(qrx * qrx + qry * qry));
			  
			  if (currentCosAngle > minCosAngle) {
				  R = pi;
				  minCosAngle = currentCosAngle;
			  }
		  }
	  }
	  
	  return R;
  }
  
}

