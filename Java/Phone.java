// 41、编程题： 定义手机类，手机有品牌(brand),
// 价格(price)和颜色(color)三个属性，有打电话call()和sendMessage()两个功能。
// 注意：类中要有空参、有参构造方法，set/get方法；定义测试类，
// 在主方法中使用空参构造创建对象，使用set方法赋值，并调用call()方法和sendMessage(),打印出方法的输出结果。

public class Phone {
    private String brand;
    private int price;
    private String color;

    public Phone() {

    }

    public Phone(String brand, int price, String color) {
        this.brand = brand;
        this.price = price;
        this.color = color;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void call() {
        System.out.println("正在打电话");
    }

    public void sendMessage() {
        System.out.println("正在发送消息");
    }
}
