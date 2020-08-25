

public class arrayInt {
    public static void main(String[] args) {
        int[] array = {5, 3, 7, 2, 9, 4};
        int menor = array[0], maior = array[0];
        for (int x: array) {
            if (x < menor) menor = x;
            if (x > maior) maior = x;
        }
        System.out.printf("Maior: %d Menor: %d", maior, menor);
    }
}