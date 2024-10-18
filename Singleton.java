class Singleton{
//	by default null
	private static Singleton ref;
	
	private Singleton() {
		System.err.println("Constructor called...!");
	}
	
	public static Singleton createRef() {
		if(ref==null)	return ref=new Singleton();
		return ref;
	}
}

public class SingletonClass {
	
	public static void main(String[] args) {
		Singleton s1=Singleton.createRef();
		Singleton s2=Singleton.createRef();
		Singleton s3=Singleton.createRef();
	}

}
