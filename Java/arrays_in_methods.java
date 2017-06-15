class Untitled {
	
	public static void main(String[] args) {
		int[] myArray = {3, 2, 1, 5};
		change(myArray);
		
		for(int y: myArray){
			System.out.println(y);
		}
	}
	
	public static void change(int[] x) {	
		for (int i=0;i<x.length;i++){
			x[i] += 5;
		}	
	}
	
}