public class Test {
    public static int sumNumbers(int[] numbers) {
        int sum = 0;
        for (int i = 0; i < numbers.length; i++) {
            sum += numbers[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        int numbers[] = { 1, 2, 3, 4, 5 };
        System.out.println("Sum of the numbers is: " + sumNumbers(numbers));

    }
}
