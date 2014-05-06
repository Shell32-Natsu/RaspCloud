#coding=utf-8
#! /bin/python

import ctypes
from file import rcFile
so = ctypes.CDLL("../bin/librcfile.so")
while True:
    print '请输入你的选择:\n1-显示当前目录下文件\t2-创建新文件\t3-创建新文件夹\t4-进入文件夹\t5-返回上一层\t6-删除文件\t7-删除目录\t8-显示当前目录\t9-退出'
    selection = int(raw_input())
    if selection == 1:
        print rcFile.list_file()
        
    elif selection == 2:
        print '请输入文件名:'
        t = raw_input()
        print rcFile.new_file(t)
        
    elif selection == 3:
        print '请输入目录名:'
        t = raw_input()
        print rcFile.new_dir(t)
        
    elif selection == 6:
        print '请输入要删除的文件名:'
        t = raw_input()
        print rcFile.del_file(t)
        
    elif selection == 7:
        print '请输入要删除的目录名:'
        t = raw_input()
        print rcFile.del_dir(t)
    
    elif selection == 8:
        print rcFile.get_dir()
    
    elif selection == 9:
        break;
    else:
        print '输入错误'

