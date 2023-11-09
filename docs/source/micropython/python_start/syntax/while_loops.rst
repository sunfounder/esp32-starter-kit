Whileループ
====================

``while`` 文はループ内でプログラムを実行するために使われます。つまり、特定の条件下で繰り返し処理する必要がある同じタスクを処理するために、ループ内でプログラムを実行します。

基本的な形式は以下の通りです：

.. code-block:: python

    while test expression:
        Body of while


``while`` ループでは、まず ``test expression`` をチェックします。 ``test expression`` が ``True`` と評価された場合のみ、whileの本体に入ります。一回のイテレーションの後、再び ``test expression`` をチェックします。このプロセスは ``test expression`` が ``False`` と評価されるまで続きます。

MicroPythonでは、 ``while`` ループの本体はインデントによって決定されます。

本体はインデントで始まり、最初の非インデント行で終わります。

Pythonはゼロでない任意の値を ``True`` と解釈します。Noneと0は ``False`` と解釈されます。

**whileループのフローチャート**

.. image:: img/while_loop.png

.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        x -= 1

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6
5
4
3
2
1


Break文
--------------------

break文を使えば、while条件が真であってもループを停止させることができます：

.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        if x == 6:
            break
        x -= 1

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6

Elseを持つWhileループ
----------------------
`if` ループのように、 `while` ループにもオプショナルの `else` ブロックを持たせることができます。

`while` ループの条件が `False` と評価された場合、 `else` 部分が実行されます。

.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        x -= 1
    else:
        print("Game Over")

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6
5
4
3
2
1
ゲームオーバー
