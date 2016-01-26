package algorithms;

import java.awt.Point;
import java.util.ArrayList;
import java.util.Random;

/***************************************************************
 * TME 1: calcul de diamètre et de cercle couvrant minimum.    *
 *   - Trouver deux points les plus éloignés d'un ensemble de  *
 *     points donné en entrée.                                 *
 *   - Couvrir l'ensemble de poitns donné en entrée par un     *
 *     cercle de rayon minimum.                                *
 *                                                             *
 * class Circle:                                               *
 *   - Circle(Point c, int r) constructs a new circle          *
 *     centered at c with radius r.                            *
 *   - Point getCenter() returns the center point.             *
 *   - int getRadius() returns the circle radius.              *
 *                                                             *
 * class Line:                                                 *
 *   - Line(Point p, Point q) constructs a new line            *
 *     starting at p ending at q.                              *
 *   - Point getP() returns one of the two end points.         *
 *   - Point getQ() returns the other end point.               *
 ***************************************************************/
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
		
		/*******************
		 * PARTIE A ECRIRE *
		 *******************/
		
		return new Line(p,q);
	}
	
	// Exercice 8.2
	private ArrayList<Point> filtrageAklToussaint(ArrayList<Point> points) {
		// On crée le quadrilatère
		Point A, B, C, D;
		A = B = C = D = points.get(0);
		for (Point p : points) {
			// A : abscisse min
			if (p.getX() < A.getX()) {
				A = p;
			}
			
			// B : ordonnée min
			if (p.getY() < B.getY()) {
				B = p;
			}
			
			// C : abscisse max
			if (p.getX() > C.getX()) {
				C = p;
			}
			
			// D : ordonnée max
			if (p.getY() > D.getY()) {
				D = p;
			}
		}
		
		// On retire les points inutiles
		ArrayList<Point> filteredPoints = new ArrayList<Point>();
		for (Point X : points) {
			if (!pointIsInRect(A, B, C, D, X)) {
				filteredPoints.add(X);
			}
		}
		
		return filteredPoints;
	}
	
	// u = p1-p2 et v = p3-p4
	private double vectorProductZ(Point p1, Point p2, Point p3, Point p4) {
		final double ux = p2.getX() - p1.getX();
		final double uy = p2.getY() - p1.getY();
		final double vx = p4.getX() - p3.getX();
		final double vy = p4.getY() - p3.getY();

		return ux * vy - uy * vx;
	}
	
	private boolean pointIsInRect(Point A, Point B, Point C, Point D, Point X) {
		return (
			   // On teste X dans ABC
			   (vectorProductZ(A, B, A, X) * vectorProductZ(A, B, A, C) >= 0.0 &&
			   vectorProductZ(B, C, B, X) * vectorProductZ(B, C, B, A) >= 0.0 &&
			   vectorProductZ(A, C, A, X) * vectorProductZ(A, C, A, B) >= 0.0) ||
			   // On test X dans ACD
			   
			   (vectorProductZ(A, D, A, X) * vectorProductZ(A, D, A, C) >= 0.0 &&
			   vectorProductZ(D, C, D, X) * vectorProductZ(D, C, D, A) >= 0.0 &&
			   vectorProductZ(A, C, A, X) * vectorProductZ(A, C, A, D) >= 0.0));
	}
	
	// calculCercleMin: ArrayList<Point> --> Circle
	//   renvoie un cercle couvrant tout point de la liste, de rayon minimum.
	// Exercice 4
	/*
	public Circle calculCercleMin(ArrayList<Point> points) {
		if (points.isEmpty()) {
			return null;
		}
		points = filtrageAklToussaint(points);

		// Cas g�n�ral
		for (Point p : points) {
			for (Point q : points) {
				double cx = (p.getX() + q.getX()) * 0.5;
				double cy = (p.getY() + q.getY()) * 0.5;
				double radius = p.distance(q) * 0.5;
				Circle c = new Circle(new Point((int) cx, (int) cy), (int) radius);
				if (circleContainsAllPoints(points, c)) {
					return c;
				}
			}
		}

		// Cas du triangle
		
//		for (Point p : points) {
//			for (Point q : points) {
//				for (Point r : points) {
//					Circle c = cercleCirconsrit(p, q, r);
//					if (containsAll(points, c)) {
//						return c;
//					}
//				}
//			}
//		}
	    
		Point center = points.get(0);
		int radius = 100;
		System.out.println("Minimum Circle not found");
		return new Circle(center, radius);
	}
	*/
	
	// calculCercleMin: ArrayList<Point> --> Circle
	//   renvoie un cercle couvrant tout point de la liste, de rayon minimum.
	// Exercice 5
	
	public Circle calculCercleMin(ArrayList<Point> points) {
		if (points.isEmpty()) {
			return null;
		}
	    System.out.println("DEBUT calculCercleMin");
	    System.out.println(points.size());

		points = filtrageAklToussaint(points);
	    System.out.println(points.size());

		// Etape 0
		ArrayList<Point> copyPoints = new ArrayList<>(points);
		
		// Etape 1
	    Random rand = new Random();
	    Point dummyP = copyPoints.get(rand.nextInt(copyPoints.size()));
	    
	    // Etape 2
	    Point P = findFarthestPoint(copyPoints, dummyP);
		
	    // Etape 3
	    Point Q = findFarthestPoint(copyPoints, P);
	    
	    // Etape 4
	    Point C = new Point((int) ((P.getX() + Q.getX()) * 0.5),
	    		            (int) ((P.getY() + Q.getY()) * 0.5));
	    
	    // Etape 5
	    Circle CERCLE = new Circle(C, (int) C.distance(P));
	    
	    // Etape 6
	    copyPoints.remove(P);
	    copyPoints.remove(Q);
	    
	    // Etape 7
	    while (!copyPoints.isEmpty()) {
	    	Point S = copyPoints.get(rand.nextInt(copyPoints.size()));
	    	
	    	// Etape 8
	    	if (circleContainsPoint(CERCLE, S)) {
	    		copyPoints.remove(S);
	    	}
	    	// Etape 9, 10, 11
	    	else {
	    		double CS = S.distance(CERCLE.getCenter());
	    		double radiusPrime = (CS + CERCLE.getRadius()) * 0.5;
	    		double alpha = radiusPrime / CS;
	    		double beta = (CS - radiusPrime) / CS; 
	    		double cxPrime = alpha * CERCLE.getCenter().getX() +
	    				         beta * S.getX();
	    		double cyPrime = alpha * CERCLE.getCenter().getY() +
				                 beta * S.getY();
	    		CERCLE = new Circle(new Point((int) cxPrime, (int) cyPrime), (int) radiusPrime);
	    	}
	    }
	    
	    System.out.println("FIN calculCercleMin");
	    return CERCLE;
	}
	
	
	private Point findFarthestPoint(ArrayList<Point> points, Point p) {
	    Point farthestPoint = null;
	    double max = 0.0;
	    for (Point i : points) {
	    	double dist = p.distance(i);
	    	if (dist > max) {
	    		farthestPoint = i;
	    		max = dist;
	    	}
	    }
	    
		return farthestPoint;
	}
	
	private boolean circleContainsPoint(Circle c, Point p) {
		return p.distance(c.getCenter()) <= c.getRadius() + 20;
	}
	
	private boolean circleContainsAllPoints(ArrayList<Point> points, Circle c) {
		for (Point p : points) {
			if (!circleContainsPoint(c, p)) {
				return false;
			}
		}
		
		return true;
	}
	
	private Circle cercleCirconsrit(Point p1, Point p2, Point p3) {
		double a = -(p2.getX() - p1.getX()) / (p2.getY() - p1.getY());
		double b = (Math.pow(p2.getX(), 2.0) - Math.pow(p1.getX(), 2.0) +
				    Math.pow(p2.getY(), 2.0) - Math.pow(p1.getY(), 2.0)) /
				   (2.0 * (p2.getY() - p1.getY()));
		double aPrime = -(p3.getX() - p2.getX()) / (p3.getY() - p2.getY());
		double bPrime = (Math.pow(p3.getX(), 2.0) - Math.pow(p2.getX(), 2.0) +
				         Math.pow(p3.getY(), 2.0) - Math.pow(p2.getY(), 2.0)) /
				        (2.0 * (p3.getY() - p2.getY()));
		double xc = (b - bPrime) / (aPrime - a);
		double yc = a * xc + b;
		double radius = Math.sqrt(Math.pow(p1.getX() - xc, 2.0) +
				                  Math.pow(p1.getY() - yc, 2.0));
		
		return new Circle(new Point((int) xc, (int) yc), (int) radius);
	}
}
