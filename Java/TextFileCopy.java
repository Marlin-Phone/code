import java.io.*;

public class TextFileCopy {
    public static void main(String[] args) {
        // 源文件路径（需替换为实际路径）
        String sourcePath = "source.txt";
        // 目标文件路径（需替换为实际路径）
        String targetPath = "target.txt";

        try (// 创建缓冲字符输入流（自动处理关闭）
                BufferedReader reader = new BufferedReader(new FileReader(sourcePath));
                // 创建缓冲字符输出流（自动处理关闭）
                BufferedWriter writer = new BufferedWriter(new FileWriter(targetPath))) {

            String line; // 存储读取的每行内容
            // 逐行读取源文件，直到文件末尾
            while ((line = reader.readLine()) != null) {
                writer.write(line); // 写入目标文件
                writer.newLine(); // 手动添加换行符，保持文本格式
            }

            System.out.println("文件拷贝成功！");

        } catch (FileNotFoundException e) {
            System.err.println("错误：文件未找到 - " + e.getMessage());
        } catch (IOException e) {
            System.err.println("错误：读写文件失败 - " + e.getMessage());
        }
    }
}