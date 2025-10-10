#我们自定义的模块
from DB import db_handle


def register_info(user_name,password):
    user_info ={
        'user_name':user_name,
        'password':password,
        'content':{}
    }
    #这是用来储存用户信息的字典
    user_data = db_handle.get_data(user_name,db_handle.main_file)
    #用DB模块的get_data方法获取用户信息
    if user_data:
        return False,'注册失败，用户名已存在'
    db_handle.save_data(user_info,db_handle.main_file)
    #另添三行代码判断用户是否已注册
    return True,f'{user_name}注册成功'



def login_info(user_name,password):
    user_data =db_handle.get_data(user_name,db_handle.main_file)
    if not user_data:
        user_data = db_handle.get_data(user_name,db_handle.backup_file)
    #获取备份文件的用户信息
    if user_data :
        #判断用户是否存在
        if password == user_data['password'] :
            #判断密码是否正确
            return True,f'{user_name}登录成功'
        else:
            return False,'登录失败，密码错误，请重新输入'
    else:
        return False,'登录失败，用户名不存在，请重新输入'