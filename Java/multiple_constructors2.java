public class multiple_constructors2 {
	private int hour;
	private int min;
	private int sec;
		
	public multiple_constructors2(){
		this(0,0,0); // calls the 3 parameter constructor 
	}
	
	public multiple_constructors2(int h){
		this(h,0,0); // calls the 3 parameter constructor 
	}
	
	public multiple_constructors2(int h, int m){
		this(h,m,0); // calls the 3 parameter constructor
	}
	
	public multiple_constructors2(int h, int m, int s){
		setTime(h,m,s);
	}
			
	public void setTime(int h, int m, int s){
		setHour(h);
		setMinute(m);
		setSecond(s);		
	}
	
	public void setHour(int h){
		hour = ((h>=0&&h<24)?h:0);
	}
	
	public void setMinute(int m){
		min = ((m>=0&&m<60)?m:0);
	}

	public void setSecond(int s){
		sec = ((s>=0&&s<60)?s:0);
	}

	public int getHour(){
		return hour;
	}

	public int getMinute(){
		return min;
	}
	
	public int getSecond(){
		return sec;
	}

	public String toMilitary(){
		return String.format("%02d:%02d:%02d", getHour(), getMinute(), getSecond());
	}
}

// because hour, min, sec are private, can never set them out of range of the set functions
// need to print them with get functions

