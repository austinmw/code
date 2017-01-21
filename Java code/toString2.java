public class toString2 {
	private int month;
	private int day;
	private int year;

	public toString2(int m, int d, int y){
		month = m;
		day = d;
		year = y;
		System.out.printf("The constructor for this is %s\n", this);
	}
	
	// this references toString function when asked for string representation of object	
	// have to call this "toString"! (Java built-in)
	public String toString() {
		return String.format("%d/%d/%d", month, day, year);
	}
	
}