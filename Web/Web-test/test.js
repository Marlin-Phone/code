const message = "Hello World";
let count = 0;

function greet(name){
    return `Hello, ${name}!`;
}
// document.write(greet("World"));
console.log(greet("Node.js用户"));
let test =  prompt("请输入您的姓名：", "张三");
if(test == "张三"){
    console.log(`欢迎您！${test}`);
    document.write(`欢迎您！${test}`);

}