# ACM-OnlineJudge

小学开始的OI之路，现在因为某些原因没有上ACM，但是还是会做做OJ题目，大概就是纪念下这条OJ之路吧。

有些代码貌似有点问题，可以在issue里放着，我会尽快解决。

## SJTU Online Judge

交大ACM的<a href = "https://acm.sjtu.edu.cn/OnlineJudge/">Online Judge</a>的题目刷一刷。这也是现在主要的练习OJ。根目录下的文件都是交大OJ上刷过的题目代码。

### 可能碰到的问题

- 貌似有些题目数据增强了,原来的可能已经过不了了。

- 本地使用的gcc版本3.4.8，提交的代码好多都是16年17年的，当时OJ服务器的gcc版本是4.8，18年已经更换为7.1版本，因此有些题目可能会RE或WA或CE(真是奇妙，最近好多AC代码交上去都编译错误了≧ ﹏ ≦)。

  针对这些问题可以放issue里,看到了的话有空更新下。当然也欢迎pr~

用户 516030910552 yyong119

## 其他OJ

一些以前刷的暂时都不管了，等哪天心血来潮再补上吧~

- YYHSOJ(since 2010，停止更新) 用户yyhsyy <a href = "192.168.1.211">yyhsoj传送门(需要yyhs校园网)</a>
- Vijos(since 2012，停止更新) 用户1479773600 <a href = "https://www.vijos.org/">Vijos传送门</a>
- CodeVS(since 2013，更新完成) 用户yyong119 <a href = "http://www.codevs.cn/">CodeVS传送门</a>
- USACO(since 2013，更新中) 用户yyhsyy <a href = "http://train.usaco.org/usacogate">USACO传送门</a>
- POJ(since 2013，停止更新) 用户yyhsyy <a href = "http://poj.org/">POJ传送门</a>
- leetcode(since 2017，更新中) 用户yyong119 <a href = "https://leetcode.com/">leetcode传送门</a>
- UVa（since 2017，停止更新) 用户sjtuMao <a href = "https://uva.onlinejudge.org/">UVa传送门</a>
- BZOJ（大视野评测） 高中的各位北大爷们刷的，哪轮的上我这种渣渣呀≧ ﹏ ≦

## 一些东西

#### 位运算(位运算操作效率较高)

- 位运算优先级较低，通常加括号
- 判断是否整除if ((n & 1) == 0)
- <<左移一位，配合|常在线段树树状数组(以及其他常见完全二叉树)中使用，index << 1和index << 1 | 1表示左右子树
- ~y = -y - 1,因此x - y可用x + (~y) + 1

#### 关于加1s操作

- 常见的加1操作有x = x + 1, x += 1, x++, ++x
- 单看效率的话++x效率最高,其次x++, x += 1, x = x + 1(主要由于编译器不认为两边的x是同一地址).