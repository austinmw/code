class Untitled {
	
	public static void main(String[] args) {
		
		int[][] x = {{1,2},{3,4}};
		
		// still works
		int[][] b = {{1},{2,3}};
		
		display(x);
		display2(x);
		
	}
	
	public static void display(int[][] a)	{
		for (int y[]: a) {
			for (int z: y) {
				System.out.println(z);
			}	
		}
	}
	
	public static void display2(int[][] x)	{	
		System.out.println();
		for (int row = 0; row < x.length; row++) {
			for (int col = 0; col < x[row].length; col++) {
				System.out.print(x[row][col] + " ");
			}	
			System.out.println();
		}
	}
	
	
}