#include <bits/stdc++.h>
using namespace std;
/**
 * @nc app=nowcoder id=55fb3c68d08d46119f76ae2df7566880 topic=295 question=1024725 lang=C++
 * 2025-09-18 09:17:47
 * https://www.nowcoder.com/practice/55fb3c68d08d46119f76ae2df7566880?tpId=295&tqId=1024725
 * [BM85] 验证IP地址
 */

/** @nc code=start */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    bool check1(string str){
        if(str == ""){
            return false;
        }
        if(str[0] == '0' && str.size() > 1){
            return false;
        }
        for(int i = 0; i < str.size(); i++){
            if('0' <= str[i] && str[i] <= '9'){
                continue;
            }else{
                return false;
            }
        }
        int num = stoi(str);
        if(0 <= num && num <= 255){
            return true;
        }else{
            return false;
        }
    }
    bool check2(string str){
        if(str == ""){
            return false;
        }
        if(str.size() > 4){
            return false;
        }
        if (str.size() == 1 && str[0] == '0') {
            return true;
        }
        // if(str.size() == 4 && str[0] == '0' && str[1] == '0' && str[2] == '0' && str[3] == '0'){
        //     return true;
        // }
        for(int i = 0; i < str.size(); i++){
            char ch = str[i];
            if(('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'F') || ('a' <= ch && ch <= 'f')){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    string solve(string IP) {
        istringstream iss(IP);
        if(count(IP.begin(), IP.end(), ':') == 7){
            vector<string> str(8);
            for(int i = 0; i < 8; i++){
                getline(iss, str[i], ':');
            }
            for(int i = 0; i < 8; i++){
                if(check2(str[i])){
                    continue;
                }else{
                    return "Neither";
                }
            }
            return "IPv6";
        }else if(count(IP.begin(), IP.end(), '.') == 3){
            vector<string> str(4);
            for(int i = 0; i < 4; i++){
                getline(iss, str[i], '.');
            }
            for(int i = 0; i < 4; i++){
                if(check1(str[i])){
                    continue;
                }else{
                    return "Neither";
                }
            }
            return "IPv4";
        }else{
            return "Neither";
        }
    }
};

/** @nc code=end */
