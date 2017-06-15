import java.util.Scanner;

class Untitled {
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		methods_instances2 myObject = new methods_instances2();
		
		System.out.println("Enter name here: ");
		String temp = input.nextLine();
		myObject.setName(temp);
		myObject.saying();
		
	}
}