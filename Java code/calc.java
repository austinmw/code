import java.util.Scanner;

class Untitled {
	public static void main(String[] args) {
		
		Scanner myscan = new Scanner(System.in);
		Double fnum, snum, ans;
		System.out.println("Enter first num: ");
		fnum = myscan.nextDouble();
		System.out.println("Enter second num: ");
		snum = myscan.nextDouble();
		ans = fnum + snum;
		System.out.println(ans);
		
	}
}