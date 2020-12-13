import rpyc

#the line belos imports sys library
#import sys 

#the line below prints the paths python searches for module
#print(sys.path)

#on my computer i've moved the rpcmodule.py file into one of the directories provided by the print() above

#comment the lines below and uncomment the lines 7 and 4
connection = rpyc.classic.connect("localhost")
connection.execute('import rpcmodule as rpc')

print(connection.eval('rpc.add(2, 3)'))
print(connection.eval('rpc.sub(5, 10)'))
print(connection.eval('rpc.mul(10, 10)'))
print(connection.eval('rpc.div(12, 4)'))
print(connection.eval('rpc.div(2, 0)'))