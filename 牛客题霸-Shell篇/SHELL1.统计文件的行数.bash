# @nc app=nowcoder id=205ccba30b264ae697a78f425f276779 topic=195 question=36211 lang=Bash
# 2025-08-09 20:31:01
# https://www.nowcoder.com/practice/205ccba30b264ae697a78f425f276779?tpId=195&tqId=36211
# [SHELL1] 统计文件的行数

# @nc code=start

#!/bin/bash
wc -l nowcoder.txt | awk '{print $1}'
# @nc code=end
