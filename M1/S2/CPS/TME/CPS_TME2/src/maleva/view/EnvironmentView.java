package maleva.view;

import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.BevelBorder;

import maleva.agent.Agent;
import maleva.agent.Environnement;

public class EnvironmentView extends Environnement {

	private JFrame envFrame; 
	private JPanel envPanel;
	
	private List<BufferedImage> preySprites;
	private List<BufferedImage> predSprites;
	
	private Map<String, BufferedImage> activeSprites;
	
	private Random random;
	
	public EnvironmentView(int width, int height) {
		super(width, height);	
		
		random = new Random();
		
		loadSprites();
		activeSprites = new HashMap<String, BufferedImage>();
		
		envFrame = new JFrame("Maleva simulator");
		envFrame.setSize(width+10, height+30);
		
		Container contentPane = envFrame.getContentPane();
		Box vbox = Box.createVerticalBox();
		envPanel = new EnvPanel();
		envPanel.setBorder(BorderFactory.createBevelBorder(BevelBorder.LOWERED));
		envPanel.setBackground(Color.WHITE);
		vbox.add(envPanel);
		
		contentPane.add(vbox);
		
		envFrame.setVisible(true);
				
	}
	
	@Override
	public void registerAgent(String id, int posx, int posy, int type) {
		super.registerAgent(id, posx, posy, type);
		
		if(type==Agent.TYPE_PROIE) {
			int img_ref = random.nextInt(preySprites.size());
			activeSprites.put(id, preySprites.get(img_ref));
		} else if(type==Agent.TYPE_PRED) {
			int img_ref = random.nextInt(predSprites.size());
			activeSprites.put(id, predSprites.get(img_ref));
		} else {
			throw new Error("Cannot register: not a prey or a predator");
		}
		
		envPanel.repaint();
	}
	
	
	@Override
	public void unregisterAgent(String id) {
		activeSprites.remove(id);
		
		super.unregisterAgent(id);
	}
	
	@Override
	public void moveAgent(String id, int posx, int posy, int type) {
		super.moveAgent(id, posx, posy, type);
		envPanel.repaint();
	}
	
	private void loadSprites() {
		preySprites = new ArrayList<BufferedImage>();
		
		List<String> preyImageFiles = new ArrayList<String>();
		preyImageFiles.add("astromechdroid.png");
		preyImageFiles.add("jawa.png");
		preyImageFiles.add("princessleia.png");
		preyImageFiles.add("yoda.png");
		preyImageFiles.add("chewie.png");
		preyImageFiles.add("jedi.png");
		preyImageFiles.add("obiwan1.png");
		preyImageFiles.add("obiwan2.png");
		preyImageFiles.add("protocoldroid1.png");
		preyImageFiles.add("hansolo.png");
		preyImageFiles.add("luke.png");
		
		for(String preyImageFile : preyImageFiles) {
			BufferedImage img = null;
			try {
			    img = ImageIO.read(new File("assets/" + preyImageFile));
			} catch (IOException e) {
				throw new Error("Cannot load image file: " + preyImageFile);
			}
			preySprites.add(img);
		}
		
		predSprites = new ArrayList<BufferedImage>();
		
		List<String> predImageFiles = new ArrayList<String>();
		predImageFiles.add("mandalorian.png");
		predImageFiles.add("darthvader.png");
		predImageFiles.add("protocoldroid1.png");
		predImageFiles.add("darthmaul.png");
		predImageFiles.add("stormtrooper.png");
		predImageFiles.add("darthsidious.png");

		for(String predImageFile : predImageFiles) {
			BufferedImage img = null;
			try {
			    img = ImageIO.read(new File("assets/" + predImageFile));
			} catch (IOException e) {
				throw new Error("Cannot load image file: " + predImageFile);
			}
			predSprites.add(img);
		}
	}
	
	class EnvPanel extends JPanel {
		private static final long serialVersionUID = -3764464748815416179L;

		EnvPanel() {
			super(true); // double-buffered
		}
		
		@Override
		public void paint(Graphics g) {
			// TODO Auto-generated method stub
			super.paint(g);
			
			/*
AffineTransform identity = new AffineTransform();

Graphics2D g2d = (Graphics2D)g;
AffineTransform trans = new AffineTransform();
trans.setTransform(identity);
trans.rotate( Math.toRadians(45) );
g2d.drawImage(image, trans, this); 
			 */
			
			Graphics2D g2d = (Graphics2D) g;
			
			for(String agentId : activeSprites.keySet()) {
				AgentSight aref = agents.get(agentId);
				g2d.drawImage(activeSprites.get(agentId), 
						aref.getX()-16, aref.getY()-16, aref.getX()+16, aref.getY()+16, // destination 
						0, 0, 32, 32,  // source
						null);
			}
		
			Toolkit.getDefaultToolkit().sync();
	        g.dispose();
		}
	}
	
}
