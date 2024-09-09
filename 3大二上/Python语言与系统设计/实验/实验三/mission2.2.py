import re


def is_valid_password(password):
    if re.search(r'[a-z]', password) and \
            re.search(r'[0-9]', password) and \
            re.search(r'[A-Z]', password) and \
            re.search(r'[$#@]', password) and \
            6 <= len(password) <= 12:
        return True
    else:
        return False


def main():
    # 接受逗号分隔的密码输入
    input_passwords = input("请输入逗号分隔的密码列表: ")
    passwords = input_passwords.split(',')

    # 检查每个密码并输出符合条件的密码
    valid_passwords = [password for password in passwords if is_valid_password(password)]
    print("符合条件的密码: {}".format(','.join(valid_passwords)))


main()
