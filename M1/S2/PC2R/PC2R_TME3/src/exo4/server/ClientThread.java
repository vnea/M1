package exo4.server;
import java.io.BufferedReader;
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
						String s = "TEST";
						System.out.println(l);

						if ("".equals(l) || l == null) {
							break;
						}
						
						switch (l) {
						
						}
						if ("GET".equals(l)) {
							System.out.println("GET OK");
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
