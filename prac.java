import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Book {
    private String title;
    private String author;
    private String publisher;
    private String edition;
    private int quantity;
    private int availableQuantity;

    public Book(String title, String author, String publisher, String edition, int quantity) {
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.edition = edition;
        this.quantity = quantity;
        this.availableQuantity = quantity;
    }

    public void borrow() {
        if (availableQuantity > 0) {
            availableQuantity--;
            System.out.println("Book borrowed successfully!");
        } else {
            System.out.println("Sorry, the book is currently unavailable.");
        }
    }

    public void returnBook() {
        if (availableQuantity < quantity) {
            availableQuantity++;
            System.out.println("Book returned successfully!");
        } else {
            System.out.println("All copies of the book are already returned.");
        }
    }

    public void getDetails() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Publisher: " + publisher);
        System.out.println("Edition: " + edition);
        System.out.println("Total Quantity: " + quantity);
        System.out.println("Available Quantity: " + availableQuantity);
    }

    public int getAvailableQuantity() {
        return availableQuantity;
    }

    public String getTitle() {
        return title;
    }
}

class Library {
    private List<Book> books;

    public Library() {
        books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
        System.out.println("Book added successfully!");
    }

    public void displayBooks() {
        if (books.isEmpty()) {
            System.out.println("No books available in the library.");
            return;
        }
        for (Book book : books) {
            book.getDetails();
            System.out.println();
        }
    }

    public Book findBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equalsIgnoreCase(title)) {
                return book;
            }
        }
        return null; // Book not found
    }
}

public class prac {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Library library = new Library();

        // Sample books (you can add more)
        library.addBook(new Book("Introduction to Algorithm", "Thomas H.Corman", "Scribner", "4th Edition", 5));
        library.addBook(new Book("Vector Annalysis", "Murray R. Spiegel", "J. B. Lippincott & Co.", "5th Edition", 3));

        while (true) {
            System.out.println("\nLibrary Management System");
            System.out.println("1. Borrow a book");
            System.out.println("2. Return a book");
            System.out.println("3. Add a new book");
            System.out.println("4. Display available books");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    // Borrow a book
                    System.out.print("Enter the title of the book you want to borrow: ");
                    scanner.nextLine(); // Consume newline
                    String borrowTitle = scanner.nextLine();
                    Book borrowBook = library.findBook(borrowTitle);
                    if (borrowBook != null) {
                        borrowBook.borrow();
                    } else {
                        System.out.println("Book not found.");
                    }
                    break;
                case 2:
                    // Return a book
                    System.out.print("Enter the title of the book you want to return: ");
                    scanner.nextLine(); // Consume newline
                    String returnTitle = scanner.nextLine();
                    Book returnBook = library.findBook(returnTitle);
                    if (returnBook != null) {
                        returnBook.returnBook();
                    } else {
                        System.out.println("Book not found.");
                    }
                    break;
                case 3:
                    // Add a new book
                    System.out.print("Enter book title: ");
                    scanner.nextLine(); // Consume newline
                    String title = scanner.nextLine();
                    System.out.print("Enter author name: ");
                    String author = scanner.nextLine();
                    System.out.print("Enter publisher: ");
                    String publisher = scanner.nextLine();
                    System.out.print("Enter edition: ");
                    String edition = scanner.nextLine();
                    System.out.print("Enter quantity: ");
                    int quantity = scanner.nextInt();
                    library.addBook(new Book(title, author, publisher, edition, quantity));
                    break;
                case 4:
                    // Display available books
                    library.displayBooks();
                    break;
                case 5:
                    System.out.println("Thank you for using the Library Management System!");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
