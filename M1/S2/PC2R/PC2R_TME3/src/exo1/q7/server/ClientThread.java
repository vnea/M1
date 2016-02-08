package exo1.q7.server;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;
import java.util.List;


public class ClientThread extends Thread {
	private List<Socket> clients;
	private List<OutputStream> streams;

	
	public ClientThread(List<Socket> clients, List<OutputStream> streams) {
		this.clients = clients;
		this.streams = streams;
	}
	
	@Override
	public void run() {
		while (true) {
			Socket client = null;
			synchronized (clients) {
				// Client en attente ou pas
				if (clients.size() == 0) {
					try {
						clients.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				
				client = clients.remove(0);
			}
			
			// Requetes
			while (true) {
				try {
					BufferedReader in = new BufferedReader(
							new InputStreamReader(client.getInputStream()));
					
					while (true) {
						String l = in.readLine();
						if ("".equals(l) || l == null) {
							break;
						}
						
						synchronized (streams) {
							for (OutputStream os : streams) {
								if (!os.equals(client.getOutputStream())) {
									DataOutputStream out =
											new DataOutputStream(os);
									out.writeChars("Texte: " + l + "\n");
									out.flush();
								}
							}
						}
					}
				}
				catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
