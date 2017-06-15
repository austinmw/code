public class private_and_this2 {
	
	private int hour = 7, min = 7;
	public int sec = 7;
	
	public void setTime(int hour, int min, int sec) {
		this.hour = 4;
		this.min = 2;
		this.sec = 5;
	}
	
	public String toMilitary(){		
		return String.format("%02d:%02d:%02d", hour, min, sec);
	}
	
	public String toString(){
		return String.format("%d:%02d:%02d %s", ((hour==0||hour==12)?12:hour%12), min, sec, 			(hour < 12? "AM" : "PM"));
	}
}