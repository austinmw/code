#ifndef MOTHER_H
#define MOTHER_H

class Mother{
	public:
		Mother();
		~Mother();
		int publicv;
	
	protected:
	// self, any 'friend', and any inheriting classes have access
		int protectedv;
		
	private:
		int privatev;
	// only this class have access to these variables
	// public methods can access these
		
};

#endif // MOTHER_H