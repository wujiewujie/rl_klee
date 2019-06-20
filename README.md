KLEE Symbolic Virtual Machine
=============================

[![Build Status](https://travis-ci.org/klee/klee.svg?branch=master)](https://travis-ci.org/klee/klee)
[![Coverage](https://codecov.io/gh/klee/klee/branch/master/graph/badge.svg)](https://codecov.io/gh/klee/klee)

如何运行：
1.将这个版本的klee源码clone下来之后编译

2.https://github.com/wujiewujie/klee_py/tree/master/klee_py
的python代码中对应的34-37行(MyThread2的run函数)，修改路径为第一步编译后的klee位置，后面搜索的参数是-search=jie,最后是.bc文件的绝对路径。这样就可以直接运行了
