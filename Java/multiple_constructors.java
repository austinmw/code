class Untitled {
	public static void main(String[] args) {
		
		multiple_constructors2 Obj1 = new multiple_constructors2();
		multiple_constructors2 Obj2 = new multiple_constructors2(5);
		multiple_constructors2 Obj3 = new multiple_constructors2(5, 10);
		multiple_constructors2 Obj4 = new multiple_constructors2(5, 10, 15);
		
		System.out.println(Obj1.toMilitary());
		System.out.println(Obj2.toMilitary());
		System.out.println(Obj3.toMilitary());
		System.out.println(Obj4.toMilitary());		
		
	}
}