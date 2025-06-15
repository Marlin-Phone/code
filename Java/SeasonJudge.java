import java.util.Scanner;

public class SeasonJudge {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入月份(1-12):");
        int month = scanner.nextInt();
        scanner.close();

        String season;

        switch (month) {
            case 3:
            case 4:
            case 5:
                season = "春天";
                break;
            case 6:
            case 7:
            case 8:
                season = "夏天";
                break;
            case 9:
            case 10:
            case 11:
                season = "秋天";
                break;
            case 12:
            case 1:
            case 2:
                season = "冬天";
                break;
            default:
                season = "错误的月份";
                break;
        }
        System.out.println(month + "月份是:" + season);
    }
}