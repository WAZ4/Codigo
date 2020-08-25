import java.util.Scanner;

public class Leitura {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Nome: ");
        String Nome = input.next();
        System.out.print("Idade: ");
        int idade = input.nextInt();
        System.out.println(Nome + " tem " + idade + " anos.");
    }
}