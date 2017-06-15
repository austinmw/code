import java.util.EnumSet;

class Untitled {
	public static void main(String[] args) {
		// loop through array of animals and give Obj name, desc name, and year
		for (enumSetRange2 animals: enumSetRange2.values()) 
			System.out.printf("%s\t%s\t%s\n", animals, animals.getDesc(), animals.getYear());
	
		System.out.println("\nAnd now for the range of constants\n");
		
		// prints from lion to bird looping through newly created array
		for(enumSetRange2 animals: EnumSet.range(enumSetRange2.lion, enumSetRange2.bird))
			System.out.printf("%s\t%s\t%s\n", animals, animals.getDesc(), animals.getYear());
	}
}