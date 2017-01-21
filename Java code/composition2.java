public class composition2 {
	
	private String name;
	private composition3 birthday;
	
	public composition2(String theName, composition3 theDate) {
		name = theName;
		birthday = theDate;
	}
	
	public String toString(){
		return String.format("My name is %s, my birthday is %s", name, birthday);
	}
	
	
	
}