// If you don't have msvcore2 library.

#define MString VString

// Virtual String. Data & size.
// No danger null as end data!

class VString{
public:
	unsigned char *data;
	unsigned int sz;

	VString(){
		data = 0;
		sz = 0;
	}

	VString(char *c){
		data = (unsigned char*)c;
		sz = strlen(c);
	}

	operator bool(){
		return sz;
	}

	operator char*(){
		return (char*)data;
	}

	operator unsigned char*(){
		return data;
	}

	unsigned char* endu(){
		return data + sz;
	}

};
