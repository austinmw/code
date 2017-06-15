public class constructors2 {
	
	private String a_name;
	
	public constructors2(String name) {
		a_name = name;
	}
	
	public void setName(String name) {
		a_name = name;
	}
	
	public String getName() {
		return a_name;
	}
	
	public void saying() {
		System.out.printf("Name is %s", getName());
	}
	
	
}