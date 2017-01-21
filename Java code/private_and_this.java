class Untitled {
	public static void main(String[] args) {
		
		// from previous tutorial
		private_and_this2 timeObj = new private_and_this2();
		System.out.println(timeObj.toMilitary());
		
		timeObj.setTime(13, 27, 6);
		System.out.println(timeObj.toMilitary());

		
		System.out.println(timeObj.toString());
		
		
		// new stuff
		// private vs public
		timeObj.sec = 5;   // works, sec is public
	 // timeObj.min = 5;   // doesn't work, min in private

		// if local and method variables of private_and_this2 are the same,
		// java will use the local ones (this is why it prints all 7's [without the 'this')
		
		
	}
}