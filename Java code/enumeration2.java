// enum instead of class
// enumerations are constants that are also objects
public enum enumeration2 {
	dog("bark", "5"),
	cat("meow", "15"),
	fish("blurp", "1");
	// these go into constructor

	// final so it doesnt change
	private final String desc;
	private final String year;
	
	enumeration2(String description, String birthday){
		desc = description;
		year = birthday;
	}
	
	public String getDesc(){
		return desc;
	}
	
	public String getYear(){
		return year;
	}
	
}