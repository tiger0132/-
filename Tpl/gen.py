from cyaron import * # 引入CYaRon的库

_n = ati([0, 7, 50, 1E4]) # ati函数将数组中的每一个元素转换为整形，方便您可以使用1E4一类的数来表示数据大小
_m = ati([0, 11, 100, 1E4]) 

# 这是一个图论题的数据生成器，该题目在洛谷的题号为P1339
for i in range(1, 4): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="heat", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    graph = Graph.graph(15, 30, repeated_edges=False) # 生成一个n点，m边的随机图，边权限制为5
    test_data.input_writeln(graph) # 自动写入到输入文件里，默认以一行一组u v w的形式输出

