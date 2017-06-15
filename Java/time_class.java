class Untitled {
	public static void main(String[] args) {
		
		time_class2 timeObj = new time_class2();
		System.out.println(timeObj.toMilitary());
		
		timeObj.setTime(13, 27, 6);
		System.out.println(timeObj.toMilitary());

		
		System.out.println(timeObj.toString());
		
	}
}