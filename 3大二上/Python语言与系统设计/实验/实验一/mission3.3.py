def is_palindrome(s):
    # 判断字符串是否等于其反转
    return s == s[::-1]


input_string = input("请输入一个字符串: ")

if is_palindrome(input_string):
    print("是回文字符串")
else:
    print("不是回文字符串")
