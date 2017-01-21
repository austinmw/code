import java.util.Random;

class Untitled {
	public static void main(String[] args) {
		
		Random dice = new Random();
		
		int num;
		
		num = dice.nextInt(6); // 0-5
		System.out.println(num);
		
		num = 1+dice.nextInt(6); // 1-6
		System.out.println(num);
		
		
	}
}