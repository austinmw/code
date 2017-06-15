class Untitled {
	public static void main(String[] args) {
		
		composition3 Obj1 = new composition3(4, 5, 6);
		composition2 Obj2 = new composition2("austin", Obj1);
		
		System.out.println(Obj2);
	}
}

// composition allows you to reference other classes when building a class