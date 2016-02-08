package exo1.q7.server;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.List;
import java.util.Vector;


public class EchoServerPool extends Thread {
	private ServerSocket ss;
	
	private final static int NB_THREADS = 100; 
	private List<Thread> threads;
	private List<Socket> clients;
	private List<OutputStream> streams;

	
	
	public EchoServerPool(int port) {		
		try {
			ss = new ServerSocket(port);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		
		threads = new Vector<Thread>(NB_THREADS);
		clients = new Vector<Socket>();
		streams = new Vector<OutputStream>();
	}
	
	@Override 
	public void run() {
		for (int i = 0; i < NB_THREADS; ++i) {
			threads.add(new ClientThread(clients, streams));
			threads.get(i).start();
		}

		while (true) {
			Socket client = null;
			try {
				client = ss.accept();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			
			synchronized (clients) {
				clients.add(client);
				try {
					streams.add(client.getOutputStream());
				} catch (IOException e) {
					e.printStackTrace();
				}
				clients.notify();
			}
		}
	}
}
