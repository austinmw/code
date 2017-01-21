import java.util.Scanner;

class Untitled {
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		methods_params2 methods_params2Object = new methods_params2();
		
		System.out.println("Enter your name here: ");
		String name = input.nextLine();
		
		methods_params2Object.simpleMessage(name);
		
	}
}