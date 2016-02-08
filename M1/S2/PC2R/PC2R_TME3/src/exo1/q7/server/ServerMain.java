package exo1.q7.server;

public class ServerMain {
	public static void main(String[] args) {
		EchoServerPool server = new EchoServerPool(2001);
		server.start();
	}
}
