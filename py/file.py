#! /bin/python
#coding=utf-8
import ctypes
MAXN = 10240

so = ctypes.CDLL("../bin/librcfile.so")

class rcFile(object):
	#Contain the file methods

	@staticmethod
	def list_file():
		fun = so.list_file
		string = ctypes.create_string_buffer(MAXN)
		fun(string)
		return string.value

	@staticmethod
	def new_file(name):
		fun = so.new_file
		string = ctypes.create_string_buffer(MAXN)
		string.value = name
		re = fun(string)
		return re

	@staticmethod
	def new_dir(name):
		fun = so.new_dir
		string = ctypes.create_string_buffer(MAXN)
		string.value = name
		re = fun(string)
		return re

	@staticmethod
	def enter_dir(name):
		fun = so.enter_dir
		string = ctypes.create_string_buffer(MAXN)
		string.value = string
		re = fun(string)
		return re

	@staticmethod
	def exit_dir():
		fun = so.exit_dir
		re = fun()
		return re

	@staticmethod
	def del_file(name):
		fun = so.del_file
		string = ctypes.create_string_buffer(MAXN)
		string.value = name
		re = fun(string)
		return re

	@staticmethod
	def del_dir(name):
		fun = so.del_dir
		string = ctypes.create_string_buffer(MAXN)
		string.value = name
		re = fun(string)
		return re

	@staticmethod
	def get_dir():
		tmp = ctypes.create_string_buffer(MAXN)
		fun = so.get_dir
		fun(tmp)
		return tmp.value

	@staticmethod
	def set_dir(string):
		tmp = ctypes.create_string_buffer(MAXN)
		tmp.value = string
		fun = so.set_dir
		fun(tmp)


if __name__ == '__main__':
	rcFile.__init()
	
