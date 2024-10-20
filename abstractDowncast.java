class Product {
	private int id;
	private String title;
	private double price;
	public Product() {
		this(1, "constructor", 3.141);
	}
	public Product(int id, String title, double price) {
		this.id = id;
		this.title = title;
		this.price = price;
	}
	public double getPrice() {
		return price;
	}
	public static int menuDriven(Scanner s) {
		System.out.println("\n1. Book");
		System.out.println("2. Tape");
		System.out.println("3. Checkout");
		System.out.print("0. Enter choice: ");
		return s.nextInt();
	}
	public void accept(Scanner s) {
		System.out.print("Enter Product Id: ");
		this.id = s.nextInt();
		System.out.print("Enter Product Title: ");
		this.title = s.next();
		System.out.print("Enter Product Price: ");
		this.price = s.nextDouble();
	}
	public void display() {
		System.out.println("Product Id: " + id);
		System.out.println("Product Title: " + title);
		System.out.println("Product Price: " + price);
	}
}

public class Tape extends Product {
	private String artist;
	Tape() {
		this("lio", 1, "constructor", 3.141);
	}
	Tape(String artist, int id, String title, double price) {
		super(id, title, price);
		this.artist = artist;
	}
	@Override
	public void accept(Scanner s) {
		System.out.println("For Tape: ");
		super.accept(s);
		System.out.print("Enter Artist: ");
		this.artist = s.next();
	}
	@Override
	public void display() {
		System.out.println("For Tape: ");
		super.display();
		System.out.println("Artist: " + artist);
	}
	public double calculate() {
		return (this.getPrice() - this.getPrice() * .05);
	}
}

public class Book extends Product {
	private String author;
	public Book() {
		this("Gandhii", 1, "Mahatma", 3.14);
	}
	public Book(String author, int id, String title, double price) {
		super(id, title, price);
		this.author = author;
	}
	@Override
	public void accept(Scanner s) {
		System.out.println("For Book: ");
		super.accept(s);
		System.out.print("Enter Author: ");
		this.author = s.next();
	}
	@Override
	public void display() {
		System.out.print("For Book: ");
		super.display();
		System.out.println("Author: " + author);
	}
	public double calculate() {
		return (this.getPrice() - this.getPrice() * .1);
	}
}

public class Main {
	public static void main(String[] args) {
		int index = 0;
		Scanner s = new Scanner(System.in);
		Product[] p = new Product[3];
		int ch = Product.menuDriven(s);
		do {
			switch (ch) {
			case 1:
				if (index < 3) {
					p[index] = new Book();
					p[index].accept(s);
					index++;
				} else {
					System.err.println("Cart is full please checkout...!");
				}
				break;
			case 2:
				if (index < 3) {
					p[index] = new Tape();
					p[index].accept(s);
					index++;
				} else {
					System.err.println("Cart is full please checkout...!");
				}
				break;
			case 3:
				if (index == 3) {
					double totalBill = .0;
					for (Product obj : p) {
						if (obj instanceof Tape) {
							Tape o = (Tape) obj;
							totalBill = totalBill + o.calculate();
						} else {
							Book o = (Book) obj;
							totalBill = totalBill + o.calculate();
						}
					}
					System.out.println("Total Bill: " + totalBill);
					ch = 0;
				} else {
					System.err.println("You should atleast buy three products...!");
				}
				break;
			default:
				System.err.print("You can buy only Book or Tape...!\n");
				break;
			}
		} while ((ch = Product.menuDriven(s)) != 0);
	}
}
